#ifndef VECTOR_H
#define VECTOR_H

#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_KL_STRUCT( ArnoldPoint, {
   KL::Float32 x;
   KL::Float32 y;
   KL::Float32 z;
});

FABRIC_EXT_KL_STRUCT( ArnoldPoint2, {
   KL::Float32 x;
   KL::Float32 y;
});

typedef ArnoldPoint ArnoldVector;
typedef ArnoldPoint2 ArnoldVector2;

FABRIC_EXT_KL_STRUCT( ArnoldHPoint, {
   KL::Float32 x;
   KL::Float32 y;
   KL::Float32 z;
   KL::Float32 w;
});

// FABRIC_EXT_KL_STRUCT( ArnoldVector, {
//    KL::Float32 x;
//    KL::Float32 y;
//    KL::Float32 z;
// });

// FABRIC_EXT_KL_STRUCT( ArnoldVector2, {
//    KL::Float32 x;
//    KL::Float32 y;
// });

inline void CopyVector(AtPoint& src, ArnoldPoint& dst)
{
   dst.x = src.x;
   dst.y = src.y;
   dst.z = src.z;
}

inline void CopyVector(AtPoint* src, ArnoldPoint& dst)
{
   dst.x = src->x;
   dst.y = src->y;
   dst.z = src->z;
}

inline void CopyHVector(AtHPoint* src, ArnoldHPoint& dst)
{
   dst.x = src->x;
   dst.y = src->y;
   dst.z = src->z;
   dst.w = src->w;
}

inline void CopyVector(ArnoldPoint& src, AtPoint& dst)
{
   dst.x = src.x;
   dst.y = src.y;
   dst.z = src.z;
}

inline void CopyVector(ArnoldPoint* src, AtPoint& dst)
{
   dst.x = src->x;
   dst.y = src->y;
   dst.z = src->z;
}

inline void CopyHVector(ArnoldHPoint* src, AtHPoint& dst)
{
   dst.x = src->x;
   dst.y = src->y;
   dst.z = src->z;
   dst.w = src->w;
}

#endif
