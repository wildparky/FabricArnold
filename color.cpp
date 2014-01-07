#include "color.h"

using namespace Fabric::EDK;

FABRIC_EXT_EXPORT void fe_AiColor(
   ArnoldRGB* color,
   const KL::Float32 f)
{
   AtColor c = AiColor(f);
   color->r = c.r;
   color->g = c.g;
   color->b = c.b;
}

FABRIC_EXT_EXPORT void fe_AiColorCreate(
   ArnoldRGB* color,
   const KL::Float32 r,
   const KL::Float32 g,
   const KL::Float32 b)
{
   AtColor c = AiColorCreate(r, g, b);
   color->r = c.r;
   color->g = c.g;
   color->b = c.b;
}