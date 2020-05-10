#!/bin/sh

arduino-cli compile --warnings default --fqbn SPRESENSE:spresense:spresense:Core=Main,Debug=Disabled Main
arduino-cli compile --warnings default --fqbn SPRESENSE:spresense:spresense:Core=Sub1,Debug=Disabled IRrecvDumpV2
arduino-cli compile --warnings default --fqbn SPRESENSE:spresense:spresense:Core=Sub2,Debug=Disabled IRsendDemo
