#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_KL_STRUCT( ArnoldRGB, {
  KL::Float32 r;
  KL::Float32 g;
  KL::Float32 b;
});

FABRIC_EXT_KL_STRUCT( ArnoldRGBA, {
  KL::Float32 r;
  KL::Float32 g;
  KL::Float32 b;
  KL::Float32 a;
});