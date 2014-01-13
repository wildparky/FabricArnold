#include "matrix.h"
#include "vector.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiM4Identity(
   ArnoldMatrix& mout)
{
   AtMatrix m;
   AiM4Identity(m);
   CopyMatrix(m, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4Translation(
   ArnoldMatrix& mout,
   ArnoldVector* t)
{
   AtMatrix m;
   AiM4Translation(m, (AtVector *)t);
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

FABRIC_EXT_EXPORT void fe_AiM4RotationY(
   ArnoldMatrix& mout,
   KL::Float32 y)
{
   AtMatrix m;
   AiM4RotationX(m, y);
   CopyMatrix(m, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4RotationZ(
   ArnoldMatrix& mout,
   KL::Float32 z)
{
   AtMatrix m;
   AiM4RotationX(m, z);
   CopyMatrix(m, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4Scaling(
   ArnoldMatrix& mout,
   ArnoldVector* s)
{
   AtMatrix m;
   AiM4Scaling(m, (AtVector *)s);
   CopyMatrix(m, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4Frame(
   ArnoldMatrix& mout,
   ArnoldVector* o,
   ArnoldVector* u,
   ArnoldVector* v,
   ArnoldVector* w)
{
   AtMatrix m;
   AiM4Frame(m,
      (AtVector *)o,
      (AtVector *)u,
      (AtVector *)v,
      (AtVector *)w);
   CopyMatrix(m, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4PointByMatrixMult(
   ArnoldPoint& pout,
   ArnoldMatrix m,
   ArnoldPoint* pin)
{
   AtMatrix mat;
   AtPoint* pnt;
   CopyMatrix(m, mat);
   AiM4PointByMatrixMult(pnt, mat, (AtPoint *)pin);
   CopyVector(pnt, pout);
}

FABRIC_EXT_EXPORT void fe_AiM4HPointByMatrixMult(
   ArnoldHPoint& pout,
   ArnoldMatrix m,
   ArnoldHPoint* pin)
{
   AtMatrix mat;
   AtHPoint* pnt;
   CopyMatrix(m, mat);
   AiM4HPointByMatrixMult(pnt, mat, (AtHPoint *)pin);
   CopyHVector(pnt, pout);
}

FABRIC_EXT_EXPORT void fe_AiM4VectorByMatrixMult(
   ArnoldVector& vout,
   ArnoldMatrix m,
   ArnoldVector* vin)
{
   AtMatrix mat;
   AtVector* vec;
   CopyMatrix(m, mat);
   AiM4VectorByMatrixMult(vec, mat, (AtPoint *)vin);
   CopyVector(vec, vout);
}

FABRIC_EXT_EXPORT void fe_AiM4VectorByMatrixTMult(
   ArnoldVector& vout,
   ArnoldMatrix m,
   ArnoldVector* vin)
{
   AtMatrix mat;
   AtVector* vec;
   CopyMatrix(m, mat);
   AiM4VectorByMatrixTMult(vec, mat, (AtPoint *)vin);
   CopyVector(vec, vout);
}

FABRIC_EXT_EXPORT void fe_AiM4Mult(
   ArnoldMatrix& mout,
   ArnoldMatrix ma,
   ArnoldMatrix mb)
{
   AtMatrix mat;
   AtMatrix matA, matB;
   CopyMatrix(ma, matA);
   CopyMatrix(mb, matB);
   AiM4Mult(mat, matA, matB);
   CopyMatrix(mat, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4Copy(
   ArnoldMatrix& dest,
   ArnoldMatrix src)
{
   AtMatrix mdest;
   AtMatrix msrc;
   CopyMatrix(src, msrc);
   AiM4Copy(mdest, msrc);
   CopyMatrix(mdest, dest);
}

FABRIC_EXT_EXPORT void fe_AiM4Transpose(
   ArnoldMatrix min,
   ArnoldMatrix& mout)
{
   AtMatrix matIn;
   AtMatrix matOut;
   CopyMatrix(mout, matOut);
   AiM4Transpose(matIn, matOut);
   CopyMatrix(matOut, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4Invert(
   ArnoldMatrix min,
   ArnoldMatrix& mout)
{
   AtMatrix matIn;
   AtMatrix matOut;
   CopyMatrix(mout, matOut);
   AiM4Invert(matIn, matOut);
   CopyMatrix(matOut, mout);
}

FABRIC_EXT_EXPORT KL::Float64 fe_AiM4Determinant(
   ArnoldMatrix m)
{
   AtMatrix mat;
   CopyMatrix(m, mat);
   return AiM4Determinant(mat);
}

FABRIC_EXT_EXPORT void fe_AiM4Lerp(
   ArnoldMatrix& mout,
   KL::Float32 t,
   ArnoldMatrix ma,
   ArnoldMatrix mb)
{
   AtMatrix matOut;
   AtMatrix matA, matB;
   CopyMatrix(ma, matA);
   CopyMatrix(mb, matB);
   AiM4Lerp(matOut, t, matA, matB);
   CopyMatrix(matOut, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4Berp(
   KL::Float32 bu,
   KL::Float32 bv,
   ArnoldMatrix m0,
   ArnoldMatrix m1,
   ArnoldMatrix m2,
   ArnoldMatrix& mout)
{
   AtMatrix mat0, mat1, mat2;
   AtMatrix matOut;
   CopyMatrix(m0, mat0);
   CopyMatrix(m1, mat1);
   CopyMatrix(m2, mat2);
   AiM4Berp(bu, bv, mat0, mat1, mat2, matOut);
   CopyMatrix(matOut, mout);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiM4IsIdentity(
   ArnoldMatrix m)
{
   AtMatrix temp;
   CopyMatrix(m, temp);
   return AiM4IsIdentity(temp); 
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiM4IsSingular(
   ArnoldMatrix m)
{
   AtMatrix temp;
   CopyMatrix(m, temp);
   return AiM4IsSingular(temp); 
}