import os
import glob
import re
import string

arnoldInclude = "E:/library/development/solidangle/Arnold-4.0.16.2-windows/include"

# process files
processFiles = [
   "ai_array.h",
   "ai_bbox.h",
   "ai_cameras.h",
   "ai_color.h",
   "ai_constants.h",
   "ai_dotass.h",
   "ai_enum.h",
   "ai_matrix.h",
   "ai_metadata.h",
   "ai_node_entry.h",
   "ai_nodes.h",
   "ai_noise.h",
   "ai_params.h",
   "ai_plugins.h",
   "ai_render.h",
   "ai_threads.h",
   "ai_types.h",
   "ai_universe.h",
   "ai_vector.h",
   "ai_version.h",
   "ai_render.h",
   "ai_msg.h"
   ]

# cpp/arnold type : kl type
typeMap = {
   "AtByte" : "Byte ",
   "AtByte*" : "Byte ",
   "const AtByte*" : "Byte ",
   "const void*" : "Data ",
   "const void**" : "Data ",
   "void" : "",
   "void*" : "Data ",
   "void**" : "Data ",
   "void*&" : "Data ",
   "bool" : "Boolean ",
   "bool&" : "Boolean ",
   "bool*" : "Boolean ",
   "const bool*" : "Boolean ",
   "const int*" : "Integer ",
   "int" : "Integer ",
   "int&" : "Integer ",
   "float" : "Scalar ",
   "float&" : "Scalar ",
   "float*" : "Scalar ",
   "double" : "Float64 ",
   "double*" : "Float64 ",
   "const float*" : "Scalar ",
   "char*" : "String ",
   "const char*" : "String ",
   "const char**" : "String ",
   "AtNode" : "ArnoldNode ",
   "AtNode*" : "ArnoldNode ",
   "AtNode**" : "ArnoldNode ",
   "const AtNode" : "ArnoldNode ",
   "const AtNode*" : "ArnoldNode ",
   "AtParamValue*" : "AtParamValue ",
   "const AtParamValue*" : "AtParamValue ",
   "AtUserParamIterator*" : "AtParamValue ",
   "const AtUserParamIterator*" : "",
   "AtRGB" : "AtRGB ",
   "const AtRGB*" : "AtRGB ",
   "AtRGB&" : "AtRGB ",
   "AtRGB*" : "AtRGB ",
   "AtRGBA" : "AtRGBA ",
   "AtRGBA&" : "AtRGBA ",
   "AtRGBA*" : "AtRGBA ",
   "const AtRGBA*" : "AtRGBA ",
   "AtColor" : "AtColor ",
   "AtColor&" : "AtColor ",
   "const AtColor&" : "AtColor ",
   "AtColor*" : "AtColor ",
   "const AtColor*" : "AtColor ",
   "const AtVector*" : "AtVector ",
   "AtVector" : "AtVector ",
   "AtVector&" : "AtVector ",
   "AtVector*" : "AtVector ",
   "AtPoint" : "AtPoint ",
   "AtPoint&" : "AtPoint ",
   "const AtPoint" : "AtPoint ",
   "AtPoint*" : "AtPoint ",
   "const AtPoint*" : "AtPoint ",
   "AtPoint2" : "AtPoint2 ",
   "AtPoint2&" : "AtPoint2 ",
   "AtVector2" : "AtVector2 ",
   "AtPoint2*" : "AtPoint2 ",
   "const AtPoint2" : "AtPoint2 ",
   "const AtPoint2*" : "AtPoint2 ",
   "AtHPoint" : "AtHPoint ",
   "AtHPoint&" : "AtHPoint ",
   "const AtHPoint" : "AtHPoint ",
   "AtHPoint*" : "AtHPoint ",
   "const AtHPoint*" : "AtHPoint ",
   "AtArray" : "AtArray ",
   "AtArray*" : "AtArray ",
   "AtArray**" : "AtArray ",
   "const AtArray*" : "AtArray ",
   "int*" : "Integer ",
   "const unsigned" : "UInt8 ",
   "unsigned int" : "UInt8 ",
   "unsigned int*" : "UInt8 ",
   "unsigned int&" : "UInt8 ",
   "AtUInt" : "UInt8 ",
   "AtUInt8" : "UInt8 ",
   "AtUInt16" : "UInt16 ",
   "AtUInt64" : "UInt64 ",
   "AtMatrix" : "AtMatrix ",
   "AtMatrix*" : "AtMatrix ",
   "const AtMatrix" : "AtMatrix ",
   "unsigned long" : "UInt32 ",
   "AtUInt32" : "UInt32 ",
   "AtUInt32*" : "UInt32 ",
   "AtCritSec*" : "AtCritSec ",
   "struct" : "struct ",
   "const struct" : "struct ",
   "AtEnum" : "AtEnum",
   "AtAOVSampleIterator*" : "Undefined ",
   "AtAOVIterator*" : "AtAOVIterator ",
   "const AtAOVIterator*" : "AtAOVIterator ",
   "const AtAOVSampleIterator*" : "Undefined ",
   "AtLicenseInfo*&" : "Undefined ",
   "AtMetaDataStore*" : "Undefined ",
   "AtNodeEntry*" : "AtNodeEntry ",
   "const AtMetaDataEntry*" : "Undefined ",
   "const AtNodeEntry*" : "AtNodeEntry ",
   "const AtNodeEntryIterator*" : "Undefined ",
   "AtNodeIterator*" : "AtNodeIterator ",
   "const AtNodeIterator*" : "AtNodeIterator ",
   "AtNodeEntryIterator*" : "Undefined ",
   "AtMsgCallBack" : "Undefined ",
   "AtParamIterator*" : "AtParamIterator ",
   "const AtParamIterator*" : "AtParamIterator ",
   "AtMetaDataIterator*" : "AtMetaDataIterator ",
   "const AtMetaDataIterator*" : "AtMetaDataIterator ",
   "AtNodeMethods*" : "Undefined ",
   "AtParamEntry" : "AtParamEntry ",
   "AtParamEntry*" : "AtParamEntry ",
   "const AtParamEntry*" : "AtParamEntry ",
   "const AtUserParamEntry*" : "Undefined ",
   "AtList*" : "Undefined ",
   "AtRay*" : "Undefined ",
   "AtRay" : "Undefined ",
   "const AtRay*" : "Undefined ",
   "AtScrSample*" : "Undefined ",
   "AtSampler*" : "Undefined ",
   "const AtSampler*" : "Undefined ",
   "const AtShaderGlobals*" : "Undefined ",
   "AtShaderGlobals*" : "Undefined ",
   "AtSamplerIterator*" : "Undefined ",
   "const AtSamplerIterator*" : "Undefined ",
   "AtMessageIterator*" : "Undefined ",
   "AtPointCloudIterator*" : "Undefined ",
   "const AtPointCloudIterator*" : "Undefined ",
   "AtPointCloudSample" : "Undefined ",
   "AtBRDFEvalSampleFunc" : "Undefined ",
   "AtBBox" : "AtBBox",
   "const AtAOVEntry*" : "AtAOVEntry "
   }

