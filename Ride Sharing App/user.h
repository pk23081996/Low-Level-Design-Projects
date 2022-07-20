#ifndef USER_H
#define USER_H

#include "vehicle.h"
#include <iostream>

class User
{
    string name;
    char sex;
    int age;
    Vehicle vehicle;

public:
    User(string name, char sex, int age);
    User() = default;
    const string &getName() const;
    void setName(const string &newName);
    const Vehicle &getVehicle() const;
    void setVehicle(const Vehicle &newVehicle);
};

#endif // USER_H
