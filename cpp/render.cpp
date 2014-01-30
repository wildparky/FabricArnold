//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiBegin()
{
   AiBegin();
}

FABRIC_EXT_EXPORT void fe_AiEnd()
{
   AiEnd();
}

FABRIC_EXT_EXPORT KL::Integer fe_AiRender(
   KL::Integer mode)
{
   return AiRender(mode);
}

FABRIC_EXT_EXPORT void fe_AiRenderAbort()
{
   AiRenderAbort();
}


FABRIC_EXT_EXPORT void fe_AiRenderInterrupt()
{
   AiRenderInterrupt();
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiRendering()
{
   return AiRendering();
}