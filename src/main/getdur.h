#include "build.h"
extern "C" {
    #define __STDC_CONSTANT_MACROS
    #include "../thirdparty/ffmpeg/libavutil/avutil.h"
    #include "../thirdparty/ffmpeg/libavutil/dict.h"
    #include "../thirdparty/ffmpeg/libavformat/avformat.h"
}

extern "C" LIB_CLASS int64_t getDur(const char* url);
