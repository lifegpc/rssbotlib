#include "build.h"
#include "listtopointer.h"

extern "C" LIB_CLASS int* version() {
    const std::list<int> l = { 1, 0, 0, 0 };
    size_t _;
    return listToPointer(l, _);
}
