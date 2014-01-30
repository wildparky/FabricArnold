//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include "color.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiColor(
   AtColor& color,
   const KL::Float32 f)
{
   color = AiColor(f);
   // color->r = c.r;
   // color->g = c.g;
   // color->b = c.b;
}

FABRIC_EXT_EXPORT void fe_AiColorCreate(
   AtColor& color,
   const KL::Float32 r,
   const KL::Float32 g,
   const KL::Float32 b)
{
   color = AiColorCreate(r, g, b);
   // color->r = c.r;
   // color->g = c.g;
   // color->b = c.b;
}

FABRIC_EXT_EXPORT void fe_AiRGBACreate(
   AtRGBA& rgba,
   const KL::Float32 r,
   const KL::Float32 g,
   const KL::Float32 b,
   const KL::Float32 a)
{
   rgba = AiRGBACreate(r, g, b, a);
   // color->r = c.r;
   // color->g = c.g;
   // color->b = c.b;
   // color->a = c.a;
}