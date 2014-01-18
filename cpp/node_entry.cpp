#include "node_entry.h"
#include "params.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiNodeEntryLookUp(
   ArnoldNodeEntry& nentry,
   KL::String::INParam name)
{
   nentry.entry = AiNodeEntryLookUp(name.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeEntryGetName(
   KL::String& name,
   ArnoldNodeEntry& nentry)
{
   name = "";
   name = AiNodeEntryGetName(nentry.entry);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiNodeEntryGetType(
   ArnoldNodeEntry& nentry)
{
   return AiNodeEntryGetType(nentry.entry);
}

FABRIC_EXT_EXPORT void fe_AiNodeEntryGetTypeName(
   KL::String& tname,
   ArnoldNodeEntry& nentry)
{
   tname = "";
   tname = AiNodeEntryGetTypeName(nentry.entry);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiNodeEntryGetOutputType(
   ArnoldNodeEntry& nentry)
{
   return AiNodeEntryGetOutputType(nentry.entry);
}

FABRIC_EXT_EXPORT void fe_AiNodeEntryGetFilename(
   KL::String& filename,
   ArnoldNodeEntry& nentry)
{
   filename = "";
   filename = AiNodeEntryGetFilename(nentry.entry);
}

FABRIC_EXT_EXPORT void fe_AiNodeEntryGetVersion(
   KL::String& version,
   ArnoldNodeEntry& nentry)
{
   version = "";
   version = AiNodeEntryGetVersion(nentry.entry);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiNodeEntryGetCount(
   ArnoldNodeEntry& nentry)
{
   return AiNodeEntryGetCount(nentry.entry);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiNodeEntryGetNumParams(
   ArnoldNodeEntry& nentry)
{
   return AiNodeEntryGetNumParams(nentry.entry);
}

FABRIC_EXT_EXPORT void fe_AiNodeEntryGetParameter(
   ArnoldParamEntry& pentry,
   ArnoldNodeEntry& nentry,
   KL::Integer i)
{
   pentry.entry = AiNodeEntryGetParameter(nentry.entry, i);
}

FABRIC_EXT_EXPORT void fe_AiNodeEntryLookUpParameter(
   ArnoldParamEntry& pentry,
   ArnoldNodeEntry& nentry,
   const KL::String param)
{
   pentry.entry = AiNodeEntryLookUpParameter(nentry.entry, param.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeEntryInstall(
   KL::Integer type,
   KL::Byte output_type,
   const KL::String& name,
   const KL::String& filename,
   ArnoldNodeMethods& methods,
   const KL::String& version)
{
   AiNodeEntryInstall(
      type,
      output_type,
      name.data(),
      filename.data(),
      methods.methods,
      version.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeEntryUninstall(
   const KL::String& name)
{
   AiNodeEntryUninstall(name.data());
}
