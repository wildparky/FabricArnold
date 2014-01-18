#ifndef NODE_ENTRY_H
#define NODE_ENTRY_H

#include <Fabric/EDK/EDK.h>

#include <ai.h>

struct ArnoldNodeMethods
{
   AtNodeMethods* methods;
};

struct ArnoldNodeEntry
{
   const AtNodeEntry* entry;
};

#endif