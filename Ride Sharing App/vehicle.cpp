#include "vehicle.h"

const string &Vehicle::getName()
{
    return name;
}

void Vehicle::setName(const string &newName)
{
    name = newName;
}

const string &Vehicle::getVehicleNumber()
{
    return vehicleNumber;
}

void Vehicle::setVehicleNumber(const string &newVehicleNumber)
{
    vehicleNumber = newVehicleNumber;
}

Vehicle::Vehicle(std::string name, std::string vehicleNumber) : name(name), vehicleNumber(vehicleNumber)
{
    isFree = true;
}
