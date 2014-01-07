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
  report("Testing FabricArnold KL extension!");
  ArnoldNode n = AiNode("sphere");
  AiNodeSetStr(n, "name", "mySphere");
  report("Arnold node name is '" + AiNodeGetName(n) + "'");
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
