#!/usr/bin/env python
# test_0002

import os
from arnold import *

testNumber = "test_0002"
print("[FabricArnold::TestSuite] Generating reference image for {0}...".format(testNumber))

start = time.clock()
AiBegin()

# create a sphere
sphere = AiNode("sphere")
AiNodeSetStr(sphere, "name", "mysphere")
AiNodeSetFlt(sphere, "radius", 5.0)

# create a lambert shader
lambert = AiNode("lambert")
AiNodeSetStr(lambert, "name", "myshader")
AiNodeSetRGB(lambert, "Kd_color", 0.0, 1.0, 0.0)

# assign the sphere's shader
AiNodeSetPtr(sphere, "shader", lambert)

# create a perspective camera
camera = AiNode("persp_camera")
AiNodeSetStr(camera, "name", "mycamera")
AiNodeSetPnt(camera, "position", 0.0, 0.0, 20.0)

# create a point light
light = AiNode("point_light")
AiNodeSetStr(light, "name", "mylight")
AiNodeSetFlt(light, "exposure", 7.5)
AiNodeSetPnt(light, "position", 0.0, 10.0, 10.0)

# set render options
options = AiUniverseGetOptions()
AiNodeSetInt(options, "AA_samples", 1)
AiNodeSetInt(options, "xres", 320)
AiNodeSetInt(options, "yres", 240)
AiNodeSetPtr(options, "camera", camera)

# create an output driver
driver = AiNode("driver_jpeg")
AiNodeSetStr(driver, "name", "mydriver")
filename = os.path.join(os.getcwd(), testNumber, "reference.jpg")
AiNodeSetStr(driver, "filename", filename)

# create a gaussian filter node
gfilter = AiNode("gaussian_filter")
AiNodeSetStr(gfilter, "name", "myfilter");

# assign th driver and the filter to the outputs
outputs_array = AiArrayAllocate(1, 1, AI_TYPE_STRING)
AiArraySetStr(outputs_array, 0, "RGB RGB myfilter mydriver")
AiNodeSetArray(options, "outputs", outputs_array)

# render the scene
result = AiRender(AI_RENDER_MODE_CAMERA)
if result != AI_SUCCESS:
    print("[FabricArnold::TestSuite] Error {0}".format(result))

# get scene bounds doesn't work unless the render is called
bounds = AiUniverseGetSceneBounds()

# remove the sphere, create a box the size of the bounds
AiNodeDestroy(sphere)
box = AiNode("box")
AiNodeSetStr(box, "name", "mybox")
AiNodeSetPtr(box, "shader", lambert)

AiNodeSetPnt(box, "min", bounds.min.x, bounds.min.y, bounds.min.z)
AiNodeSetPnt(box, "max", bounds.max.x, bounds.max.y, bounds.max.z)

# render the box now
result = AiRender(AI_RENDER_MODE_CAMERA)
if result != AI_SUCCESS:
    print("[FabricArnold::TestSuite] Error {0}".format(result))

AiEnd()
secs = time.clock() - start
print("Elapsed time: {0} seconds".format(secs))
