//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include "./FabricArnold.h"

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT KL::Boolean fe_AiUniverseIsActive()
{
   return AiUniverseIsActive();
}

FABRIC_EXT_EXPORT void fe_AiUniverseCacheFlush(
   KL::Traits< KL::SInt32 >::INParam cache_flags)
{
   AiUniverseCacheFlush(cache_flags);
}

FABRIC_EXT_EXPORT void fe_AiUniverseGetOptions(
   KL::Traits< KL::AtNode >::Result result)
{
   result.node = AiUniverseGetOptions();
}

FABRIC_EXT_EXPORT void fe_AiUniverseGetCamera(
   KL::Traits< KL::AtNode >::Result result)
{
   result.node = AiUniverseGetCamera();
}

FABRIC_EXT_EXPORT void fe_AiUniverseGetSceneBounds(
   KL::Traits< KL::AtBBox >::Result result)
{
   AtBBox bbox = AiUniverseGetSceneBounds();
   result = reinterpret_cast<KL::AtBBox &>(bbox);
}

// FABRIC_EXT_EXPORT KL::Integer fe_AiUniverseGetNumLights()
// {
//    return AiUniverseGetNumLights();
// }

// FABRIC_EXT_EXPORT void fe_AiUniverseGetLights(
//    KL::VariableArray< KL::AtNode >::Result result)
// {
//    AtNode** nodes = AiUniverseGetLights();
//    int nbLights = AiUniverseGetNumLights();
//    result.resize(nbLights);
//    for (int i=0; i<nbLights; i++)
//    {
//       result[i].node = nodes[i];
//    }
// }

// FABRIC_EXT_EXPORT KL::Integer fe_AiUniverseGetNumGObjects()
// {
//    return AiUniverseGetNumGObjects();
// }

FABRIC_EXT_EXPORT void fe_AiUniverseGetNodeIterator(
   KL::Traits< KL::AtNodeIterator >::Result iter,
   KL::Traits< KL::UInt32 >::INParam node_mask)
{
   iter.it = AiUniverseGetNodeIterator(node_mask);
}

// FABRIC_EXT_EXPORT void fe_AiUniverseGetNodeEntryIterator(
//    ArnoldNodeEntryIterator& iter,
//    KL::UInt32 node_mask)
// {
//    iter.it = AiUniverseGetNodeEntryIterator(node_mask);
// }

// FABRIC_EXT_EXPORT void fe_AiUniverseGetAOVIterator(
//    ArnoldAOVIterator& iter)
// {
//    iter.it = AiUniverseGetAOVIterator();
// }

// // node iterator functions
// FABRIC_EXT_EXPORT void fe_AiNodeIteratorDestroy(
//    ArnoldNodeIterator& iter)
// {
//    AiNodeIteratorDestroy(iter.it);
// }

// FABRIC_EXT_EXPORT void fe_AiNodeIteratorGetNext(
//    ArnoldNode& node,
//    ArnoldNodeIterator& iter)
// {
//    node.node = AiNodeIteratorGetNext(iter.it);
// }

// FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeIteratorFinished(
//    ArnoldNodeIterator& iter)
// {
//    return AiNodeIteratorFinished(iter.it);
// }

// // node entry iterator functions
// FABRIC_EXT_EXPORT void fe_AiNodeEntryIteratorDestroy(
//    ArnoldNodeEntryIterator& iter)
// {
//    AiNodeEntryIteratorDestroy(iter.it);
// }

// FABRIC_EXT_EXPORT void  fe_AiNodeEntryIteratorGetNext(
//    ArnoldNodeEntry& nentry,
//    ArnoldNodeEntryIterator& iter)
// {
//    nentry.entry = AiNodeEntryIteratorGetNext(iter.it);
// }

// FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeEntryIteratorFinished(
//    ArnoldNodeEntryIterator& iter)
// {
//    return AiNodeEntryIteratorFinished(iter.it);
// }

// // aov iterator functions
// FABRIC_EXT_EXPORT void fe_AiAOVIteratorDestroy(
//    ArnoldAOVIterator& iter)
// {
//    AiAOVIteratorDestroy(iter.it);
// }

// FABRIC_EXT_EXPORT void  fe_AiAOVIteratorGetNext(
//    ArnoldAOVEntry& nentry,
//    ArnoldAOVIterator& iter)
// {
//    nentry.entry = AiAOVIteratorGetNext(iter.it);
// }

// FABRIC_EXT_EXPORT KL::Boolean fe_AiAOVIteratorFinished(
//    ArnoldAOVIterator& iter)
// {
//    return AiAOVIteratorFinished(iter.it);
// }
