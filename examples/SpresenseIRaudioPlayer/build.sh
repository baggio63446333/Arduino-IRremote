#!/bin/sh

arduino-cli compile --warnings default --fqbn SPRESENSE:spresense:spresense:Core=Main,Debug=Disabled player_playlist_remocon
arduino-cli compile --warnings default --fqbn SPRESENSE:spresense:spresense:Core=Sub1,Debug=Disabled player_playlist_remocon/IRrecvSub
