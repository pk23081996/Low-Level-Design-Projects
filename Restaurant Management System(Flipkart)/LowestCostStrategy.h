#ifndef LOWESTCOSTSTRATEGY_H
#define LOWESTCOSTSTRATEGY_H

#include <QtGlobal>
#include "OrderPlacingStrategy.h"
#include "restaurant.h"
class LowestCostStrategy : public OrderPlacingStrategy {
public:
    Restaurant* assignOrderToRestaurant(const vector<Restaurant*>& restaurants, const initializer_list<pair<string,int>>& items) {
        Restaurant* selectedRestaurant = nullptr;
        double minBill = INT_MAX;
        for(auto& r : restaurants) {
            double billForCurrentRestaurant = 0.0;
            bool canFulfilOrder = r->getOrderBill(items, billForCurrentRestaurant);
            if(canFulfilOrder) {
                if(billForCurrentRestaurant < minBill) {
                    minBill = billForCurrentRestaurant;
                    selectedRestaurant = r;
                }
            }
        }
        return selectedRestaurant;
    }
};

#endif // LOWESTCOSTSTRATEGY_H
