#include "prefferedvehiclestrategy.h"
#include <iostream>
using namespace std;

PrefferedVehicleStrategy::PrefferedVehicleStrategy(string source, string destination, int seatsRequired, string vehicle)
{
    this->source = source;
    this->destination = destination;
    this->seatsRequired = seatsRequired;
    this->prefferedVehicle = vehicle;
}

string PrefferedVehicleStrategy::getMatchingRide() {
    string res;
    for(auto& ride : RideManager::getInstance()->getRides()) {
        if(source == ride.getSource() and
           destination == ride.getDestination() and
           seatsRequired <= ride.getAvailableSeats()) {

           if(ride.getVehicle().getName() == prefferedVehicle) {
                res = ride.getId();
                break;
           }
        }
    }
    return res;
}
