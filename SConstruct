#!/usr/bin/env python
# 
# Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
# 
# FabricArnold Extension

import os, sys

try:
  fabricEDKPath = os.environ['FABRIC_EDK_DIR']
except:
  print "You must set FABRIC_EDK_DIR in your environment."
  print "Refer to README.txt for more information."
  sys.exit(1)

SConscript(os.path.join(fabricEDKPath, 'SConscript'))
Import('fabricBuildEnv')

# source files
fabricBuildEnv.Extension('FabricArnold',
    ['cpp/FabricArnold.cpp',
    'cpp/matrix.cpp',
    'cpp/vector.cpp',
    'cpp/bbox.cpp',
    'cpp/render.cpp',
    'cpp/nodes.cpp',
    'cpp/node_entry.cpp',
    'cpp/params.cpp',
    'cpp/enum.cpp',
    'cpp/array.cpp',
    'cpp/color.cpp',
    'cpp/universe.cpp',
    'cpp/plugins.cpp',
    'cpp/version.cpp',
    'cpp/dotass.cpp',
    'cpp/msg.cpp' ])

# add arnold include
# arnold root
arnoldRoot = "E:/library/development/solidangle/Arnold-4.0.16.2-windows"
includePath = os.path.join(arnoldRoot, "include")
fabricBuildEnv.Append(CPPPATH = [includePath])
fabricBuildEnv.Append(LIBS = ["ai"], LIBPATH=[os.path.join(arnoldRoot, "lib")])

# function for generating AI_VERSION constants from arnold header file
def generateVersionKLFile(target, source, env):
    # open ai_version.h and find the version defines
    headerFile = open(os.path.join(includePath, "ai_version.h")).read().split("\n")
    arch = major = minor = fix = None
    for line in headerFile:
        if "#define AI_VERSION_ARCH_NUM" in line:
            split = line.split()
            arch = split[2]
        elif "#define AI_VERSION_MAJOR_NUM" in line:
            split = line.split()
            major = split[2]
        elif "#define AI_VERSION_MINOR_NUM" in line:
            split = line.split()
            minor = split[2]
        elif "#define AI_VERSION_FIX" in line:
            split = line.split()
            fix = split[2]
        else:
            pass
    # all of these must exist
    if arch is None or major is None or minor is None or fix is None:
        raise

    # format the string from the template
    templateStr = open(source[0].abspath, "r").read()
    templateStr = templateStr.format(arch, major, minor, fix)
    # write the file to be used in the extension
    open(target[0].abspath, "w").write(templateStr)

templateFile = fabricBuildEnv.File("gen/version.kl.template")
klFile = fabricBuildEnv.File("version.kl")
fabricBuildEnv.Depends(klFile, templateFile)  
fabricBuildEnv.Command(klFile, templateFile, generateVersionKLFile)
