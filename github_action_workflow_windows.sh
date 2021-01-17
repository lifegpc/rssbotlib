#!/bin/bash
cd src
./configure.sh
if [ $? -ne 0 ]; then exit 1; fi
./build_ffmpeg.sh
if [ $? -ne 0 ]; then exit 1; fi
./build.sh
if [ $? -ne 0 ]; then exit 1; fi
7z a -stm1 -y -mx9 ../release.7z main/rssbot.dll
if [ $? -ne 0 ]; then exit 1; fi
