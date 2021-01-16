#include "build.h"
extern "C" {
#include "libavformat/avformat.h"
}
#include "ffmpegtype.h"

struct StreamInfo {
    AVMediaType originMediaType;
    MEDIA_TYPE mediaType;
    AVCodecID originCodecID;
    STREAM_TYPE codecID;
    int64_t bitRate = -1;
    int bitsPerCodedSample = -1;
    int bitsPerRawSample = -1;
    int profile;
    int level;
    int width = -1;
    int height = -1;
    int channels = -1;
    int sampleRate = -1;
};

struct BasicInfo {
    bool ok = false;
    int64_t duration = -1;
    int64_t bit_rate = -1;
    const char* mime_type = NULL;
    const char* type_long_name = NULL;
    const char* type_name = NULL;
    bool get_stream_info_ok = false;
    StreamInfo* stream_list = NULL;
    std::size_t stream_list_length;
};

extern "C" LIB_CLASS BasicInfo getBasicInfo(const char* url);
