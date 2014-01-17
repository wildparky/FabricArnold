#include <Fabric/EDK/EDK.h>

#include <ai.h>

#include "vector.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiM4Identity(
   AtMatrix& mout)
{
   AiM4Identity(mout);
}

FABRIC_EXT_EXPORT void fe_AiM4Translation(
   AtMatrix& mout,
   AtVector* t)
{
   AiM4Translation(mout, t);
}

FABRIC_EXT_EXPORT void fe_AiM4RotationX(
   AtMatrix& mout,
   KL::Float32 x)
{
   AiM4RotationX(mout, x);
}

FABRIC_EXT_EXPORT void fe_AiM4RotationY(
   AtMatrix& mout,
   KL::Float32 y)
{
   AiM4RotationX(mout, y);
}

FABRIC_EXT_EXPORT void fe_AiM4RotationZ(
   AtMatrix& mout,
   KL::Float32 z)
{
   AiM4RotationX(mout, z);
}

FABRIC_EXT_EXPORT void fe_AiM4Scaling(
   AtMatrix& mout,
   AtVector* s)
{
   AiM4Scaling(mout, s);
}

FABRIC_EXT_EXPORT void fe_AiM4Frame(
   AtMatrix& mout,
   AtVector* o,
   AtVector* u,
   AtVector* v,
   AtVector* w)
{
   AiM4Frame(mout, o, u, v, w);
}

FABRIC_EXT_EXPORT void fe_AiM4PointByMatrixMult(
   AtPoint* pout,
   AtMatrix m,
   AtPoint* pin)
{
   AiM4PointByMatrixMult(pout, m, pin);
}

FABRIC_EXT_EXPORT void fe_AiM4HPointByMatrixMult(
   AtHPoint* pout,
   AtMatrix m,
   AtHPoint* pin)
{
   AiM4HPointByMatrixMult(pout, m, pin);
}

FABRIC_EXT_EXPORT void fe_AiM4VectorByMatrixMult(
   AtVector* vout,
   AtMatrix m,
   AtVector* vin)
{
   AiM4VectorByMatrixMult(vout, m, vin);
}

FABRIC_EXT_EXPORT void fe_AiM4VectorByMatrixTMult(
   AtVector* vout,
   AtMatrix m,
   AtVector* vin)
{
   AiM4VectorByMatrixTMult(vout, m, vin);
}

FABRIC_EXT_EXPORT void fe_AiM4Mult(
   AtMatrix& mout,
   AtMatrix ma,
   AtMatrix mb)
{
   AiM4Mult(mout, ma, mb);
}

FABRIC_EXT_EXPORT void fe_AiM4Copy(
   AtMatrix& dest,
   AtMatrix src)
{
   AiM4Copy(dest, src);
}

FABRIC_EXT_EXPORT void fe_AiM4Transpose(
   AtMatrix min,
   AtMatrix& mout)
{
   AiM4Transpose(min, mout);
}

FABRIC_EXT_EXPORT void fe_AiM4Invert(
   AtMatrix min,
   AtMatrix& mout)
{
   AiM4Invert(min, mout);
}

FABRIC_EXT_EXPORT KL::Float64 fe_AiM4Determinant(
   AtMatrix m)
{
   return AiM4Determinant(m);
}

FABRIC_EXT_EXPORT void fe_AiM4Lerp(
   AtMatrix& mout,
   KL::Float32 t,
   AtMatrix ma,
   AtMatrix mb)
{
   AiM4Lerp(mout, t, ma, mb);
}

FABRIC_EXT_EXPORT void fe_AiM4Berp(
   KL::Float32 bu,
   KL::Float32 bv,
   AtMatrix m0,
   AtMatrix m1,
   AtMatrix m2,
   AtMatrix& mout)
{
   AiM4Berp(bu, bv, m0, m1, m2, mout);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiM4IsIdentity(
   AtMatrix m)
{
   return AiM4IsIdentity(m); 
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiM4IsSingular(
   AtMatrix m)
{
   return AiM4IsSingular(m); 
}