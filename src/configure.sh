#!/bin/bash
pre=`pwd`/ffmpeg-build
cd thirdparty/ffmpeg
./configure --enable-gpl --enable-version3 --prefix=$pre --disable-programs --disable-encoders \
--disable-asm --disable-decoders --disable-hwaccels --disable-muxers --disable-bsfs \
--disable-devices --disable-filters --enable-gnutls --enable-muxer=mp4 --enable-muxer=matroska \
--enable-small $EXTRA_CONFIG
if [ $? -ne 0 ]; then exit 1; fi
