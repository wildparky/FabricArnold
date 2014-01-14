#ifndef COLOR_H
#define COLOR_H

#include <Fabric/EDK/EDK.h>

#include <ai.h>

using namespace Fabric::EDK;

FABRIC_EXT_KL_STRUCT( ArnoldRGB, {
   KL::Float32 r;
   KL::Float32 g;
   KL::Float32 b;
   ArnoldRGB(AtRGB& src)
   {
      this->r = src.r;
      this->g = src.g;
      this->b = src.b;
   }
   operator AtRGB()
   {
      AtRGB c;
      c.r = this->r;
      c.g = this->g;
      c.b = this->b;
      return c;
   }
   ArnoldRGB operator=(AtRGB c)
   {
      this->r = c.r;
      this->g = c.g;
      this->b = c.b;
      return *this;
   }
});

FABRIC_EXT_KL_STRUCT( ArnoldRGBA, {
   KL::Float32 r;
   KL::Float32 g;
   KL::Float32 b;
   KL::Float32 a;
   ArnoldRGBA(AtRGBA& src)
   {
      this->r = src.r;
      this->g = src.g;
      this->b = src.b;
      this->a = src.a;
   }
   operator AtRGBA()
   {
      AtRGBA c;
      c.r = this->r;
      c.g = this->g;
      c.b = this->b;
      c.a = this->a;
      return c;
   }
   ArnoldRGBA operator=(AtRGBA c)
   {
      this->r = c.r;
      this->g = c.g;
      this->b = c.b;
      this->a = c.a;
      return *this;
   }
});

inline void CopyColor(AtRGB& src, ArnoldRGB& dst)
{
   dst.r = src.r;
   dst.g = src.g;
   dst.b = src.b;
}

inline void CopyColor(AtRGBA& src, ArnoldRGBA& dst)
{
   dst.r = src.r;
   dst.g = src.g;
   dst.b = src.b;
   dst.a = src.a;
}

inline void CopyColor(ArnoldRGB& src, AtRGB& dst)
{
   dst.r = src.r;
   dst.g = src.g;
   dst.b = src.b;
}

inline void CopyColor(ArnoldRGBA& src, AtRGBA& dst)
{
   dst.r = src.r;
   dst.g = src.g;
   dst.b = src.b;
   dst.a = src.a;
}

#endif
