//
// Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
//

#include "./FabricArnold.h"

#include <ai.h>

using namespace Fabric::EDK;

// node methods

FABRIC_EXT_EXPORT void fe_AiNode(
   KL::Traits< KL::AtNode >::Result result,
   KL::Traits< KL::String>::INParam name)
{
   result.node = AiNode(name.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeLookUpByName(
   KL::Traits< KL::AtNode >::Result result,
   KL::Traits< KL::String>::INParam name)
{
   result.node = AiNodeLookUpByName(name.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeReset(
   KL::Traits< KL::AtNode >::IOParam node)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeReset(n);
}

FABRIC_EXT_EXPORT void fe_AiNodeClone(
   KL::Traits< KL::AtNode >::Result result,
   KL::Traits< KL::AtNode >::INParam node)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   result.node = AiNodeClone(n);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeDestroy(
   KL::Traits< KL::AtNode >::IOParam node)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   return AiNodeDestroy(n);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeIs(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam str)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   return AiNodeIs(n, str.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeDeclare(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::String >::INParam declaration)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   return AiNodeDeclare(n, param.data(), declaration.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeLink(
   KL::Traits< KL::AtNode >::INParam src,
   KL::Traits< KL::String >::INParam input,
   KL::Traits< KL::AtNode >::INParam target)
{
   AtNode* s = reinterpret_cast<AtNode *>(src.node);
   AtNode* t = reinterpret_cast<AtNode *>(target.node);
   return AiNodeLink(s, input.data(), t);
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeLinkOutput(
   KL::Traits< KL::AtNode >::INParam src,
   KL::Traits< KL::String >::INParam output,
   KL::Traits< KL::AtNode >::INParam target,
   KL::Traits< KL::String >::INParam input)
{
   AtNode* s = reinterpret_cast<AtNode *>(src.node);
   AtNode* t = reinterpret_cast<AtNode *>(target.node);
   return AiNodeLinkOutput(s, output.data(), t, input.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeUnlink(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam input)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   return AiNodeUnlink(n, input.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeIsLinked(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam input)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   return AiNodeIsLinked(n, input.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetLink(
   KL::Traits< KL::AtNode >::Result result,
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam input,
   KL::Traits< KL::SInt32 >::INParam comp)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   result.node = AiNodeGetLink(n, input.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetName(
   KL::Traits< KL::String >::Result result,
   KL::Traits< KL::AtNode >::INParam node)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   result = AiNodeGetName(n);
}

FABRIC_EXT_EXPORT void fe_AiNodeGetNodeEntry(
   KL::Traits< KL::AtNodeEntry >::Result result,
   KL::Traits< KL::AtNode >::INParam node)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   AtNodeEntry const * nentry = AiNodeGetNodeEntry(n);
   result = reinterpret_cast<KL::AtNodeEntry &>(nentry);
}

// FABRIC_EXT_EXPORT void fe_AiNodeGetParams(
//    ArnoldParamValue& pvalue,
//    ArnoldNode& node)
// {
//    pvalue.value = AiNodeGetParams(node.node);
// }

// FABRIC_EXT_EXPORT KL::Data fe_AiNodeGetLocalData(
//    ArnoldNode& node)
// {
//    return AiNodeGetLocalData(node.node);
// }

// FABRIC_EXT_EXPORT void fe_AiNodeSetLocalData(
//    KL::Traits< KL::AtNode >::INParam node,
//    KL::Data data)
// {
//    AiNodeSetLocalData(node.node, data);
// }

// FABRIC_EXT_EXPORT void fe_AiNodeLookUpUserParameter(
//    ArnoldUserParamEntry& upentry,
//    KL::Traits< KL::AtNode >::INParam node,
//    KL::String::INParam param)
// {
//    upentry.entry = AiNodeLookUpUserParameter(node.node, param.data());
// }

// FABRIC_EXT_EXPORT void fe_AiNodeGetUserParamIterator(
//    ArnoldUserParamIterator& iter,
//    ArnoldNode& node)
// {
//    iter.it = AiNodeGetUserParamIterator(node.node);
// }

// // user param iterator methods
// FABRIC_EXT_EXPORT void fe_AiUserParamIteratorDestroy(
//    ArnoldUserParamIterator& iter)
// {
//    AiUserParamIteratorDestroy(iter.it);
// }

// FABRIC_EXT_EXPORT void fe_AiUserParamIteratorGetNext(
//    ArnoldUserParamEntry& upentry,
//    ArnoldUserParamIterator& iter)
// {
//    upentry.entry = AiUserParamIteratorGetNext(iter.it);
// }

// FABRIC_EXT_EXPORT KL::Boolean fe_AiUserParamIteratorFinished(
//    ArnoldUserParamIterator& iter)
// {
//    return AiUserParamIteratorFinished(iter.it);
// }

// node parameter writer functions

FABRIC_EXT_EXPORT void fe_AiNodeSetByte(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::UInt8 >::INParam val)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetByte(n, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetInt(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::SInt32 >::INParam val)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetInt(n, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetUInt(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::UInt32 >::INParam val)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetUInt(n, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetBool(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::Boolean >::INParam val)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetBool(n, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetFlt(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::Float32 >::INParam val)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetFlt(n, param.data(), val);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetRGB(
  KL::Traits< KL::AtNode >::IOParam node,
  KL::Traits< KL::String >::INParam param,
  KL::Traits< KL::Float32 >::INParam r,
  KL::Traits< KL::Float32 >::INParam g,
  KL::Traits< KL::Float32 >::INParam b)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetRGB(n, param.data(), r, g, b);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetRGBA(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::Float32 >::INParam r,
   KL::Traits< KL::Float32 >::INParam g,
   KL::Traits< KL::Float32 >::INParam b,
   KL::Traits< KL::Float32 >::INParam a)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetRGBA(n, param.data(), r, g, b, a);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetVec(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::Float32 >::INParam x,
   KL::Traits< KL::Float32 >::INParam y,
   KL::Traits< KL::Float32 >::INParam z)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetVec(n, param.data(), x, y, z);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetPnt(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::Float32 >::INParam x,
   KL::Traits< KL::Float32 >::INParam y,
   KL::Traits< KL::Float32 >::INParam z)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetPnt(n, param.data(), x, y, z);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetPnt2(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::Float32 >::INParam x,
   KL::Traits< KL::Float32 >::INParam y)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetPnt2(n, param.data(), x, y);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetStr(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::String >::INParam str)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetStr(n, param.data(), str.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeSetPtr(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::Data >::INParam ptr)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetPtr(n, param.data(), ptr);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetNode(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::AtNode >::INParam value)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetPtr(n, param.data(), value.node);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetArray(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::AtArray >::IOParam array)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AtArray* a = reinterpret_cast<AtArray *>(&array);
   printf(AiNodeGetName(n));
   printf(AiArrayGetStr(a, 0));
   AiNodeSetArray(n, param.data(), a);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetMatrix(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::FixedArray< KL::FixedArray< KL::Float32, 4 >, 4 > >::IOParam matrix)
{
   AtNode& n = reinterpret_cast<AtNode &>(node.node);
   AtMatrix& m = reinterpret_cast<AtMatrix &>(matrix);
   AiNodeSetMatrix(&n, param.data(), m);
}

FABRIC_EXT_EXPORT void fe_AiNodeSetAttributes(
   KL::Traits< KL::AtNode >::IOParam node,
   KL::Traits< KL::String >::INParam attributes)
{
   AtNode* n = reinterpret_cast<AtNode *>(node.node);
   AiNodeSetAttributes(n, attributes.data());
}

// node parameter reader functions

FABRIC_EXT_EXPORT KL::Byte fe_AiNodeGetByte(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   return AiNodeGetByte(n, param.data());
}

FABRIC_EXT_EXPORT KL::Integer fe_AiNodeGetInt(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   return AiNodeGetInt(n, param.data());
}

FABRIC_EXT_EXPORT KL::UInt32 fe_AiNodeGetUInt(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   return AiNodeGetUInt(n, param.data());
}

FABRIC_EXT_EXPORT KL::Boolean fe_AiNodeGetBool(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   return AiNodeGetBool(n, param.data());
}

FABRIC_EXT_EXPORT KL::Float32 fe_AiNodeGetFlt(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   return AiNodeGetFlt(n, param.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetRGB(
   KL::Traits< KL::AtRGB >::Result result,
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   AtRGB& color = reinterpret_cast<AtRGB &>(result);
   AtRGB rgb = AiNodeGetRGB(n, param.data());
   color = rgb;
}

FABRIC_EXT_EXPORT void fe_AiNodeGetRGBA(
   KL::Traits< KL::AtRGBA >::Result result,
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   AtRGBA& color = reinterpret_cast<AtRGBA &>(result);
   AtRGBA rgba = AiNodeGetRGBA(n, param.data());
   color = rgba;
}

FABRIC_EXT_EXPORT void fe_AiNodeGetVec(
   KL::Traits< KL::AtVector >::Result result,
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   AtVector vec = AiNodeGetVec(n, param.data());
   result = reinterpret_cast<KL::AtVector &>(vec);
}

FABRIC_EXT_EXPORT void fe_AiNodeGetPnt(
   KL::Traits< KL::AtPoint >::Result result,
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   AtPoint pnt = AiNodeGetPnt(n, param.data());
   result = reinterpret_cast<KL::AtPoint &>(pnt);
}

FABRIC_EXT_EXPORT void fe_AiNodeGetPnt2(
   KL::Traits< KL::AtPoint2 >::Result result,
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   AtPoint2 pnt2 = AiNodeGetPnt2(n, param.data());
   result = reinterpret_cast<KL::AtPoint2 &>(pnt2);
}

FABRIC_EXT_EXPORT void fe_AiNodeGetStr(
   KL::Traits< KL::String >::Result result,
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   result = KL::String(AiNodeGetStr(n, param.data()));
}

FABRIC_EXT_EXPORT KL::Data fe_AiNodeGetPtr(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   KL::Data ptr = NULL;
   AtNode const & n = reinterpret_cast<AtNode const &>(node.node);
   ptr = AiNodeGetPtr(&n, param.data());
   return ptr;
}

FABRIC_EXT_EXPORT void fe_AiNodeGetNode(
   KL::Traits< KL::AtNode >::Result result,
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   result.node = AiNodeGetPtr(n, param.data());
}

FABRIC_EXT_EXPORT void fe_AiNodeGetArray(
   KL::Traits< KL::AtArray >::Result result,
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   AtArray& array = reinterpret_cast<AtArray &>(result);
   AtArray* a = AiNodeGetArray(n, param.data());
   array = *a;
}

FABRIC_EXT_EXPORT void fe_AiNodeGetMatrix(
   KL::Traits< KL::AtNode >::INParam node,
   KL::Traits< KL::String >::INParam param,
   KL::Traits< KL::AtMatrix >::IOParam matrix)
{
   AtNode const * n = reinterpret_cast<AtNode const *>(node.node);
   AtMatrix& m = reinterpret_cast<AtMatrix &>(matrix);
   AiNodeGetMatrix(n, param.data(), m);
}