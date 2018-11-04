#ifndef _UTILS_H
#define _UTILS_H

#include <utility>

template<typename T>
void swap(T &x, T &y) {
    T temp{std::move(x)};
    x = y;
    y = temp;
}

#endif //_UTILS_H
