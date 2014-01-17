#include "enum.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT KL::Integer fe_AiEnumGetValue(
   ArnoldEnum enum_type,
   const KL::String string)
{
   return AiEnumGetValue(enum_type.enum, string.data());
}

FABRIC_EXT_EXPORT void fe_AiEnumGetString(
   KL::String& string,
   ArnoldEnum enum_type,
   KL::Integer int)
{
   string = "";
   string = AiEnumGetValue(enum_type.enum, int);
}