#ifndef STORAGEFULLEXCEPTION_H
#define STORAGEFULLEXCEPTION_H
#include <exception>
#include <string>
using namespace std;

class StorageFullException : public std::exception
{
public:
    StorageFullException() = default;
    virtual const char * what() const noexcept override {
        return  "EXCEPTION here. Storage is full";
    }
};

#endif // STORAGEFULLEXCEPTION_H
