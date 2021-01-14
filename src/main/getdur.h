#include "build.h"
extern "C" {
    #include "../thirdparty/ffmpeg/libavformat/avformat.h"
}

extern "C" LIB_CLASS int64_t __cdecl getDur(const char* url);
