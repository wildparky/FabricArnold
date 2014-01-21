#!/usr/bin/env python
# run all tests
# TODO: allow a specific test to be run

import os
import sys
import imgdiff

# append arnold bin to path
arnoldBin = "E:/library/development/solidangle/Arnold-4.0.16.2-windows/bin"
if arnoldBin not in os.environ["PATH"]:
    os.environ["PATH"] = os.pathsep.join([arnoldBin, os.environ["PATH"]])

# append arnold python module to sys.path
arnoldPython = "E:/library/development/solidangle/Arnold-4.0.16.2-windows/python"
if arnoldPython not in sys.path:
    sys.path.append(arnoldPython)

# append to the extensions path
if "FABRIC_EXTS_PATH" in os.environ:
    os.environ["FABRIC_EXTS_PATH"] = os.pathsep.join(["../", os.environ["FABRIC_EXTS_PATH"]])
else:
    os.environ["FABRIC_EXTS_PATH"] = "../"

# for each test_#### directory, run the test
for d in os.listdir(os.getcwd()):
    if os.path.isdir(d):

        # generate reference image
        arnoldPythonTest = os.path.join(os.getcwd(), d, "reference.py")
        if os.path.exists(arnoldPythonTest):
            execfile(arnoldPythonTest)
        else:
            sys.exit(1)

        # generate image made from kl bindings
        klExtTest = os.path.join(os.getcwd(), d, "test.py")
        if os.path.exists(klExtTest):
            execfile(klExtTest)
        else:
            sys.exit(1)

        # run difference test
        if imgdiff.main(d):
            print("[FabricArnold::TestSuite] {0} failed!".format(testNumber))
        else:
            print("[FabricArnold::TestSuite] {0} passed!".format(testNumber))


