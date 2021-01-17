#!/bin/bash
apt install -y libgnutls30
if [ $? -ne 0 ]; then exit 1; fi
cd src
./configure.sh
if [ $? -ne 0 ]; then exit 1; fi
./build_ffmpeg.sh
if [ $? -ne 0 ]; then exit 1; fi
./build.sh
if [ $? -ne 0 ]; then exit 1; fi
