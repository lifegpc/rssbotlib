#include "build.h"
extern "C" {
#define __STDC_CONSTANT_MACROS
#include "../thirdparty/ffmpeg/libavutil/avutil.h"
#include "../thirdparty/ffmpeg/libavutil/dict.h"
#include "../thirdparty/ffmpeg/libavcodec/avcodec.h"
#include "../thirdparty/ffmpeg/libavformat/avformat.h"
}

struct BasicInfo {
    bool ok = false;
    int64_t duration = -1;
    int64_t bit_rate = -1;
    bool has_h264 = false;
    bool has_aac = false;
    const char* mime_type = NULL;
    const char* type_long_name = NULL;
    const char* type_name = NULL;
    uint16_t video_stream_count = 0;
    uint16_t audio_stream_count = 0;
    uint16_t subtitle_stream_count = 0;
    int width = 0;
    int height = 0;
    bool get_stream_info_ok = false;
};

extern "C" LIB_CLASS BasicInfo getBasicInfo(const char* url);
