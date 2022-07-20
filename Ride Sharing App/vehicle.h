#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>
using std::string;

class Vehicle
{
    string name;
    string vehicleNumber;
    bool isFree;

public:
    Vehicle(string name, string vehicleNumber);
    Vehicle() { isFree = true; }
    const string &getName();
    void setName(const string &newName);
    const string &getVehicleNumber();
    void setVehicleNumber(const string &newVehicleNumber);
    void setIsFree(bool status) { isFree = status;}
    bool getIsFree() const { return isFree;}
};

#endif // VEHICLE_H
