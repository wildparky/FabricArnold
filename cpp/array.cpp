//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include "array.h"
#include "color.h"
#include "vector.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiArray(
   AtArray& array,
   const KL::UInt32 nelements,
   const KL::Byte nkeys,
   const KL::Byte type)
{
   AtArray* a = AiArray(nelements, nkeys, type);
   array = *a;
   //array.nelements = nelements;
   //array.nkeys = nkeys;
   //array.type = type;
}

FABRIC_EXT_EXPORT void fe_AiArrayAllocate(
   AtArray& array,
   const KL::UInt32 nelements,
   const KL::Byte nkeys,
   const KL::Byte type)
{
   AtArray* a = AiArrayAllocate(nelements, nkeys, type);
   array = *a;
   // array.nelements = nelements;
   // array.nkeys = nkeys;
   // array.type = type;
}

FABRIC_EXT_EXPORT void fe_AiArrayDestroy(
   AtArray& array)
{
   AiArrayDestroy(&array);
}

FABRIC_EXT_EXPORT void fe_AiArrayConvert(
   AtArray& array,
   const KL::UInt32 nelements,
   const KL::Byte nkeys,
   const KL::Byte type,
   KL::Data data)
{
   AtArray* a = AiArrayConvert(nelements, nkeys, type, data);
   array = *a;
}

FABRIC_EXT_EXPORT void fe_AiArrayModify(
   AtArray& outarray,
   AtArray& inarray,
   const KL::UInt32 nelements,
   const KL::Byte nkeys,
   const KL::Byte type)
{
   AtArray* a = AiArrayModify(&inarray, nelements, nkeys, type);
   outarray = *a;
}

