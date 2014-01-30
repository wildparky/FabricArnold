//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiLoadPlugins(
   KL::String::INParam directory)
{
   AiLoadPlugins(directory.data());
}

FABRIC_EXT_EXPORT void fe_AiLoadPlugin(
   KL::String::INParam path)
{
   AiLoadPlugins(path.data());
}
