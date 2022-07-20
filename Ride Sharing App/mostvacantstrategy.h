#ifndef MOSTVACANTSTRATEGY_H
#define MOSTVACANTSTRATEGY_H

#include "RideStrategy.h"

class MostVacantStrategy : public RideStrategy
{
    string source;
    string destination;
    int seatsRequired;

public:
    MostVacantStrategy(string source, string destination, int seatsRequired);

    // RideStrategy interface
public:
    string getMatchingRide();

};

#endif // MOSTVACANTSTRATEGY_H
