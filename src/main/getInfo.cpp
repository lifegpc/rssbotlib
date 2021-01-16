#include "getInfo.h"
#include "listtopointer.h"

extern "C" LIB_CLASS const char* getProfileName(int codecId, int profile) {
    AVCodecID c = static_cast<AVCodecID>(codecId);
    return avcodec_profile_name(c, profile);
}

extern "C" LIB_CLASS const char* getCodecName(int codecId) {
    AVCodecID c = static_cast<AVCodecID>(codecId);
    return avcodec_get_name(c);
}

extern "C" LIB_CLASS const char* getCodecDescription(int codecId) {
    AVCodecID c = static_cast<AVCodecID>(codecId);
    const AVCodecDescriptor* d(avcodec_descriptor_get(c));
    if (d == NULL) return NULL;
    return d->long_name;
}

extern "C" LIB_CLASS const char** getCodecMimeType(int codecId, std::size_t * len) {
    AVCodecID c = static_cast<AVCodecID>(codecId);
    const AVCodecDescriptor* d(avcodec_descriptor_get(c));
    if (d == NULL || d->mime_types == NULL) {
        if (len != NULL) *len = 0;
        return NULL;
    }
    std::list<const char*> l;
    std::size_t i = 0;
    while (d->mime_types[i] != NULL) {
        l.push_back(d->mime_types[i]);
        i++;
    }
    if (l.size() == 0) {
        if (len != NULL) *len = 0;
        return NULL;
    }
    std::size_t le = 0;
    const char** r = listToPointer(l, le);
    if (len != NULL) *len = le;
    return r;
}
