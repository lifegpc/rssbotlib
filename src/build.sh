cd main
includePath=-I../thirdparty/ffmpeg
GPP=g++ -fPIC -shared
$GPP $includePath -c getdur.cpp
TEMP_PKG_CONFIG_PATH=$PKG_CONFIG_PATH
export PKG_CONFIG_PATH=pkgconfig/:$PKG_CONFIG_PATH
libavformat=$(pkg-config --libs libavformat)
export PKG_CONFIG_PATH=$TEMP_PKG_CONFIG_PATH
case "$OSTYPE" in 
    linux*) OUTPUT_DLL=rssbot.so;;
    *) OUTPUT_DLL=rssbot.dll;;
esac
$GPP -shared -o $OUTPUT_DLL getdur.o $libavformat
