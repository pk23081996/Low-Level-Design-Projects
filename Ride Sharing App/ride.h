#ifndef RIDE_H
#define RIDE_H

#include "vehicle.h"

class Ride
{
    Vehicle vehicle;
    string source, destination;
    int availableSeats;
    string rideOfferer;
    string id;

public:
    Ride(string owner, string source, int seats, Vehicle v, string destination);
    Vehicle &getVehicle();
    void setVehicle(const Vehicle &newVehicle);
    const string &getSource() const;
    void setSource(const string &newSource);
    const string &getDestination() const;
    void setDestination(const string &newDestination);
    int getAvailableSeats() const;
    void setAvailableSeats(int newAvailableSeats);
    const string &getRideOfferer() const;
    void setRideOfferer(const string &newRideOfferer);
    void setId(string id);
    string getId();
};

#endif // RIDE_H
