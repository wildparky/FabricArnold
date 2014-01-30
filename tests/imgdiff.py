#!/usr/bin/env python
# 
# Copyright (c) 2014, Steven Caron <steven@steven-caron.com> All rights reserved.
# 
# FabricArnold Extension

# absoluate difference of two images using PIL (pillow fork)
# 8bit RGB (jpg) support for now

import sys

from PIL import Image
from PIL import ImageChops

def pixeldiff(p1, p2):
    """maximum absolute pixel difference of all channels"""
    rdiff = abs(p1[0] - p2[0])
    gdiff = abs(p1[1] - p2[1])
    bdiff = abs(p1[2] - p2[2])

    diff = max([rdiff, gdiff, bdiff])
    
    return diff

def main(testNumber):

    # open images rendered by test suite
    img1 = Image.open("./{0}/reference.jpg".format(testNumber))
    img2 = Image.open("./{0}/test.jpg".format(testNumber))

    # make sure images are same width and height
    img1w,img1h = img1.size
    img2w,img2h = img2.size

    are_different = False
    if img1w == img2w and img1h == img2h:

        # get pixel difference
        maxdiff = 0
        totaldiff = 0
        for i in xrange(img1w):
            for j in xrange(img1h):
                pix1 = img1.getpixel((i,j))
                pix2 = img2.getpixel((i,j))
                diff = pixeldiff(pix1, pix2)

                if diff > maxdiff:
                    maxdiff = diff

                totaldiff += diff

        # average difference
        nbPixels = img1w * img1h
        avgdiff = float(totaldiff)/nbPixels

        # write a difference image for display in html report
        diffImg = ImageChops.difference(img1, img2)
        diffImg.save("./{0}/diff.jpg".format(testNumber))

        # right now we support up to 1% difference
        # TODO: expose as an optional argument
        if avgdiff > 1.0:
            print("Error: Input images are not the same!")
            are_different = True

    else:   
        print("Error: Input images not the same size!")
        are_different = True

    return are_different
    