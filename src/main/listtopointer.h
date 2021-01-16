#include <list>
#include <malloc.h>

template <class T> T* listToPointer(std::list<T> in, std::size_t& le) {
    std::size_t len = in.size();
    le = len <= 0 ? 0 : len;
    if (len <= 0) return NULL;
    T* l = (T*)malloc(sizeof(T) * len);
    auto it = in.begin();
    std::size_t i = 0;
    for (; it != in.end(); ++it, ++i) {
        l[i] = *it;
    }
    return l;
}
