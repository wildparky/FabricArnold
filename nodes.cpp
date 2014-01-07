#include "nodes.h"
#include "array.h"

using namespace Fabric::EDK;

// node methods

FABRIC_EXT_EXPORT void fe_AiNode(
   ArnoldNode& node,
   const KL::String& name)
{
   node.node = AiNode(name.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeLookUpByName(
   ArnoldNode& node,
   const KL::String& name)
{
   node.node = AiNodeLookUpByName(name.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeReset(
   ArnoldNode* node)
{
   AiNodeReset(node->node);
}

FABRIC_EXT_EXPORT void fe_AiNodeClone(
   ArnoldNode& clone,
   ArnoldNode* node)
{
   clone.node = AiNodeClone(node->node);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeDestroy(
   ArnoldNode* node)
{
   return AiNodeDestroy(node->node);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeIs(
   ArnoldNode* node,
   const KL::String& str)
{
   return AiNodeIs(node->node, str.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeDeclare(
   ArnoldNode* node,
   const KL::String& param,
   const KL::String& declaration)
{
   return AiNodeDeclare(node->node, param.data(), declaration.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeLink(
   ArnoldNode* src,
   const KL::String input,
   ArnoldNode* target)
{
   return AiNodeLink(src->node, input.data(), target->node);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeLinkOutput(
   ArnoldNode* src,
   const KL::String& output,
   ArnoldNode* target,
   const KL::String& input)
{
   return AiNodeLinkOutput(
      src->node, output.data(), target->node, input.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeUnlink(
   ArnoldNode* node,
   const KL::String& input)
{
   return AiNodeUnlink(node->node, input.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeIsLinked(
   ArnoldNode* node,
   const KL::String& input)
{
   return AiNodeIsLinked(node->node, input.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetLink(
   ArnoldNode& link,
   ArnoldNode& node,
   const KL::String& input)
{
   link.node = AiNodeGetLink(node.node, input.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetName(
   KL::String& name,
   ArnoldNode& node)
{
   name = KL::String(AiNodeGetName(node.node));
}

// node parameter writer functions

FABRIC_EXT_EXPORT void fe_AiNodeSetByte(
   ArnoldNode& node,
   const KL::String& param,
   const KL::Byte val)
{
   AiNodeSetByte(node.node, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetInt(
   ArnoldNode& node,
   const KL::String& param,
   const KL::Integer val)
{
   AiNodeSetInt(node.node, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetUInt(
   ArnoldNode& node,
   const KL::String& param,
   const KL::UInt32 val)
{
   AiNodeSetUInt(node.node, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetBool(
   ArnoldNode& node,
   const KL::String& param,
   const KL::Boolean val)
{
   AiNodeSetBool(node.node, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetFlt(
   ArnoldNode& node,
   const KL::String& param,
   const KL::Float32 val)
{
   AiNodeSetFlt(node.node, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetRGB(
   ArnoldNode& node,
   const KL::String& param,
   const KL::Float32 r,
   const KL::Float32 g,
   const KL::Float32 b)
{
   AiNodeSetRGB(node.node, param.data(), r, g, b);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetRGBA(
   ArnoldNode& node,
   const KL::String& param,
   const KL::Float32 r,
   const KL::Float32 g,
   const KL::Float32 b,
   const KL::Float32 a)
{
   AiNodeSetRGBA(node.node, param.data(), r, g, b, a);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetVec(
   ArnoldNode& node,
   const KL::String& param,
   const KL::Float32 x,
   const KL::Float32 y,
   const KL::Float32 z)
{
   AiNodeSetVec(node.node, param.data(), x, y, z);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetPnt(
   ArnoldNode& node,
   const KL::String& param,
   const KL::Float32 x,
   const KL::Float32 y,
   const KL::Float32 z)
{
   AiNodeSetPnt(node.node, param.data(), x, y, z);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetPnt2(
   ArnoldNode& node,
   const KL::String& param,
   const KL::Float32 x,
   const KL::Float32 y)
{
   AiNodeSetPnt2(node.node, param.data(), x, y);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetStr(
   ArnoldNode& node,
   const KL::String& param,
   const KL::String& str)
{
   AiNodeSetStr(node.node, param.data(), str.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeSetPtr(
   ArnoldNode& node,
   const KL::String& param,
   KL::Data ptr)
{
   AiNodeSetPtr(node.node, param.data(), ptr);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetArray(
   ArnoldNode& node,
   const KL::String& param,
   ArnoldArray& array)
{
   AiNodeSetArray(node.node, param.data(), array.array);
}

// node parameter reader functions

FABRIC_EXT_EXPORT KL::Byte fe_AiNodeGetByte(
   ArnoldNode& node,
   const KL::String& param)
{
   return AiNodeGetByte(node.node, param.data());
}

FABRIC_EXT_EXPORT KL::Integer fe_AiNodeGetInt(
   ArnoldNode& node,
   const KL::String& param)
{
   return AiNodeGetInt(node.node, param.data());
}

FABRIC_EXT_EXPORT KL::UInt32 fe_AiNodeGetUInt(
   ArnoldNode& node,
   const KL::String& param)
{
   return AiNodeGetUInt(node.node, param.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeGetBool(
   ArnoldNode& node,
   const KL::String& param)
{
   return AiNodeGetBool(node.node, param.data());
}

FABRIC_EXT_EXPORT KL::Float32 fe_AiNodeGetFlt(
   ArnoldNode& node,
   const KL::String& param)
{
   return AiNodeGetFlt(node.node, param.data());
}

// FABRIC_EXT_EXPORT void fe_AiNodeGetRGB(
//    ArnoldNode& node,
//    const KL::String& param,
//    const KL::Float32 r,
//    const KL::Float32 g,
//    const KL::Float32 b)
// {
//    AiNodeGetRGB(node.node, param.data(), r, g, b);
// }

// FABRIC_EXT_EXPORT void fe_AiNodeGetRGBA(
//    ArnoldNode& node,
//    const KL::String& param,
//    const KL::Float32 r,
//    const KL::Float32 g,
//    const KL::Float32 b,
//    const KL::Float32 a)
// {
//    AiNodeGetRGBA(node.node, param.data(), r, g, b, a);
// }

// FABRIC_EXT_EXPORT void fe_AiNodeGetVec(
//    ArnoldNode& node,
//    const KL::String& param,
//    const KL::Float32 x,
//    const KL::Float32 y,
//    const KL::Float32 z)
// {
//    AiNodeGetVec(node.node, param.data(), x, y, z);
// }

// FABRIC_EXT_EXPORT void fe_AiNodeGetPnt(
//    ArnoldNode& node,
//    const KL::String& param,
//    const KL::Float32 x,
//    const KL::Float32 y,
//    const KL::Float32 z)
// {
//    AiNodeGetPnt(node.node, param.data(), x, y, z);
// }

// FABRIC_EXT_EXPORT void fe_AiNodeGetPnt2(
//    ArnoldNode& node,
//    const KL::String& param,
//    const KL::Float32 x,
//    const KL::Float32 y)
// {
//    AiNodeGetPnt2(node.node, param.data(), x, y);
// }

FABRIC_EXT_EXPORT void fe_AiNodeGetStr(
   KL::String& str,
   ArnoldNode& node,
   const KL::String& param)
{
   str = KL::String(AiNodeGetStr(node.node, param.data()));
}

// FABRIC_EXT_EXPORT void fe_AiNodeGetPtr(
//    ArnoldNode& node,
//    const KL::String& param,
//    KL::Data ptr)
// {
//    AiNodeGetPtr(node.node, param.data(), ptr);
// }

// FABRIC_EXT_EXPORT void fe_AiNodeGetArray(
//    ArnoldNode& node,
//    const KL::String& param,
//    ArnoldArray& array)
// {
//    AiNodeGetArray(node.node, param.data(), array.array);
// }