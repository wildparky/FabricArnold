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

fabricBuildEnv.Extension('FabricArnold',
    ['FabricArnold.cpp',
    'matrix.cpp',
    'render.cpp',
    'nodes.cpp',
    'array.cpp',
    'color.cpp',
    'universe.cpp',
    'dotass.cpp' ])

# add arnold include
# arnold root
arnoldRoot = "E:/library/development/solidangle/Arnold-4.0.16.2-windows"
fabricBuildEnv.Append(CPPPATH = [os.path.join(arnoldRoot, "include")])
fabricBuildEnv.Append(LIBS = ["ai"], LIBPATH=[os.path.join(arnoldRoot, "lib")])
