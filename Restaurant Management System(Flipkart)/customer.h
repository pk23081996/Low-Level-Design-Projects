#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;

class Customer
{
    string name;
public:
    Customer(string name = "") {
        this->name = name;
    }
};

#endif // CUSTOMER_H
