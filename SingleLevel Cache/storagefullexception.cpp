#include "storagefullexception.h"

const char* StorageFullException::what() const noexcept {
    return string("Storage Full!!").c_str();
}
