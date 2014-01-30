//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT KL::Integer fe_AiASSWrite(
   const KL::String& filename)
{
   return AiASSWrite(filename.data());
}

FABRIC_EXT_EXPORT KL::Integer fe_AiASSWrite_masked(
   const KL::String& filename,
   const KL::Integer mask)
{
   return AiASSWrite(filename.data(), mask);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiASSWrite_masked_procs(
   const KL::String& filename,
   const KL::Integer mask,
   const KL::Boolean open_procs)
{
   return AiASSWrite(filename.data(), mask, open_procs);
}

FABRIC_EXT_EXPORT KL::Integer fe_AiASSLoad(
   const KL::String& filename)
{
   return AiASSLoad(filename.data());
}

FABRIC_EXT_EXPORT KL::Integer fe_AiASSLoad_masked(
   const KL::String& filename,
   const KL::Integer mask)
{
   return AiASSLoad(filename.data(), mask);
}
