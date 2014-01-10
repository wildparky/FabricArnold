#include "matrix.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiM4Identity(
   ArnoldMatrix& mout)
{
   AtMatrix m;
   AiM4Identity(m);
   CopyMatrix(m, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4RotationX(
   ArnoldMatrix& mout,
   KL::Float32 x)
{
   AtMatrix m;
   AiM4RotationX(m, x);
   CopyMatrix(m, mout);
}