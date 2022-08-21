#include "elementnotfoundexception.h"

const char* ElementNotFoundException::what() const noexcept {
    return string("Element not there in the cache!!").c_str();
}
