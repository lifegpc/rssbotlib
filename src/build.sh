cd main
includePath=-I../thirdparty/ffmpeg
g++ $includePath -shared -c getdur.cpp
TEMP_PKG_CONFIG_PATH=$PKG_CONFIG_PATH
export PKG_CONFIG_PATH=pkgconfig/:$PKG_CONFIG_PATH
libavformat=$(pkg-config --libs libavformat)
export PKG_CONFIG_PATH=$TEMP_PKG_CONFIG_PATH
g++ -shared -o rssbot.dll getdur.o $libavformat
