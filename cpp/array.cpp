//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

// #include "array.h"
// #include "color.h"
// #include "vector.h"
#include "./FabricArnold.h"
#include <ai.h>

using namespace Fabric::EDK;

// this function should take more arguments,
// AiArray(4, 1, AI_TYPE_FLOAT, 10.f, 11.f, 12.f, 13.f);
FABRIC_EXT_EXPORT void fe_AiArray(
   KL::Traits< KL::AtArray >::Result result,
   KL::Traits< KL::UInt32 >::INParam nelements,
   KL::Traits< KL::UInt8 >::INParam nkeys,
   KL::Traits< KL::UInt8 >::INParam type)
{
   AtArray& array = reinterpret_cast<AtArray &>(result);
   AtArray* a = AiArray(nelements, nkeys, type);
   array = *a;
}

FABRIC_EXT_EXPORT void fe_AiArrayAllocate(
   KL::Traits< KL::AtArray >::Result result,
   KL::Traits< KL::UInt32 >::INParam nelements,
   KL::Traits< KL::UInt8 >::INParam nkeys,
   KL::Traits< KL::UInt8 >::INParam type)
{
   AtArray& array = reinterpret_cast<AtArray &>(result);
   AtArray* a = AiArrayAllocate(nelements, nkeys, type);
   array = *a;
}

FABRIC_EXT_EXPORT void fe_AiArrayDestroy(
   KL::Traits< KL::AtArray >::IOParam array)
{
   AtArray &a = reinterpret_cast<AtArray &>(array);
   AiArrayDestroy(&a);
}

// FABRIC_EXT_EXPORT void fe_AiArrayConvert(
//    KL::Traits< KL::AtArray >::Result result,
//    KL::Traits< KL::UInt32 >::INParam nelements,
//    KL::Traits< KL::UInt8 >::INParam nkeys,
//    KL::Traits< KL::UInt8 >::INParam type,
//    KL::Traits< KL::Data >::INParam data)
// {
//    AtArray& array = reinterpret_cast<AtArray &>(array);
//    AtArray* a = AiArrayConvert(nelements, nkeys, type, data);
//    array = *a;
// }

// FABRIC_EXT_EXPORT void fe_AiArrayModify(
//    AtArray& outarray,
//    AtArray& inarray,
//    KL::Traits< KL::UInt32 >::INParam nelements,
//    KL::Traits< KL::UInt8 >::INParam nkeys,
//    KL::Traits< KL::UInt8 >::INParam type)
// {
//    AtArray* a = AiArrayModify(&inarray, nelements, nkeys, type);
//    outarray = *a;
// }

// FABRIC_EXT_EXPORT void fe_AiArrayCopy(
//    AtArray& outarray,
//    AtArray& inarray)
// {
//    AtArray* a = AiArrayCopy(&inarray);
//    outarray = *a;
// }

// FABRIC_EXT_EXPORT KL::Boolean fe_AiArraySetKey(
//    KL::AtArray::Result array,
//    KL::Traits< KL::UInt8 >::INParam key,
//    KL::Data data)
// {
//    return AiArraySetKey(&array, key, data);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayInterpolatePnt(
//    AtPoint& point,
//    KL::AtArray::INParam array,
//    KL::Float32 time,
//    KL::UInt32 idx)
// {
//    point = AiArrayInterpolatePnt(&array, time, idx);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayInterpolateVec(
//    AtVector& vector,
//    KL::AtArray::INParam array,
//    KL::Float32 time,
//    KL::UInt32 idx)
// {
//    vector = AiArrayInterpolateVec(&array, time, idx);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayInterpolateRGB(
//    AtColor& color,
//    KL::AtArray::INParam array,
//    KL::Float32 time,
//    KL::UInt32 idx)
// {
//    color = AiArrayInterpolateRGB(&array, time, idx);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayInterpolateRGBA(
//    AtRGBA& color,
//    KL::AtArray::INParam array,
//    KL::Float32 time,
//    KL::UInt32 idx)
// {
//    color = AiArrayInterpolateRGBA(&array, time, idx);
// }

// FABRIC_EXT_EXPORT KL::Float32 fe_AiArrayInterpolateFlt(
//    AtArray& array,
//    KL::Float32 time,
//    KL::UInt32 idx)
// {
//    return AiArrayInterpolateFlt(&array, time, idx);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayInterpolateMtx(
//    AtArray& array,
//    KL::Float32 time,
//    KL::UInt32 idx,
//    AtMatrix& result)
// {
//    AiArrayInterpolateMtx(&array, time, idx, result);
// }

// array getters
// FABRIC_EXT_EXPORT KL::Boolean fe_AiArrayGetBool(
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    return AiArrayGetBool(&a, i);
// }

