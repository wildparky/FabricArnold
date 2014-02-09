//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

// #include <Fabric/EDK/EDK.h>

#include "./FabricArnold.h"
#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT KL::Integer fe_AiASSWrite(
   KL::Traits< KL::String >::INParam filename)
{
   return AiASSWrite(filename.data());
}

FABRIC_EXT_EXPORT KL::Integer fe_AiASSWrite_masked(
   KL::Traits< KL::String >::INParam filename,
   KL::Traits< KL::SInt32 >::INParam mask)
{
   return AiASSWrite(filename.data(), mask);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiASSWrite_masked_procs(
   KL::Traits< KL::String >::INParam filename,
   KL::Traits< KL::SInt32 >::INParam mask,
   KL::Traits< KL::Boolean >::INParam open_procs)
{
   return AiASSWrite(filename.data(), mask, open_procs);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiASSLoad(
   KL::Traits< KL::String >::INParam filename)
{
   return AiASSLoad(filename.data());
}

FABRIC_EXT_EXPORT KL::Integer fe_AiASSLoad_masked(
   KL::Traits< KL::String >::INParam filename,
   KL::Traits< KL::SInt32 >::INParam mask)
{
   return AiASSLoad(filename.data(), mask);
}
