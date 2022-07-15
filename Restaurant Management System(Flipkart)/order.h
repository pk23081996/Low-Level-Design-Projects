#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "restaurant.h"
#include "customer.h"
using namespace std;

class Order
{
    string OrderId;
    Customer customer;
    Restaurant* restaurant;
    OrderStatus status;

public:
    Order() = default;

    Order(const string &OrderId, const Customer &customer, Restaurant *restaurant, OrderStatus status) {
        this->OrderId = OrderId;
        this->customer = customer;
        this->restaurant = restaurant;
        this->status = status;
    }

//    Order(OrderStatus status) {
//        this->status = status;
//    }


    void setOrderID(string id) {
        this->OrderId = id;
    }

    void setCustomer(Customer c) { customer = c;}
    void setRestaurant(Restaurant* r) { restaurant = r;}

    void setOrderStatus(OrderStatus status) {
        this->status = status;
    }

    Restaurant* getRestaurant() {
        return restaurant;
    }
};

#endif // ORDER_H
