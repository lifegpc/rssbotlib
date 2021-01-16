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
    std::list<StreamInfo> streamList;
    for (; i < pFormatContext->nb_streams; i++) {
        AVStream* stream = pFormatContext->streams[i];
        AVCodecParameters* para = stream->codecpar;
        StreamInfo info;
        info.originCodecID = para->codec_id;
        info.originMediaType = para->codec_type;
        info.codecID = avcodecid2streamType(para->codec_id);
        info.mediaType = avmediatype2mediaType(para->codec_type);
        info.bitsPerCodedSample = para->bits_per_coded_sample;
        info.bitsPerRawSample = para->bits_per_raw_sample;
        info.bitRate = para->bit_rate;
        info.profile = para->profile;
        info.level = para->level;
        if (para->codec_type == AVMEDIA_TYPE_VIDEO) {
            info.width = para->width;
            info.height = para->height;
        } else if (para->codec_type == AVMEDIA_TYPE_AUDIO) {
            info.channels = para->channels;
            info.sampleRate = para->sample_rate;
        }
        streamList.push_back(info);
    }
    re.stream_list = listToPointer(streamList, re.stream_list_length);
    re.get_stream_info_ok = true;
    avformat_close_input(&pFormatContext);
    avformat_free_context(pFormatContext);
    return re;
}
