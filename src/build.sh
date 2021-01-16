cd main
includePath=-I../thirdparty/ffmpeg
GPP="g++ -fPIC -shared"
$GPP $includePath -c getBasicInfo.cpp
TEMP_PKG_CONFIG_PATH=$PKG_CONFIG_PATH
export PKG_CONFIG_PATH=pkgconfig/:$PKG_CONFIG_PATH
libavformat=$(pkg-config --libs libavformat)
export PKG_CONFIG_PATH=$TEMP_PKG_CONFIG_PATH
case "$OSTYPE" in 
    linux*) OUTPUT_DLL=rssbot.so;;
    *) OUTPUT_DLL=rssbot.dll;;
esac
$GPP -shared -static-libstdc++ -o $OUTPUT_DLL getBasicInfo.o $libavformat
