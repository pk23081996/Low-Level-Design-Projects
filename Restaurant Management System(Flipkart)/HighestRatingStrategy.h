#ifndef HIGHESTRATINGSTRATEGY_H
#define HIGHESTRATINGSTRATEGY_H

#include <QtGlobal>
#include "OrderPlacingStrategy.h"
#include "restaurant.h"

class HighestRatingStrategy : public OrderPlacingStrategy {

public:
    Restaurant *assignOrderToRestaurant(const std::__1::vector<Restaurant *>& restaurants, const std::initializer_list<std::__1::pair<string, int>>& items) {
        Restaurant* selectedRestaurant = nullptr;
        int maxRating = -1;
        double billForCurrentRestaurant = 0.0;
        for(auto& r : restaurants) {
            bool canFulfilOrder = r->getOrderBill(items, billForCurrentRestaurant);
            if(canFulfilOrder) {
                double rating = r->getRestaurantRating();
                if(rating > maxRating) {
                    maxRating = rating;
                    selectedRestaurant = r;
                }
            }
        }
        return selectedRestaurant;
    }
};

#endif // HIGHESTRATINGSTRATEGY_H
