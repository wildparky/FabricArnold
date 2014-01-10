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

FABRIC_EXT_EXPORT void fe_AiUniverseGetLights(
   KL::VariableArray<ArnoldNode>& lights)
{
   AtNode** nodes = AiUniverseGetLights();
   int nbLights = AiUniverseGetNumLights();
   lights.resize(nbLights);
   for (int i=0; i<nbLights; i++)
   {
      lights[i].node = nodes[i];
   }
}

FABRIC_EXT_EXPORT KL::Integer fe_AiUniverseGetNumGObjects()
{
   return AiUniverseGetNumGObjects();
}