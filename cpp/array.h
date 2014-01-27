#ifndef ARRAY_H
#define ARRAY_H

#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

struct ArnoldArray
{
   AtArray* array;
   KL::UInt32 nelements;
   KL::Byte nkeys;
   KL::Byte type;
   KL::Byte padding[2];
};

#endif
