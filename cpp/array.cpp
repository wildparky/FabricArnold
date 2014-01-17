#include "array.h"
#include "color.h"
#include "vector.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiArray(
   ArnoldArray& array,
   const KL::UInt32 nelements,
   const KL::Byte nkeys,
   const KL::Byte type)
{
   array.array = AiArray(nelements, nkeys, type);
   array.nelements = nelements;
   array.nkeys = nkeys;
   array.type = type;
}

FABRIC_EXT_EXPORT void fe_AiArrayAllocate(
   ArnoldArray& array,
   const KL::UInt32 nelements,
   const KL::Byte nkeys,
   const KL::Byte type)
{
   array.array = AiArrayAllocate(nelements, nkeys, type);
   array.nelements = nelements;
   array.nkeys = nkeys;
   array.type = type;
}

FABRIC_EXT_EXPORT void fe_AiArrayDestroy(
   ArnoldArray& array)
{
   AiArrayDestroy(array.array);
}

// array getters
FABRIC_EXT_EXPORT KL::Boolean fe_AiArrayGetBool(
   ArnoldArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetBool(a.array, i);
}

FABRIC_EXT_EXPORT KL::Byte fe_AiArrayGetByte(
   ArnoldArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetByte(a.array, i);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiArrayGetInt(
   ArnoldArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetInt(a.array, i);
}

FABRIC_EXT_EXPORT KL::UInt32 fe_AiArrayGetUInt(
   ArnoldArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetUInt(a.array, i);
}

FABRIC_EXT_EXPORT KL::Float32 fe_AiArrayGetFlt(
   ArnoldArray& a,
   const KL::UInt32 i)
{
   return AiArrayGetFlt(a.array, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetRGB(
   AtRGB& color,
   ArnoldArray a,
   const KL::UInt32 i)
{
   color = AiArrayGetRGB(a.array, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetRGBA(
   AtRGBA& color,
   ArnoldArray a,
   const KL::UInt32 i)
{
   color = AiArrayGetRGBA(a.array, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetPnt(
   AtPoint& point,
   ArnoldArray a,
   const KL::UInt32 i)
{
   point = AiArrayGetPnt(a.array, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetPnt2(
   AtPoint2& point,
   ArnoldArray a,
   const KL::UInt32 i)
{
   point = AiArrayGetPnt2(a.array, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetVec(
   AtVector& vector,
   ArnoldArray a,
   const KL::UInt32 i)
{
   vector = AiArrayGetVec(a.array, i);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetMtx(
   AtMatrix& matrix,
   ArnoldArray a,
   const KL::UInt32 i)
{
   AiArrayGetMtx(a.array, i, matrix);
}

FABRIC_EXT_EXPORT void fe_AiArrayGetStr(
   KL::String& str,
   ArnoldArray& a,
   const KL::UInt32 i)
{
   str = AiArrayGetStr(a.array, i);
}

FABRIC_EXT_EXPORT KL::Data fe_AiArrayGetPtr(
   ArnoldArray& a,
   const KL::UInt32 i)
{
   KL::Data ptr = NULL;
   ptr = AiArrayGetPtr(a.array, i);
   return ptr;
}

FABRIC_EXT_EXPORT void fe_AiArrayGetArray(
   ArnoldArray& aout,
   ArnoldArray a,
   KL::UInt32 i)
{
   aout.array = AiArrayGetArray(a.array, i);
}

// array setters
FABRIC_EXT_EXPORT void fe_AiArraySetBool(
   ArnoldArray& a,
   KL::UInt32 i,
   KL::Boolean val)
{
   AiArraySetBool(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetByte(
   ArnoldArray& a,
   KL::UInt32 i,
   KL::Byte val)
{
   AiArraySetByte(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetInt(
   ArnoldArray& a,
   KL::UInt32 i,
   KL::Integer val)
{
   AiArraySetInt(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetUInt(
   ArnoldArray& a,
   KL::UInt32 i,
   KL::UInt32 val)
{
   AiArraySetUInt(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetFlt(
   ArnoldArray& a,
   KL::UInt32 i,
   KL::Float32 val)
{
   AiArraySetFlt(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetRGB(
   ArnoldArray& a,
   KL::UInt32 i,
   AtRGB val)
{
   AiArraySetRGB(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetRGBA(
   ArnoldArray& a,
   KL::UInt32 i,
   AtRGBA val)
{
   AiArraySetRGBA(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetPnt(
   ArnoldArray& a,
   KL::UInt32 i,
   AtPoint val)
{
   AiArraySetPnt(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetPnt2(
   ArnoldArray& a,
   KL::UInt32 i,
   AtPoint2 val)
{
   AiArraySetPnt2(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetVec(
   ArnoldArray& a,
   KL::UInt32 i,
   AtVector val)
{
   AiArraySetVec(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetMtx(
   ArnoldArray& a,
   KL::UInt32 i,
   AtMatrix val)
{
   AiArraySetMtx(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetStr(
   ArnoldArray& a,
   KL::UInt32 i,
   const KL::String val)
{
   AiArraySetStr(a.array, i, val.data());
}

FABRIC_EXT_EXPORT void fe_AiArraySetPtr(
   ArnoldArray& a,
   KL::UInt32 i,
   KL::Data val)
{
   AiArraySetPtr(a.array, i, val);
}

FABRIC_EXT_EXPORT void fe_AiArraySetArray(
   ArnoldArray& a,
   KL::UInt32 i,
   ArnoldArray val)
{
   AiArraySetArray(a.array, i, val.array);
}