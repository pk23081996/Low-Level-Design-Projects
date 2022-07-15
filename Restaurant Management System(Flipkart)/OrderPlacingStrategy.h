#ifndef ORDERPLACINGSTRATEGY_H
#define ORDERPLACINGSTRATEGY_H

#include<vector>
#include<initializer_list>
#include<string>
using namespace std;

class Restaurant;
class OrderPlacingStrategy {
public:
    virtual Restaurant* assignOrderToRestaurant(const vector<Restaurant*>& restaurants, const initializer_list<pair<string,int>>& items) = 0;
};

#endif // ORDERPLACINGSTRATEGY_H