FABRIC_EXT_EXPORT void fe_AiArrayCopy(
   AtArray& outarray,
   AtArray& inarray)
{
   AtArray* a = AiArrayCopy(&inarray);
   outarray = *a;
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiArraySetKey(
   AtArray& array,
   const KL::Byte key,
   KL::Data data)
{
   return AiArraySetKey(&array, key, data);
}

FABRIC_EXT_EXPORT void fe_AiArrayInterpolatePnt(
   AtPoint& point,
   AtArray& array,
   KL::Float32 time,
   KL::UInt32 idx)
{
   point = AiArrayInterpolatePnt(&array, time, idx);
}

FABRIC_EXT_EXPORT void fe_AiArrayInterpolateVec(
   AtVector& vector,
   AtArray& array,
   KL::Float32 time,
   KL::UInt32 idx)
{
   vector = AiArrayInterpolateVec(&array, time, idx);
}

FABRIC_EXT_EXPORT void fe_AiArrayInterpolateRGB(
   AtColor& color,
   AtArray& array,
   KL::Float32 time,
   KL::UInt32 idx)
{
   color = AiArrayInterpolateRGB(&array, time, idx);
}

FABRIC_EXT_EXPORT void fe_AiArrayInterpolateRGBA(
   AtRGBA& color,
   AtArray& array,
   KL::Float32 time,
   KL::UInt32 idx)
{
   color = AiArrayInterpolateRGBA(&array, time, idx);
}

FABRIC_EXT_EXPORT KL::Float32 fe_AiArrayInterpolateFlt(
   AtArray& array,
   KL::Float32 time,
   KL::UInt32 idx)
{
   return AiArrayInterpolateFlt(&array, time, idx);
}

FABRIC_EXT_EXPORT void fe_AiArrayInterpolateMtx(
   AtArray& array,
   KL::Float32 time,
   KL::UInt32 idx,
   AtMatrix& result)
{
   AiArrayInterpolateMtx(&array, time, idx, result);
}

// array getters
FABRIC_EXT_EXPORT KL::Boolean fe_AiArrayGetBool(
   AtArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetBool(&a, i);
}

FABRIC_EXT_EXPORT KL::Byte fe_AiArrayGetByte(
   AtArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetByte(&a, i);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiArrayGetInt(
   AtArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetInt(&a, i);
}

FABRIC_EXT_EXPORT KL::UInt32 fe_AiArrayGetUInt(
   AtArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetUInt(&a, i);
}

FABRIC_EXT_EXPORT KL::Float32 fe_AiArrayGetFlt(
   AtArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetFlt(&a, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetRGB(
   AtRGB& color,
   AtArray& a,
   const KL::UInt32 i)
{
   color = AiArrayGetRGB(&a, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetRGBA(
   AtRGBA& color,
   AtArray& a,
   const KL::UInt32 i)
{
   color = AiArrayGetRGBA(&a, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetPnt(
   AtPoint& point,
   AtArray& a,
   const KL::UInt32 i)
{
   point = AiArrayGetPnt(&a, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetPnt2(
   AtPoint2& point,
   AtArray& a,
   const KL::UInt32 i)
{
   point = AiArrayGetPnt2(&a, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetVec(
   AtVector& vector,
   AtArray& a,
   const KL::UInt32 i)
{
   vector = AiArrayGetVec(&a, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetMtx(
   AtMatrix& matrix,
   AtArray& a,
   const KL::UInt32 i)
{
   AiArrayGetMtx(&a, i, matrix);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetStr(
   KL::String& str,
   AtArray& a,
   const KL::UInt32 i)
{
   str = AiArrayGetStr(&a, i);
}

FABRIC_EXT_EXPORT KL::Data fe_AiArrayGetPtr(
   AtArray& a,
   const KL::UInt32 i)
{
   KL::Data ptr = NULL;
   ptr = AiArrayGetPtr(&a, i);
   return ptr;
}

FABRIC_EXT_EXPORT void fe_AiArrayGetArray(
   AtArray& aout,
   AtArray& a,
   KL::UInt32 i)
{
   AtArray* array = AiArrayGetArray(&a, i);
   aout = *array;
}

// array setters
FABRIC_EXT_EXPORT void fe_AiArraySetBool(
   AtArray& a,
   KL::UInt32 i,
   KL::Boolean val)
{
   AiArraySetBool(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetByte(
   AtArray& a,
   KL::UInt32 i,
   KL::Byte val)
{
   AiArraySetByte(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetInt(
   AtArray& a,
   KL::UInt32 i,
   KL::Integer val)
{
   AiArraySetInt(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetUInt(
   AtArray& a,
   KL::UInt32 i,
   KL::UInt32 val)
{
   AiArraySetUInt(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetFlt(
   AtArray& a,
   KL::UInt32 i,
   KL::Float32 val)
{
   AiArraySetFlt(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetRGB(
   AtArray& a,
   KL::UInt32 i,
   AtRGB val)
{
   AiArraySetRGB(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetRGBA(
   AtArray& a,
   KL::UInt32 i,
   AtRGBA val)
{
   AiArraySetRGBA(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetPnt(
   AtArray& a,
   KL::UInt32 i,
   AtPoint val)
{
   AiArraySetPnt(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetPnt2(
   AtArray& a,
   KL::UInt32 i,
   AtPoint2 val)
{
   AiArraySetPnt2(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetVec(
   AtArray& a,
   KL::UInt32 i,
   AtVector val)
{
   AiArraySetVec(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetMtx(
   AtArray& a,
   KL::UInt32 i,
   AtMatrix val)
{
   AiArraySetMtx(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetStr(
   AtArray& a,
   KL::UInt32 i,
   const KL::String val)
{
   AiArraySetStr(&a, i, val.data());
}

FABRIC_EXT_EXPORT void fe_AiArraySetPtr(
   AtArray& a,
   KL::UInt32 i,
   KL::Data val)
{
   AiArraySetPtr(&a, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetArray(
   AtArray& a,
   KL::UInt32 i,
   AtArray& val)
{
   AiArraySetArray(&a, i, &val);
}