#include "ride.h"

Vehicle&Ride::getVehicle()
{
    return vehicle;
}

void Ride::setVehicle(const Vehicle &newVehicle)
{
    vehicle = newVehicle;
}

const string &Ride::getSource() const
{
    return source;
}

void Ride::setSource(const string &newSource)
{
    source = newSource;
}

const string &Ride::getDestination() const
{
    return destination;
}

void Ride::setDestination(const string &newDestination)
{
    destination = newDestination;
}

int Ride::getAvailableSeats() const
{
    return availableSeats;
}

void Ride::setAvailableSeats(int newAvailableSeats)
{
    availableSeats = newAvailableSeats;
}

const string &Ride::getRideOfferer() const
{
    return rideOfferer;
}

void Ride::setRideOfferer(const string &newRideOfferer)
{
    rideOfferer = newRideOfferer;
}

Ride::Ride(std::string owner, std::string source, int seats, Vehicle v, std::string destination) : vehicle(v)
{
    this->rideOfferer = owner;
    this->source = source;
    this->availableSeats = seats;
    this->destination = destination;
}

string Ride::getId() {
    return id;
}

void Ride::setId(string id) {
    this->id = id;
}
