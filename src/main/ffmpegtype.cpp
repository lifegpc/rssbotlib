#include "ffmpegtype.h"

STREAM_TYPE avcodecid2streamType(AVCodecID code) {
    if (code >= AV_CODEC_ID_PCM_S16LE && code < AV_CODEC_ID_ADPCM_IMA_QT) return STREAM_TYPE_PCM;
    else if (code >= AV_CODEC_ID_ADPCM_IMA_QT && code < AV_CODEC_ID_AMR_NB) return STREAM_TYPE_ADPCM;
    switch (code) {
    case AV_CODEC_ID_NONE:
        return STREAM_TYPE_NONE;
    case AV_CODEC_ID_MPEG1VIDEO:
        return STREAM_TYPE_MPEG1VIDEO;
    case AV_CODEC_ID_MPEG2VIDEO:
        return STREAM_TYPE_MPEG2VIDEO;
    case AV_CODEC_ID_H261:
        return STREAM_TYPE_H261;
    case AV_CODEC_ID_H263:
    case AV_CODEC_ID_H263I:
    case AV_CODEC_ID_H263P:
        return STREAM_TYPE_H263;
    case AV_CODEC_ID_RV10:
    case AV_CODEC_ID_RV20:
    case AV_CODEC_ID_RV30:
    case AV_CODEC_ID_RV40:
        return STREAM_TYPE_RV;
    case AV_CODEC_ID_MPEG4:
        return STREAM_TYPE_MPEG4;
    case AV_CODEC_ID_RAWVIDEO:
        return STREAM_TYPE_RAWVIDEO;
    case AV_CODEC_ID_MSMPEG4V1:
    case AV_CODEC_ID_MSMPEG4V2:
    case AV_CODEC_ID_MSMPEG4V3:
        return STREAM_TYPE_MSMPEG4;
    case AV_CODEC_ID_WMV1:
    case AV_CODEC_ID_WMV2:
    case AV_CODEC_ID_WMV3:
        return STREAM_TYPE_WMV;
    case AV_CODEC_ID_FLV1:
    case AV_CODEC_ID_FLASHSV:
    case AV_CODEC_ID_FLASHSV2:
        return STREAM_TYPE_FLV;
    case AV_CODEC_ID_H264:
        return STREAM_TYPE_H264;
    case AV_CODEC_ID_VP7:
        return STREAM_TYPE_VP7;
    case AV_CODEC_ID_VP8:
        return STREAM_TYPE_VP8;
    case AV_CODEC_ID_VP9:
        return STREAM_TYPE_VP9;
    case AV_CODEC_ID_HEVC:
        return STREAM_TYPE_HEVC;
    case AV_CODEC_ID_VVC:
        return STREAM_TYPE_VVC;
    case AV_CODEC_ID_MP3:
        return STREAM_TYPE_MP3;
    case AV_CODEC_ID_AAC:
        return STREAM_TYPE_AAC;
    case AV_CODEC_ID_AC3:
        return STREAM_TYPE_AC3;
    case AV_CODEC_ID_DTS:
        return STREAM_TYPE_DTS;
    case AV_CODEC_ID_WMAV1:
    case AV_CODEC_ID_WMAV2:
    case AV_CODEC_ID_WMAPRO:
    case AV_CODEC_ID_WMALOSSLESS:
    case AV_CODEC_ID_WMAVOICE:
        return STREAM_TYPE_WMA;
    case AV_CODEC_ID_FLAC:
        return STREAM_TYPE_FLAC;
    case AV_CODEC_ID_APE:
        return STREAM_TYPE_APE;
    case AV_CODEC_ID_EAC3:
        return STREAM_TYPE_EAC3;
    case AV_CODEC_ID_OPUS:
        return STREAM_TYPE_OPUS;
    case AV_CODEC_ID_DVD_SUBTITLE:
        return STREAM_TYPE_DVD_SUBTITLE;
    case AV_CODEC_ID_TEXT:
        return STREAM_TYPE_TEXT;
    case AV_CODEC_ID_SSA:
    case AV_CODEC_ID_ASS:
        return STREAM_TYPE_ASS;
    case AV_CODEC_ID_MOV_TEXT:
        return STREAM_TYPE_MOV_TEXT;
    case AV_CODEC_ID_HDMV_PGS_SUBTITLE:
        return STREAM_TYPE_HDMV_PGS_SUBTITLE;
    case AV_CODEC_ID_SRT:
    case AV_CODEC_ID_SUBRIP:
        return STREAM_TYPE_SRT;
    case AV_CODEC_ID_MICRODVD:
        return STREAM_TYPE_MICRODVD;
    case AV_CODEC_ID_WEBVTT:
        return STREAM_TYPE_WEBVTT;
    case AV_CODEC_ID_HDMV_TEXT_SUBTITLE:
        return STREAM_TYPE_HDMV_TEXT_SUBTITLE;
    case AV_CODEC_ID_TTML:
        return STREAM_TYPE_TTML;
    default:
        return STREAM_TYPE_UNKNOWN;
    }
}

MEDIA_TYPE avmediatype2mediaType(AVMediaType type) {
    switch (type) {
    case AVMEDIA_TYPE_VIDEO:
        return MEDIA_TYPE_VIDEO;
    case AVMEDIA_TYPE_AUDIO:
        return MEDIA_TYPE_AUDIO;
    case AVMEDIA_TYPE_SUBTITLE:
        return MEDIA_TYPE_SUBTITLE;
    default:
        return MEDIA_TYPE_UNKNOWN;
    }
}
