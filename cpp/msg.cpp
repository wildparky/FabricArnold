//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiMsgSetLogFileName(
   KL::String::INParam filename)
{
   AiMsgSetLogFileName(filename.data());
}

FABRIC_EXT_EXPORT void fe_AiMsgSetLogFileFlags(
   KL::Integer flags)
{
   AiMsgSetLogFileFlags(flags);
}

FABRIC_EXT_EXPORT void fe_AiMsgSetConsoleFlags(
   KL::Integer flags)
{
   AiMsgSetConsoleFlags(flags);
}
FABRIC_EXT_EXPORT void fe_AiMsgSetMaxWarnings(
   KL::Integer max_warnings)
{
   AiMsgSetMaxWarnings(max_warnings);
}

FABRIC_EXT_EXPORT void fe_AiMsgInfo(
   KL::String::INParam format)
{
   AiMsgInfo(format.data());
}

FABRIC_EXT_EXPORT void fe_AiMsgDebug(
   KL::String::INParam format)
{
   AiMsgDebug(format.data());
}

FABRIC_EXT_EXPORT void fe_AiMsgWarning(
   KL::String::INParam format)
{
   AiMsgWarning(format.data());
}

FABRIC_EXT_EXPORT void fe_AiMsgError(
   KL::String::INParam format)
{
   AiMsgError(format.data());
}

FABRIC_EXT_EXPORT void fe_AiMsgFatal(
   KL::String::INParam format)
{
   AiMsgFatal(format.data());
}

FABRIC_EXT_EXPORT void fe_AiMsgTab(
   KL::Integer tabinc)
{
   AiMsgTab(tabinc);
}

FABRIC_EXT_EXPORT KL::UInt64 fe_AiMsgUtilGetUsedMemory()
{
   return AiMsgUtilGetUsedMemory();
}

FABRIC_EXT_EXPORT KL::UInt32 fe_AiMsgUtilGetElapsedTime()
{
   return AiMsgUtilGetElapsedTime();
}