func_format = "function {type}{func_name}({param_list}) = \"fe_{func_name}\";"
define_format = "const Integer {const_name} = {const_value};"

def setParamListFromMatchObject(funcFormatDict, match):
   param_type = typeMap[match.group(1)]
   param_name = match.group(2)

   # comma delimiter, if this key isn't empty then add a comma
   if funcFormatDict["param_list"]:
      funcFormatDict["param_list"] += ", "
      funcFormatDict["param_list"] += "{0}{1}".format(param_type, param_name)
   else:
      funcFormatDict["param_list"] += "{0}{1}".format(param_type, param_name)

   return funcFormatDict


def main():

   headers = glob.glob(os.path.join(arnoldInclude, "*.h"))
   for file in headers:
      if os.path.basename(file) not in processFiles:
         print("skipping %s..." % os.path.basename(file))
         continue

      funcFormatDict = {}
      defineFormatDict = {}
      arnoldStructs = []
      arnoldFunctions = []
      arnoldConstants = []

      # parse the header files
      print("processing %s..." % os.path.basename(file))
      lines = open(file).read().split("\n")
      for line in lines:

         # functions
         if line.startswith("AI_API") or line.startswith("inline"):
            nonConstPattern = r"^(?:AI_API)\s*(\S+)\s*(\S+)\s*\((.*?)\)"
            constPattern = r"^(?:AI_API)\s*(\S+\s{1}\S+)\s*(\S+)\s*\((.*?)\)"
            match1 = re.search(nonConstPattern, line)
            match2 = re.search(constPattern, line)
            if match1:
               funcFormatDict["type"] = typeMap[match1.group(1)]
               funcFormatDict["func_name"] = match1.group(2)
               funcFormatDict["param_list"] = ""
               # the function might have multiple arguments
               # notice the split on ', ' the extra space was
               # confusing the regex
               params = match1.group(3).split(", ")
               for param in params:
                  if param.startswith("const"):
                     constPattern = r"^(\S+\s\S+)\s(.+)"
                     match3 = re.search(constPattern, param)
                     if match3:
                        funcFormatDict = setParamListFromMatchObject(funcFormatDict, match3)
                  elif param.startswith("unsigned"):
                     constPattern = r"^(\S+\s\S+)\s(.+)"
                     match3 = re.search(constPattern, param)
                     if match3:
                        funcFormatDict = setParamListFromMatchObject(funcFormatDict, match3)
                  else:
                     nonConstPattern = r"^(\S+)\s(.+)"
                     match3 = re.search(nonConstPattern, param)
                     if match3:
                        funcFormatDict = setParamListFromMatchObject(funcFormatDict, match3)

               formatted = func_format.format(**funcFormatDict)
               arnoldFunctions.append(formatted)
            elif match2:
               funcFormatDict["type"] = typeMap[match2.group(1)]
               funcFormatDict["func_name"] = match2.group(2)
               funcFormatDict["param_list"] = ""
               # the function might have multiple arguments
               # notice the split on ', ' the extra space was
               # confusing the regex
               params = match2.group(3).split(", ")
               for param in params:
                  if param.startswith("const") or param.startswith("unsigned"):
                     constPattern = r"^(\S+\s\S+)\s(.+)"
                     match3 = re.search(constPattern, param)
                     if match3:
                        funcFormatDict = setParamListFromMatchObject(funcFormatDict, match3)
                  else:
                     nonConstPattern = r"^(\S+)\s(.+)"
                     match3 = re.search(nonConstPattern, param)
                     if match3:
                        funcFormatDict = setParamListFromMatchObject(funcFormatDict, match3)

               formatted = func_format.format(**funcFormatDict)
               arnoldFunctions.append(formatted)

         # structures
         if line.startswith("struct"):
            # ex. "struct AtNode;"
            line = line.lstrip("struct")
            line = line.rstrip(";")
            line = line.strip()
            arnoldStructs.append(line)

         if line.startswith("typedef"):
            pass

         if line.startswith("#define"):
            defineFormatDict["const_name"] = ""
            defineFormatDict["const_value"] = ""
            # function defines
            if ";" in line:
               continue
            split = line.split()
            constantName = re.sub(r'[\W_]+', '', split[1])
            isUpper = [letter.isupper() for letter in constantName]
            if all(isUpper[0] == item for item in isUpper):
               defineFormatDict["const_name"] = split[1]
            if isinstance(split[2], (int, long, float, complex)):
               defineFormatDict["const_value"] = split[2]
            else:
               try:
                  i = string.atoi(split[2], 0)
                  defineFormatDict["const_value"] = split[2]
               except ValueError:
                  continue
            formatted = define_format.format(**defineFormatDict)
            arnoldConstants.append(formatted)

      klName = os.path.basename(file).replace(".h", ".kl")
      outputPath = os.path.join(os.path.dirname(__file__), klName)

      output = open(outputPath, "w")
      #output.write("\n")
      for struct in arnoldStructs:
         output.write("struct {0} {{}};\r".format(struct))
      output.write("\n")
      for func in arnoldFunctions:
         #print(func)
         output.write("{0}\n".format(func))
      for constant in arnoldConstants:
         output.write("{0}\n".format(constant))

      output.close()

if __name__ == '__main__':
   main()