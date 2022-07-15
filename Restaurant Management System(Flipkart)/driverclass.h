#ifndef DRIVERCLASS_H
#define DRIVERCLASS_H
#include "restaurant.h"
#include "customer.h"
#include "order.h"
#include "OrderPlacingStrategy.h"
#include "HighestRatingStrategy.h"
#include "LowestCostStrategy.h"
#include <iostream>
#include <initializer_list>
#include <set>
#include<list>
#include<map>

enum class OrderSelectionCriteria {
    Max_Rating,
    Lowest_Cost
};

class DriverClass
{
    vector<Restaurant*> restaurants;
    map<string, Restaurant*> restaurantIdToRestaurantMap;
    list<Order*> orders;
    map<string, Order*> orderIdToOrderMap;
    OrderPlacingStrategy* orderPlacingStrategy;
    static int s_restaurantCount;
    static int s_orderCount;
public:
    DriverClass() {
        cout << "Driver created" << endl;
    }
    void showAvailableItems() {
        cout << "*************      Menu     *************";
        for(auto r : restaurants) {
            cout << "\nRestaurant : " << r->getRestaurantID() << endl;
            for(auto& p : r->getMenu()) {
                cout << p.first << " : " << p.second << endl;
            }
        }
    }

    void registerRestaurant(int capacity, unordered_map<string,double> menu, double rating) {
        string id = "R" + to_string(s_restaurantCount++);
        restaurants.push_back(new Restaurant(menu,capacity,rating,id));
        restaurantIdToRestaurantMap[id] = restaurants.back();
    }

    void updateRestaurantMenu(string id, UpdateRestaurant type, string item, double price) {
        if(type == UpdateRestaurant::AddItem) {
            restaurantIdToRestaurantMap[id]->addorUpdateItem(item, price);
        } else if(type == UpdateRestaurant::UpdateItem) {
            restaurantIdToRestaurantMap[id]->addorUpdateItem(item, price);
        }
        showAvailableItems();
        cout << endl;
    }

    void placeOrder(const Customer& customer, initializer_list<pair<string,int>> items, OrderSelectionCriteria criteria) {
        if(restaurants.size() == 0) {
            cout << "No restaurants found!!" << endl;
            return;
        }

        Restaurant *selectedRestaurant;
        if(criteria == OrderSelectionCriteria::Lowest_Cost) {
            orderPlacingStrategy = new LowestCostStrategy();
        } else if(criteria == OrderSelectionCriteria::Max_Rating) {
            orderPlacingStrategy = new HighestRatingStrategy();
        }
        selectedRestaurant = orderPlacingStrategy->assignOrderToRestaurant(restaurants, items);
        if(!selectedRestaurant) {
            cout << "Order can’t be fulfilled!!!" << endl;
            return;
        }

        if(!selectedRestaurant->incrementLoad()) {
            cout << "Unfortunately, Restaurant " << selectedRestaurant->getRestaurantID() << " is running at full capacity at the moment." << endl;
            cout << "Kindly wait for some time." << endl << endl;
            return;
        }

        cout << "Restaurant selected : " << selectedRestaurant->getRestaurantID() << endl;
        const string& orderId = "Order" + to_string(s_orderCount++);
        cout << "Order ID : " << orderId << endl << endl;
        Order* order = new Order(orderId, customer, selectedRestaurant, OrderStatus::UnderProcess);
        orderIdToOrderMap[orderId] = order;
    }

    void updateOrderStatus(string id, OrderStatus status) {
        orderIdToOrderMap[id]->setOrderStatus(status);
        if(status == OrderStatus::Completed) {
            orderIdToOrderMap[id]->getRestaurant()->decrementLoad();
            cout << "Order " << id << " of Restaurant " << orderIdToOrderMap[id]->getRestaurant()->getRestaurantID() << " completed!" << endl;
        }
    }
};

int DriverClass::s_restaurantCount = 1;
int DriverClass::s_orderCount = 1;
#endif // DRIVERCLASS_H
