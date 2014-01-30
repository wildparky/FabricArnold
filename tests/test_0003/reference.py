#!/usr/bin/env python
# test_0003

import os
import time
import math
from arnold import *

testNumber = "test_0003"
print("[FabricArnold::TestSuite] Generating reference image for {0}...".format(testNumber))

start = time.clock()
AiBegin()

nbSpheres = 100000
radius = 2.0

for i in range(nbSpheres):

    step = float(i)/float(nbSpheres)
    theta = AI_PITIMES2 * step

    x = radius * math.cos(theta)
    z = radius * math.sin(theta)

    # create a sphere
    sphere = AiNode("sphere")
    AiNodeSetStr(sphere, "name", "mysphere_{0}".format(i))
    AiNodeSetFlt(sphere, "radius", step*0.5)
    AiNodeSetPnt(sphere, "center", x, theta, z)

    # create a lambert shader
    lambert = AiNode("lambert")
    AiNodeSetStr(lambert, "name", "myshader_{0}".format(i))
    AiNodeSetRGB(lambert, "Kd_color", 0.0, 1.0, 0.0)

    # assign the sphere's shader
    AiNodeSetPtr(sphere, "shader", lambert)

# create a perspective camera
camera = AiNode("persp_camera")
AiNodeSetStr(camera, "name", "mycamera")
AiNodeSetPnt(camera, "position", 0.0, 5.0, 20.0)
AiNodeSetPnt(camera, "look_at", 0.0, 5.0, 0.0)

# create a point light
light = AiNode("point_light")
AiNodeSetStr(light, "name", "mylight")
AiNodeSetFlt(light, "exposure", 10.5)
AiNodeSetPnt(light, "position", 0.0, 20.0, 0.0)

# create a point light
light1 = AiNode("point_light")
AiNodeSetStr(light1, "name", "mylight_1")
AiNodeSetFlt(light1, "exposure", 10.5)
AiNodeSetPnt(light1, "position", 0.0, -20.0, 0.0)

# set render options
options = AiUniverseGetOptions()
AiNodeSetInt(options, "AA_samples", 4)
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

AiEnd()
secs = time.clock() - start
print("Elapsed time: {0} seconds".format(secs))
