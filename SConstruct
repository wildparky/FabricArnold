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
    'cpp/dotass.cpp' ])

# add arnold include
# arnold root
arnoldRoot = "E:/library/development/solidangle/Arnold-4.0.16.2-windows"
fabricBuildEnv.Append(CPPPATH = [os.path.join(arnoldRoot, "include")])
fabricBuildEnv.Append(LIBS = ["ai"], LIBPATH=[os.path.join(arnoldRoot, "lib")])
