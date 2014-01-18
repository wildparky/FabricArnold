#ifndef PARAMS_H
#define PARAMS_H

#include <Fabric/EDK/EDK.h>

#include <ai.h>

struct ArnoldParamValue
{
   const AtParamValue* value;
};

struct ArnoldParamEntry
{
   const AtParamEntry* entry;
};

struct ArnoldUserParamEntry
{
   const AtUserParamEntry* entry;
};

#endif