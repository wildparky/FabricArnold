#include "params.h"
#include "enum.h"

using namespace Fabric::EDK;

// standard arnold parameters

FABRIC_EXT_EXPORT void fe_AiParamGetName(
   KL::String& name,
   ArnoldParamEntry& pentry)
{
   name = "";
   name = AiParamGetName(pentry.entry);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiParamGetType(
   ArnoldParamEntry& pentry)
{
   return AiParamGetType(pentry.entry);
}

FABRIC_EXT_EXPORT void fe_AiParamGetDefault(
   ArnoldParamValue& pvalue,
   ArnoldParamEntry& pentry)
{
   pvalue.value = AiParamGetDefault(pentry.entry);
}

FABRIC_EXT_EXPORT void fe_AiParamGetEnum(
   ArnoldEnum& enum_type,
   ArnoldParamEntry& pentry)
{
   enum_type.aenum = AiParamGetEnum(pentry.entry);
}

FABRIC_EXT_EXPORT void fe_AiParamGetTypeName(
   KL::String& tname,
   KL::Byte type)
{
   tname = "";
   tname = AiParamGetTypeName(type);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiParamGetTypeSize(
   KL::Byte type)
{
   return AiParamGetTypeSize(type);
}

// user parameters

FABRIC_EXT_EXPORT void fe_AiUserParamGetName(
   KL::String& name,
   ArnoldUserParamEntry& upentry)
{
   name = "";
   name = AiUserParamGetName(upentry.entry);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiUserParamGetType(
   ArnoldUserParamEntry& upentry)
{
   return AiUserParamGetType(upentry.entry);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiUserParamGetArrayType(
   ArnoldUserParamEntry& upentry)
{
   return AiUserParamGetArrayType(upentry.entry);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiUserParamGetCategory(
   ArnoldUserParamEntry& upentry)
{
   return AiUserParamGetCategory(upentry.entry);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiUserParamGetIndex(
   ArnoldUserParamEntry& upentry)
{
   return AiUserParamGetIndex(upentry.entry);
}

