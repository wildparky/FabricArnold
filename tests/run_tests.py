#!/usr/bin/env python
# run all tests
# TODO: allow a specific test to be run

import os
import sys
import argparse
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

parser = argparse.ArgumentParser()
parser.add_argument("-t", "-test", "--test", type=int, nargs="+", help="which test(s) to run")
args = parser.parse_args()

failedTests = list()
if args.test:
    # run a specific set of tests
    for arg in args.test:
        testNumber = "test_{0}".format(str(arg).zfill(4))
        # generate reference image
        arnoldPythonTest = os.path.join(os.getcwd(), testNumber, "reference.py")
        if os.path.exists(arnoldPythonTest):
            try:
                execfile(arnoldPythonTest)
            except Exception, e:
                print(e)
        else:
            print("[FabricArnold::TestSuite] {0} doesn't exist!".format(testNumber))
            failedTests.append(testNumber)
            continue

        # generate image made from kl bindings
        klExtTest = os.path.join(os.getcwd(), testNumber, "test.py")
        if os.path.exists(klExtTest):
            try:
                execfile(klExtTest)
            except Exception, e:
                print(e)
        else:
            print("[FabricArnold::TestSuite] {0} doesn't exist!".format(testNumber))
            failedTests.append(testNumber)
            continue

        # run difference test
        if imgdiff.main(testNumber):
            print("[FabricArnold::TestSuite] {0} failed!".format(testNumber))
            failedTests.append(testNumber)
        else:
            print("[FabricArnold::TestSuite] {0} passed!".format(testNumber))
else:
    # run all the tests
    for testNumber in os.listdir(os.getcwd()):
        if os.path.isdir(testNumber):
            # generate reference image
            arnoldPythonTest = os.path.join(os.getcwd(), testNumber, "reference.py")
            if os.path.exists(arnoldPythonTest):
                try:
                    execfile(arnoldPythonTest)
                except Exception, e:
                    print(e)
            else:
                print("[FabricArnold::TestSuite] {0} doesn't exist!".format(testNumber))
                failedTests.append(testNumber)
                continue

            # generate image made from kl bindings
            klExtTest = os.path.join(os.getcwd(), testNumber, "test.py")
            if os.path.exists(klExtTest):
                try:
                    execfile(klExtTest)
                except Exception, e:
                    print(e)
            else:
                print("[FabricArnold::TestSuite] {0} doesn't exist!".format(testNumber))
                failedTests.append(testNumber)
                continue

            # run difference test
            if imgdiff.main(testNumber):
                print("[FabricArnold::TestSuite] {0} failed!".format(testNumber))
                failedTests.append(testNumber)
            else:
                print("[FabricArnold::TestSuite] {0} passed!".format(testNumber))

# print a report of failed tests
print(os.linesep)
if len(failedTests) > 0:
    print("[FabricArnold::TestSuite] These tests failed...")
    for fail in failedTests:
        print("{0}".format(fail))
else:
    print("[FabricArnold::TestSuite] All tests passed!")

