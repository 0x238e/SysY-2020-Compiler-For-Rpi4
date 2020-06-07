#!/bin/sh

# Only check for validity, generated bject file is of little interest
arm-linux-gnueabihf-as -march=arm -mcpu=cortex-a9 $@