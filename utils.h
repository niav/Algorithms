#ifndef _UTILS_H
#define _UTILS_H

#include <utility>// for std::move
#include <chrono> // for std::chrono
#include <string>
#include <random>
#include <iostream>
#include <unistd.h> //sleep -temporary solution

namespace chrono {
    using namespace std::chrono;
    using clock_t = high_resolution_clock;
    using second_t = duration<double, std::ratio<1> >;

    class Timer {
    private:
        time_point<clock_t> m_beg;

    public:
        Timer() : m_beg(clock_t::now()) {
        }

        void reset() {
            m_beg = clock_t::now();
        }

        double elapsed() const {
            return duration_cast<second_t>(clock_t::now() - m_beg).count();
        }
    };
}//chrono

const std::string makeRandomString(size_t size);

template<typename T>
void swap(T &x, T &y) {
    T temp{std::move(x)};
    x = y;
    y = temp;
}

#endif //_UTILS_H
