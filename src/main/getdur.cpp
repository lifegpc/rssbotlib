#include "getdur.h"

extern "C" LIB_CLASS int64_t getDur(const char *url) {
    AVFormatContext *pFormatContext = avformat_alloc_context();
    if (avformat_open_input(&pFormatContext, url, NULL, NULL)) {
        avformat_free_context(pFormatContext);
        return -1;
    }
    int64_t t = pFormatContext->duration;
    avformat_close_input(&pFormatContext);
    avformat_free_context(pFormatContext);
    return t;
}
