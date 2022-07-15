#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <unordered_map>
#include "customer.h"
#include <vector>
#include <initializer_list>
#include <iostream>
using namespace std;
enum class UpdateRestaurant {
    AddItem,
    UpdateItem
};

enum class OrderStatus {
    Received,
    UnderProcess,
    Dispatched,
    Completed
};

class Restaurant {
    unordered_map<string,double> menu;
    double rating;
    int capacity;
    static int order_count;
    int current_load = 0;
    string id;
public:
    Restaurant(int rating = 1.0) {
        this->rating = rating;
    }

    Restaurant(unordered_map<string,double> menu, int capacity, double rating, string id) {
        this->menu = menu;
        this->rating = rating;
        this->capacity = capacity;
        this->id = id;
    }

    unordered_map<string,double> getMenu() {
        return menu;
    }

    void setRestaurantID(string id) {
        this->id = id;
    }

    string getRestaurantID() {
        return id;
    }

    void addorUpdateItem(string item, double price) {
        menu[item] = price;
    }

    bool getOrderBill(std::initializer_list<pair<string,int>> items, double& bill) {
        string curItem;
        double quantity;
        for(auto& item : items) {
            curItem = item.first;
            quantity = item.second;
            if(!menu.count(curItem)) {
                bill =  0.0;
                return false;
            }
            bill += menu[curItem]*quantity;
        }
        return true;
    }

    double getRestaurantRating() {
        return rating;
    }

    bool incrementLoad() {
//        cout << "Restaurant = " << this->getRestaurantID() << ", capacity = " << capacity << endl;
        if(current_load < capacity)
            current_load++;
        else
            return false;
        return true;
    }

    void decrementLoad() {
        if(current_load > 0)
            current_load--;
    }
};

int Restaurant::order_count = 0;
#endif // RESTAURANT_H
