#include "utils.h"

const std::string makeRandomString(const size_t size) {//all symbols are in lowercase
    std::string sString;
    sString.reserve(size);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    std::uniform_int_distribution<int> distribution(97, 122);
    sleep(distribution(generator) / 100);
    for (int i = 0; i < size; ++i) {
        sString += static_cast<char>(distribution(generator));
    }
    return sString;
}
