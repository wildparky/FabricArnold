#!/usr/bin/env python
# test_0001

import sys
import os

testNumber = "test_0001"
print("[FabricArnold::TestSuite] Running extension {0}".format(testNumber))

import FabricEngine.Core as Core
client = Core.createClient()

node = client.DG.createNode("test_node")
node.addMember("filename", "String")
operator = client.DG.createOperator("test_operator")

klFilename = os.path.join(os.getcwd(), testNumber, "test.kl")
operatorSource = open(klFilename).read()

operator.setSourceCode(operatorSource)
operator.setEntryPoint("entry")

if operator.getDiagnostics():
    print("Error(s) compiling operator:")
    for d in operator.getDiagnostics():
        print("  {0}".format(str(d)))
    sys.exit(1)

binding = client.DG.createBinding()
binding.setParameterLayout(["self.filename"])
binding.setOperator(operator)
node.bindings.append(binding)

filename = os.path.join(os.getcwd(), testNumber, "test.tif")
node.setValue("filename", 0, filename)

node.evaluate()

if node.getErrors():
  print("Error(s) executing operator:")
  for e in node.getErrors():
    print("  {0}".format(str(e)))
  sys.exit(1)

client.close()
