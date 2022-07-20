#include "mostvacantstrategy.h"
#include "RideManager.h"

MostVacantStrategy::MostVacantStrategy(string source, string destination, int seatsRequired)
{
    this->source = source;
    this->destination = destination;
    this->seatsRequired = seatsRequired;
}

string MostVacantStrategy::getMatchingRide() {
    string res;
    int maxSeats = 0;
    for(auto& ride : RideManager::getInstance()->getRides()) {
        if(source == ride.getSource() and
           destination == ride.getDestination() and
           ride.getAvailableSeats() >= seatsRequired) {

            if(ride.getAvailableSeats() > maxSeats) {
                maxSeats = ride.getAvailableSeats();
                res = ride.getId();
            }
        }
    }
    return res;
}
