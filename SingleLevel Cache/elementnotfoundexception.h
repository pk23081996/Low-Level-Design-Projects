#ifndef ELEMENTNOTFOUNDEXCEPTION_H
#define ELEMENTNOTFOUNDEXCEPTION_H
#include <exception>
#include <string>
using namespace std;

class ElementNotFoundException : public std::exception
{
public:
    ElementNotFoundException() = default; 
    virtual const char * what() const noexcept override {
        return "EXCEPTION here. Element not found";}
};

#endif // ELEMENTNOTFOUNDEXCEPTION_H
