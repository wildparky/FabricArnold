#include "array.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiArray(
   ArnoldArray* array,
   const KL::UInt32 nelements,
   const KL::Byte nkeys,
   const KL::Byte type)
{
   array->array = AiArray(nelements, nkeys, type);
}

FABRIC_EXT_EXPORT void fe_AiArrayAllocate(
   ArnoldArray* array,
   const KL::UInt32 nelements,
   const KL::Byte nkeys,
   const KL::Byte type)
{
   array->array = AiArrayAllocate(nelements, nkeys, type);
}

FABRIC_EXT_EXPORT void fe_AiArrayDestroy(
   ArnoldArray& array)
{
   AiArrayDestroy(array.array);
}

// array getters
FABRIC_EXT_EXPORT KL::Boolean fe_AiArrayGetBool(
   ArnoldArray& array,
   const KL::UInt32 i)
{
   return AiArrayGetBool(array.array, i);
}

FABRIC_EXT_EXPORT KL::Byte fe_AiArrayGetByte(
   ArnoldArray& array,
   const KL::UInt32 i)
{
   return AiArrayGetByte(array.array, i);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiArrayGetInt(
   ArnoldArray& array,
   const KL::UInt32 i)
{
   return AiArrayGetInt(array.array, i);
}

FABRIC_EXT_EXPORT KL::UInt32 fe_AiArrayGetUInt(
   ArnoldArray& array,
   const KL::UInt32 i)
{
   return AiArrayGetUInt(array.array, i);
}

FABRIC_EXT_EXPORT KL::Float32 fe_AiArrayGetFlt(
   ArnoldArray& array,
   const KL::UInt32 i)
{
   return AiArrayGetFlt(array.array, i);
}

// FABRIC_EXT_EXPORT void fe_AiArrayGetRGB(
//    ArnoldRGB* color,
//    ArnoldArray array,
//    const KL::UInt32 i)
// {
//    return AiArrayGetRGB(array.array, i);
// }

// FABRIC_EXT_EXPORT void fe_AiArrayGetRGBA(
//    ArnoldRGBA* color,
//    ArnoldArray array,
//    const KL::UInt32 i)
// {
//    return AiArrayGetRGBA(array.array, i);
// }

// array setters
