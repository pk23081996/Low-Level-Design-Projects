#ifndef RIDESTRATEGY_H
#define RIDESTRATEGY_H

#include "vehicle.h"
#include "ride.h"

class RideStrategy {
public:
    virtual string getMatchingRide() = 0;
};

#endif // RIDESTRATEGY_H
