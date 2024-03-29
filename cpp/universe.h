//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <Fabric/EDK/EDK.h>

#include <ai.h>

struct ArnoldNodeIterator
{
   AtNodeIterator* it;
};

struct ArnoldNodeEntryIterator
{
   AtNodeEntryIterator* it;
};

struct ArnoldAOVIterator
{
   AtAOVIterator* it;
};

struct ArnoldAOVEntry
{
   const AtAOVEntry* entry;
};

#endif