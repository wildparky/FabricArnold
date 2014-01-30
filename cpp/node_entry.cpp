//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

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

FABRIC_EXT_EXPORT void fe_AiNodeEntryGetParamIterator(
   ArnoldParamIterator& iter,
   ArnoldNodeEntry& nentry)
{
   iter.it = AiNodeEntryGetParamIterator(nentry.entry);
}

FABRIC_EXT_EXPORT void fe_AiNodeEntryGetMetaDataIterator(
   ArnoldMetaDataIterator& iter,
   ArnoldNodeEntry& nentry,
   const KL::String param)
{
   iter.it = AiNodeEntryGetMetaDataIterator(nentry.entry, param.data());
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

// param iterator functions
FABRIC_EXT_EXPORT void fe_AiParamIteratorDestroy(
   ArnoldParamIterator& iter)
{
   AiParamIteratorDestroy(iter.it);
}

FABRIC_EXT_EXPORT void fe_AiParamIteratorGetNext(
   ArnoldParamEntry& pentry,
   ArnoldParamIterator& iter)
{
   pentry.entry = AiParamIteratorGetNext(iter.it);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiParamIteratorFinished(
   ArnoldParamIterator& iter)
{
   return AiParamIteratorFinished(iter.it);
}

// metadata iterator functions
FABRIC_EXT_EXPORT void fe_AiMetaDataIteratorDestroy(
   ArnoldMetaDataIterator& iter)
{
   AiMetaDataIteratorDestroy(iter.it);
}

FABRIC_EXT_EXPORT void fe_AiMetaDataIteratorGetNext(
   ArnoldMetaDataEntry& mdentry,
   ArnoldMetaDataIterator& iter)
{
   mdentry.entry = AiMetaDataIteratorGetNext(iter.it);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiMetaDataIteratorFinished(
   ArnoldMetaDataIterator& iter)
{
   return AiMetaDataIteratorFinished(iter.it);
}
