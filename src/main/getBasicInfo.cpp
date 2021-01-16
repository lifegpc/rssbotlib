#include "getBasicInfo.h"
#include "listtopointer.h"

extern "C" LIB_CLASS BasicInfo getBasicInfo(const char* url) {
    BasicInfo re;
    AVFormatContext* pFormatContext = avformat_alloc_context();
    if (avformat_open_input(&pFormatContext, url, NULL, NULL)) {
        avformat_free_context(pFormatContext);
        return BasicInfo();
    }
    re.duration = pFormatContext->duration;
    re.bit_rate = pFormatContext->bit_rate;
    re.mime_type = pFormatContext->iformat->mime_type;
    re.type_long_name = pFormatContext->iformat->long_name;
    re.type_name = pFormatContext->iformat->name;
    re.ok = true;
    if (avformat_find_stream_info(pFormatContext, NULL) < 0) {
        avformat_close_input(&pFormatContext);
        avformat_free_context(pFormatContext);
        return re;
    }
    unsigned int i = 0;
    for (; i < pFormatContext->nb_streams; i++) {
        AVStream* stream = pFormatContext->streams[i];
        AVCodecParameters* para = stream->codecpar;
        if (para->codec_type == AVMEDIA_TYPE_VIDEO) {
            re.video_stream_count++;
            if (re.video_stream_count == 1) {
                re.width = para->width;
                re.height = para->height;
            }
            if (para->codec_id == AV_CODEC_ID_H264) {
                re.has_h264 = true;
            }
        } else if (para->codec_type == AVMEDIA_TYPE_AUDIO) {
            re.audio_stream_count++;
            if (para->codec_id == AV_CODEC_ID_AAC || para->codec_id == AV_CODEC_ID_AAC_LATM) {
                re.has_aac = true;
            }
        } else if (para->codec_type == AVMEDIA_TYPE_SUBTITLE) {
            re.subtitle_stream_count++;
        }
    }
    re.get_stream_info_ok = true;
    avformat_close_input(&pFormatContext);
    avformat_free_context(pFormatContext);
    return re;
}
