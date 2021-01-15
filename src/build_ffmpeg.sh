cd thirdparty/ffmpeg
make install
cd ../../main/
if test -d pkgconfig
then
    rm -rfv pkgconfig
fi
cd ../thirdparty/ffmpeg
mv -f pkgconfig ../../main/
mv -f *.a ../../main/
