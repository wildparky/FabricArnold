#include "node_entry.h"

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