// FABRIC_EXT_EXPORT KL::Byte fe_AiArrayGetByte(
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    return AiArrayGetByte(&a, i);
// }

// FABRIC_EXT_EXPORT KL::Integer fe_AiArrayGetInt(
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    return AiArrayGetInt(&a, i);
// }

// FABRIC_EXT_EXPORT KL::UInt32 fe_AiArrayGetUInt(
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    return AiArrayGetUInt(&a, i);
// }

// FABRIC_EXT_EXPORT KL::Float32 fe_AiArrayGetFlt(
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    return AiArrayGetFlt(&a, i);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayGetRGB(
//    AtRGB& color,
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    color = AiArrayGetRGB(&a, i);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayGetRGBA(
//    AtRGBA& color,
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    color = AiArrayGetRGBA(&a, i);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayGetPnt(
//    AtPoint& point,
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    point = AiArrayGetPnt(&a, i);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayGetPnt2(
//    AtPoint2& point,
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    point = AiArrayGetPnt2(&a, i);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayGetVec(
//    AtVector& vector,
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    vector = AiArrayGetVec(&a, i);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayGetMtx(
//    AtMatrix& matrix,
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    AiArrayGetMtx(&a, i, matrix);
// }

FABRIC_EXT_EXPORT void fe_AiArrayGetStr(
   KL::Traits< KL::String >::Result result,
   KL::Traits< KL::AtArray >::INParam a,
   KL::Traits< KL::UInt32 >::INParam i)
{
   AtArray const & array = reinterpret_cast<AtArray const &>(a);
   result = AiArrayGetStr(&array, i);
}

// FABRIC_EXT_EXPORT KL::Data fe_AiArrayGetPtr(
//    AtArray& a,
//    KL::Traits< KL::UInt32 >::INParam i)
// {
//    KL::Data ptr = NULL;
//    ptr = AiArrayGetPtr(&a, i);
//    return ptr;
// }

// FABRIC_EXT_EXPORT void fe_AiArrayGetArray(
//    AtArray& aout,
//    AtArray& a,
//    KL::UInt32 i)
// {
//    AtArray* array = AiArrayGetArray(&a, i);
//    aout = *array;
// }

// array setters
FABRIC_EXT_EXPORT KL::Boolean fe_AiArraySetBool(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::Boolean >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   return AiArraySetBool(&array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetByte(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::Byte >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AiArraySetByte(&array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetInt(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::Integer >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AiArraySetInt(&array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetUInt(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::UInt8 >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AiArraySetUInt(&array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetFlt(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::Float32 >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AiArraySetFlt(&array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetRGB(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::AtRGB >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AtRGB const &value = reinterpret_cast<AtRGB const &>(val);
   AiArraySetRGB(&array, i, value);
}

FABRIC_EXT_EXPORT void fe_AiArraySetRGBA(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::Color >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AtRGBA const &value = reinterpret_cast<AtRGBA const &>(val);
   AiArraySetRGBA(&array, i, value);
}

FABRIC_EXT_EXPORT void fe_AiArraySetPnt(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::Vec3 >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AtPoint const &value = reinterpret_cast<AtPoint const &>(val);
   AiArraySetPnt(&array, i, value);
}

FABRIC_EXT_EXPORT void fe_AiArraySetPnt2(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::Vec2 >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AtPoint2 const &value = reinterpret_cast<AtPoint2 const &>(val);
   AiArraySetPnt2(&array, i, value);
}

FABRIC_EXT_EXPORT void fe_AiArraySetVec(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::Vec3 >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AtVector const &value = reinterpret_cast<AtVector const &>(val);
   AiArraySetVec(&array, i, value);
}

FABRIC_EXT_EXPORT void fe_AiArraySetMtx(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::FixedArray< KL::FixedArray< KL::Float32, 4 >, 4 > >::IOParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AtMatrix& value = reinterpret_cast<AtMatrix &>(val);
   AiArraySetMtx(&array, i, value);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiArraySetStr(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::String >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   bool success = AiArraySetStr(&array, i, val.data());
   printf("%d", success);
   if (success)
      return true;
   return false;
}

FABRIC_EXT_EXPORT void fe_AiArraySetPtr(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::Data >::INParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AiArraySetPtr(&array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetArray(
   KL::Traits< KL::AtArray >::IOParam a,
   KL::Traits< KL::UInt32 >::INParam i,
   KL::Traits< KL::AtArray >::IOParam val)
{
   AtArray& array = reinterpret_cast<AtArray &>(a);
   AtArray& value = reinterpret_cast<AtArray &>(val);
   AiArraySetArray(&array, i, &value);
}