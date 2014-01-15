# FabricArnold Extension
# testing extension
# TODO: create extensive unit tests

import os

if "FABRIC_EXTS_PATH" in os.environ:
  os.environ["FABRIC_EXTS_PATH"] = os.pathsep.join([".", os.environ["FABRIC_EXTS_PATH"]])
else:
  os.environ["FABRIC_EXTS_PATH"] = "."
  
import FabricEngine.Core as fabric
fabricClient = fabric.createClient({"traceOperators":True});

opSource = """
require FabricArnold;

operator entry(io Boolean active) {
  AiBegin();

  ArnoldNode options = AiUniverseGetOptions();
  AiNodeSetInt(options, "AA_samples", 1);

  ArnoldNode driver = AiNode("driver_tiff");
  AiNodeSetStr(driver, "name", "mydriver");
  AiNodeSetStr(driver, "filename", "scene1.tiff");

  ArnoldNode filter = AiNode("gaussian_filter");
  AiNodeSetStr(filter, "name", "myfilter");

  ArnoldArray outputs_array = AiArrayAllocate(1, 1, AI_TYPE_STRING);
  AiArraySetStr(outputs_array, 0, "RGB RGB myfilter mydriver");
  AiNodeSetArray(options, "outputs", outputs_array);

  ArnoldArray outs = AiNodeGetArray(options, "outputs");
  report(outs.nelements);
  for(Index i=0; i<outs.nelements; i++)
  {
    report(AiArrayGetStr(outs, i));
  }

  report("Testing FabricArnold KL extension!");
  ArnoldNode n = AiNode("sphere");
  AiNodeSetStr(n, "name", "mySphere");
  report("Arnold node name is '" + AiNodeGetName(n) + "'");
  report(n.getName());
  ArnoldNode s = AiNode("standard");
  AiNodeSetStr(s, "name", "standard");
  AiNodeSetRGB(s, "Kd_color", 1.0, 0.0, 0.0);
  AiNodeSetFlt(s, "Kd", 0.5555);
  report("Arnold shader name is '" + AiNodeGetName(s) + "'");
  AtRGB c = AiNodeGetRGB(s, "Kd_color");
  report(c);
  c.g = 0.54545;
  report(c);
  AiNodeSetRGB(s, "Kd_color", c.r, c.g, c.b);
  ArnoldNode pointLight = AiNode("point_light");
  AiNodeSetStr(pointLight, "name", "point_light");
  AiNodeSetPnt(pointLight, "position", 0.0, 10.0, 0.0);

  ArnoldNode quadLight = AiNode("quad_light");
  AiNodeSetStr(quadLight, "name", "quad_light");
  quadLight.setFlt("intensity", 500.0);

  ArnoldMatrix m;
  AiM4Identity(m);
  AiM4RotationX(m, -90);

  ArnoldVector v;
  v.set(0,1,0);

  //report(m);

  quadLight.setMatrix("matrix", m);

  ArnoldPoint p;
  p.setNull();

  AiM4PointByMatrixMult(p, m, v);

  report(p);

  ArnoldNode nodes[] = AiUniverseGetLights();
  report("Arnold light nodes...");
  for (Index i=0; i<nodes.size(); i++)
  {
    report("\\t" + nodes[i].getName() +
            " --> " + nodes[i].getFlt("intensity"));
  }

  AiASSWrite("./test.ass");
  AiEnd();
  active = true;
}
"""
op = fabricClient.DG.createOperator("op")
op.setSourceCode(opSource)
op.setEntryPoint("entry")

if op.getDiagnostics():
   print op.getDiagnostics()

b = fabricClient.DG.createBinding()
b.setOperator(op)
b.setParameterLayout(["self.active"])

node = fabricClient.DG.createNode("node")
node.addMember("active", "Boolean")
node.bindings.append(b)
node.evaluate()

fabricClient.close()
