#include "nodes.h"
#include "node_entry.h"
#include "params.h"
#include "array.h"
#include "color.h"
#include "vector.h"

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
   name = "";
   name = AiNodeGetName(node.node);
}

FABRIC_EXT_EXPORT void fe_AiNodeGetNodeEntry(
   ArnoldNodeEntry& nentry,
   ArnoldNode& node)
{
   nentry.entry = AiNodeGetNodeEntry(node.node);
}

FABRIC_EXT_EXPORT void fe_AiNodeGetParams(
   ArnoldParamValue& pvalue,
   ArnoldNode& node)
{
   pvalue.value = AiNodeGetParams(node.node);
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

FABRIC_EXT_EXPORT void fe_AiNodeSetNode(
   ArnoldNode& node,
   const KL::String& param,
   ArnoldNode& value)
{
   AiNodeSetPtr(node.node, param.data(), value.node);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetArray(
   ArnoldNode& node,
   const KL::String& param,
   AtArray& array)
{
   AiNodeSetArray(node.node, param.data(), &array);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetMatrix(
   ArnoldNode& node,
   const KL::String& param,
   AtMatrix& matrix)
{
   AiNodeSetMatrix(node.node, param.data(), matrix);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetAttributes(
   ArnoldNode& node,
   const KL::String& param)
{
   AiNodeSetAttributes(node.node, param.data());
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

FABRIC_EXT_EXPORT void fe_AiNodeGetRGB(
   AtRGB& color,
   ArnoldNode& node,
   const KL::String& param)
{
   color = AiNodeGetRGB(node.node, param.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetRGBA(
   AtRGBA& color,
   ArnoldNode& node,
   const KL::String& param)
{
   color = AiNodeGetRGBA(node.node, param.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetVec(
   AtVector& vector,
   ArnoldNode& node,
   const KL::String& param)
{
   vector = AiNodeGetVec(node.node, param.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetPnt(
   AtPoint& point,
   ArnoldNode& node,
   const KL::String& param)
{
   point = AiNodeGetPnt(node.node, param.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetPnt2(
   AtPoint2& point,
   ArnoldNode& node,
   const KL::String& param)
{
   point = AiNodeGetPnt2(node.node, param.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetStr(
   KL::String& str,
   ArnoldNode& node,
   const KL::String& param)
{
   str = KL::String(AiNodeGetStr(node.node, param.data()));
}

FABRIC_EXT_EXPORT KL::Data fe_AiNodeGetPtr(
   ArnoldNode& node,
   const KL::String& param)
{
   KL::Data ptr = NULL;
   ptr = AiNodeGetPtr(node.node, param.data());
   return ptr;
}

FABRIC_EXT_EXPORT void fe_AiNodeGetNode(
   ArnoldNode& outnode,
   ArnoldNode& node,
   const KL::String& param)
{
   outnode.node = (AtNode*)AiNodeGetPtr(node.node, param.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetArray(
   AtArray& array,
   ArnoldNode& node,
   const KL::String& param)
{
   AtArray* a = AiNodeGetArray(node.node, param.data());
   array = *a;
   // array.nelements = array.array->nelements;
   // array.nkeys = array.array->nkeys;
   // array.type = array.array->type;
}

FABRIC_EXT_EXPORT void fe_AiNodeGetMatrix(
   ArnoldNode& node,
   const KL::String& param,
   AtMatrix& matrix)
{
   AiNodeGetMatrix(node.node, param.data(), matrix);
}