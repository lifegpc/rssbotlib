#!/bin/bash
cd thirdparty/ffmpeg
make install
if [ $? -ne 0 ]; then exit 1; fi
