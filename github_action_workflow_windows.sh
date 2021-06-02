#!/bin/bash
SETUPFLAGS="--noconfirm --overwrite '*'"
GNUTLS=gnutls.pkg.tar.zst
curl "https://github.com/lifegpc/static-mingw-w64-gnutls/releases/download/3.7.1-1/mingw-w64-x86_64-gnutls-3.7.1-1-any.pkg.tar.zst" -o $GNUTLS -L || exit 1
pacman -U $GNUTLS $SETUPFLAGS || exit 1
EXTRA_CONFIG='--extra-ldflags=-static --pkg-config-flags=--static'
cd src
./configure.sh
if [ $? -ne 0 ]; then exit 1; fi
./build_ffmpeg.sh
if [ $? -ne 0 ]; then exit 1; fi
PKG_CONFIG_PATH="`pwd`/ffmpeg-build/lib/pkgconfig:$PKG_CONFIG_PATH"
cd ..
mkdir -f build
cd build
cmake -G "MSYS Makefiles" .. || exit 1
make || exit 1
for i in librssbot*; do echo mv "$i" -v ../"${i:3}"; done
cd ..
7z a -stm1 -y -mx9 release.7z rssbot* LICENSE
