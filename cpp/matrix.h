#ifndef MATRIX_H
#define MATRIX_H

#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_KL_STRUCT( ArnoldMatrix, {
   KL::Float32 m[4][4];
});

inline void CopyMatrix(AtMatrix& src, ArnoldMatrix& dst)
{
   dst.m[0][0] = src[0][0];
   dst.m[0][1] = src[0][1];
   dst.m[0][2] = src[0][2];
   dst.m[0][3] = src[0][3];
   dst.m[1][0] = src[1][0];
   dst.m[1][1] = src[1][1];
   dst.m[1][2] = src[1][2];
   dst.m[1][3] = src[1][3];
   dst.m[2][0] = src[2][0];
   dst.m[2][1] = src[2][1];
   dst.m[2][2] = src[2][2];
   dst.m[2][3] = src[2][3];
   dst.m[3][0] = src[3][0];
   dst.m[3][1] = src[3][1];
   dst.m[3][2] = src[3][2];
   dst.m[3][3] = src[3][3];
}

inline void CopyMatrix(ArnoldMatrix& src, AtMatrix& dst)
{
   dst[0][0] = src.m[0][0];
   dst[0][1] = src.m[0][1];
   dst[0][2] = src.m[0][2];
   dst[0][3] = src.m[0][3];
   dst[1][0] = src.m[1][0];
   dst[1][1] = src.m[1][1];
   dst[1][2] = src.m[1][2];
   dst[1][3] = src.m[1][3];
   dst[2][0] = src.m[2][0];
   dst[2][1] = src.m[2][1];
   dst[2][2] = src.m[2][2];
   dst[2][3] = src.m[2][3];
   dst[3][0] = src.m[3][0];
   dst[3][1] = src.m[3][1];
   dst[3][2] = src.m[3][2];
   dst[3][3] = src.m[3][3];
}

#endif
