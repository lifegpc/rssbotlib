#!/bin/bash
cd thirdparty/ffmpeg
make install
if [ $? -ne 0 ]; then exit 1; fi
cd ../../main/
if test -d pkgconfig
then
    rm -rf pkgconfig
fi
cd ../thirdparty/ffmpeg
mv -f pkgconfig ../../main/
mv -f *.a ../../main/
if [ $? -ne 0 ]; then exit 1; fi
