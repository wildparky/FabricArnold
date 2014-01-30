//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include "enum.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT KL::Integer fe_AiEnumGetValue(
   ArnoldEnum enum_type,
   const KL::String string)
{
   return AiEnumGetValue(enum_type.aenum, string.data());
}

FABRIC_EXT_EXPORT void fe_AiEnumGetString(
   KL::String& string,
   ArnoldEnum enum_type,
   KL::Integer index)
{
   string = "";
   string = AiEnumGetString(enum_type.aenum, index);
}