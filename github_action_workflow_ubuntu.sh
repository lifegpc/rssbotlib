#!/bin/bash
sudo apt install -y libgnutls28-dev cmake
if [ $? -ne 0 ]; then exit 1; fi
cd src
sudo bash ./configure.sh
if [ $? -ne 0 ]; then exit 1; fi
sudo bash ./build_ffmpeg.sh
if [ $? -ne 0 ]; then exit 1; fi
PKG_CONFIG_PATH="`pwd`/ffmpeg-build/lib/pkgconfig:$PKG_CONFIG_PATH"
cd ..
mkdir -f build
cd build
cmake .. || exit 1
make || exit 1
for i in librssbot*; do echo mv "$i" -v ../"${i:3}"; done
cd ..
7z a -stm1 -y -mx9 release.7z rssbot* LICENSE
