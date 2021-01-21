#include "build.h"
extern "C" {
#include "libavformat/avformat.h"
}
#include <list>

extern "C" LIB_CLASS const char* getProfileName(int codecId, int profile);
extern "C" LIB_CLASS const char* getCodecName(int codecId);
extern "C" LIB_CLASS const char* getCodecDescription(int codecId);
extern "C" LIB_CLASS const char** getCodecMimeType(int codecId, std::size_t * len);
extern "C" LIB_CLASS int getAVTIMEBASE();
