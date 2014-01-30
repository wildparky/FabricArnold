//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#ifndef NODE_ENTRY_H
#define NODE_ENTRY_H

#include <Fabric/EDK/EDK.h>

#include <ai.h>

struct ArnoldNodeEntry
{
   const AtNodeEntry* entry;
};

struct ArnoldNodeMethods
{
   AtNodeMethods* methods;
};

struct ArnoldParamIterator
{
   AtParamIterator* it;
};

struct ArnoldMetaDataIterator
{
   AtMetaDataIterator* it;
};

struct ArnoldMetaDataEntry
{
   const AtMetaDataEntry* entry;
};

#endif
