#ifndef PREFFEREDVEHICLESTRATEGY_H
#define PREFFEREDVEHICLESTRATEGY_H

#include "RideStrategy.h"
#include "RideManager.h"

class PrefferedVehicleStrategy : public RideStrategy
{
    string source;
    string destination;
    int seatsRequired;
    string prefferedVehicle;

public:
    PrefferedVehicleStrategy(string source, string destination, int seatsRequired, string vehicle);

    // RideStrategy interface
public:
    string getMatchingRide();
};

#endif // PREFFEREDVEHICLESTRATEGY_H
