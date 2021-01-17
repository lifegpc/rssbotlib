#!/bin/bash
pacman --noconfirm --needed -S mingw64/mingw-w64-x86_64-gcc
if [ $? -ne 0 ]; then exit 1; fi
pacman --noconfirm --needed -S mingw64/mingw-w64-x86_64-gnutls
if [ $? -ne 0 ]; then exit 1; fi
pacman --noconfirm --needed -S msys/p7zip
if [ $? -ne 0 ]; then exit 1; fi
cd src
./configure.sh
if [ $? -ne 0 ]; then exit 1; fi
./build_ffmpeg.sh
if [ $? -ne 0 ]; then exit 1; fi
./build.sh
if [ $? -ne 0 ]; then exit 1; fi
7z a -stm1 -y -mx9 ../release.7z main/rssbot.dll
if [ $? -ne 0 ]; then exit 1; fi
