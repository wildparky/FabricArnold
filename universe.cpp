#include <Fabric/EDK/EDK.h>

#include <ai.h>
#include "nodes.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT KL::Boolean fe_AiUniverseIsActive()
{
   return AiUniverseIsActive();
}

FABRIC_EXT_EXPORT void fe_AiUniverseCacheFlush(
   const KL::Integer cache_flags)
{
   AiUniverseCacheFlush(cache_flags);
}

FABRIC_EXT_EXPORT void fe_AiUniverseGetOptions(
   ArnoldNode& node)
{
   node.node = AiUniverseGetOptions();
}

FABRIC_EXT_EXPORT void fe_AiUniverseGetCamera(
   ArnoldNode& node)
{
   node.node = AiUniverseGetCamera();
}

FABRIC_EXT_EXPORT KL::Integer fe_AiUniverseGetNumLights()
{
   return AiUniverseGetNumLights();
}

// array of arnold nodes?
// FABRIC_EXT_EXPORT void fe_AiUniverseGetLights(
//    ArnoldNode** node)
// {
//    AtNode* nodes = AiUniverseGetLights();
// }

FABRIC_EXT_EXPORT KL::Integer fe_AiUniverseGetNumGObjects()
{
   return AiUniverseGetNumGObjects();
}