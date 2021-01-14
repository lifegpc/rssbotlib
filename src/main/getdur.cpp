#include "getdur.h"
extern "C" {
    #include "../thirdparty/ffmpeg/libavformat/avformat.h"
}
#include "string.h"

extern "C" LIB_CLASS int64_t __cdecl getDur(const char *url) {
    AVFormatContext *pFormatContext = avformat_alloc_context();
    if (avformat_open_input(&pFormatContext, url, NULL, NULL)) {
        avformat_free_context(pFormatContext);
        return -1;
    }
    int64_t t = pFormatContext->duration;
    avformat_free_context(pFormatContext);
    return t;
}
