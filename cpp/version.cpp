//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiGetVersion(
   KL::String& version,
   KL::String::IOParam arch,
   KL::String::IOParam major,
   KL::String::IOParam minor,
   KL::String::IOParam fix)
{
   version = "";
   version = AiGetVersion(arch.data(), major.data(), minor.data(), fix.data());
}

FABRIC_EXT_EXPORT void fe_AiGetVersionInfo(
   KL::String& info)
{
   info = "";
   info = AiGetVersionInfo();
}

FABRIC_EXT_EXPORT void fe_AiGetCompileOptions(
   KL::String& options)
{
   options = "";
   options = AiGetCompileOptions();
}
FABRIC_EXT_EXPORT KL::Boolean fe_AiCheckAPIVersion(
   KL::String::INParam arch,
   KL::String::INParam major,
   KL::String::INParam minor)
{
   return AiCheckAPIVersion(arch.data(), major.data(), minor.data());
}

FABRIC_EXT_EXPORT void fe_AiSetAppString(
   KL::String::INParam appstr)
{
   AiSetAppString(appstr.data());
}
