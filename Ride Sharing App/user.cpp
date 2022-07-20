#include "user.h"

const string &User::getName() const
{
    return name;
}

void User::setName(const string &newName)
{
    name = newName;
}

const Vehicle &User::getVehicle() const
{
    return vehicle;
}

void User::setVehicle(const Vehicle &newVehicle)
{
    vehicle = newVehicle;
}

User::User(string name, char sex, int age) : name(name), sex(sex), age(age)
{
}
