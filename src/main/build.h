#ifndef RSSBOTLIB_BUILD
#define __STDC_CONSTANT_MACROS
#ifdef __WIN32__
#define LIB_CLASS __declspec(dllexport)
#else
#define LIB_CLASS       // Linux & other Unices : leave it blank !
#endif
#define RSSBOTLIB_BUILD
#endif
