#ifndef RIDEMANAGER_H
#define RIDEMANAGER_H

#include "user.h"
#include "ride.h"
#include "RideStrategy.h"
#include <map>
#include <mutex>
#include <list>
#include <iostream>
using namespace std;

class RideManager {
    map<string, User> nameToUserMap;
    map<string, pair<int,int> > userStats;
    list<Ride> rides;

    RideManager() = default;
    RideManager(const RideManager&);
    RideManager operator=(const RideManager&);

    static int count;
    static RideManager* driver;
    static mutex mtx;

public:
    static RideManager* getInstance() {
        if(driver == nullptr) {
            mtx.lock();
            if(driver == nullptr) {
                driver = new RideManager();
            }
            mtx.unlock();
        }
        return driver;
    }

    list<Ride>& getRides() {
        return rides;
    }

    void add_user(string name, char sex, int age) {
        nameToUserMap[name] = User(name, sex, age);
        cout << "User " << name << " added" << endl;
    }

    void add_vehicle(string owner, string vehicleName, string vehicleNumber) {
        nameToUserMap[owner].setVehicle(Vehicle(vehicleName, vehicleNumber));
        cout << "Vehicle " << vehicleName << "(" << vehicleNumber << ") assigned to " << owner << endl;
    }

    //returns ride number which will be used by end_ride()
    string offer_ride(string owner, string source, int availableSeats, string vehicleName, string vehicleNumber, string destination) {
        string id = "2-";
        id.push_back(static_cast<char>(count + 'a'));
        count++;

        if(vehicleAlreadyOccupied(vehicleName, vehicleNumber))
            return "-1";

        userStats[owner].first++;
        cout << "Created ride : " << id << endl;
        Ride newRide = Ride(owner, source, availableSeats, Vehicle(vehicleName, vehicleNumber), destination);
        newRide.setId(id);
        newRide.getVehicle().setIsFree(false);
        rides.push_back(newRide);

        return id;
    }

    void select_ride(string taker, RideStrategy* strategy) {
        string rideId = strategy->getMatchingRide();
        if(rideId.size()) {
            cout << rideId << " is the desired output" << endl;
            userStats[taker].second++;
            return;
        }

        cout << "No rides found" << endl;
    }

    void end_ride(string id) {
        for(auto& r : rides) {
            if(r.getId() == id) {
                r.getVehicle().setIsFree(true);
            }
        }
    }

    bool vehicleAlreadyOccupied(string vehicleName, string vehicleNumber) {
        for(auto& r : rides) {
            if(r.getVehicle().getName() == vehicleName and r.getVehicle().getVehicleNumber() == vehicleNumber
               and !r.getVehicle().getIsFree())
                return true;
            else
                break;
        }
        return false;
    }

    void print_ride_stats() {
        for(auto& p : userStats) {
            cout << p.first << ": " << p.second.first << " Offered, " << p.second.second << " Taken" << endl;
        }
    }
};

#endif // RIDEMANAGER_H
