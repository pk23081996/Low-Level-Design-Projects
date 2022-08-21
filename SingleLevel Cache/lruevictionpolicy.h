#ifndef LRUEVICTIONPOLICY_H
#define LRUEVICTIONPOLICY_H
#include <list>
#include <map>
#include <unordered_map>
#include "evictionpolicy.h"
#include "elementnotfoundexception.h"
using namespace std;

template <typename Key>
class LRUEvictionPolicy : public EvictionPolicy<Key>
{
    list<Key> lru;
    unordered_map<Key, typename list<Key>::iterator > mp;
public:
    LRUEvictionPolicy() {};

    void keyAccessed(Key key) {
        if(mp.count(key)) {
            lru.erase(mp[key]);
        }
        lru.push_front(key);
        mp[key] = lru.begin();
    }

    Key evictKey() {
        if(!lru.empty()) {
            Key key = lru.back();
            mp.erase(key);
            lru.pop_back();
            return key;
        } else {
            throw ElementNotFoundException();
        }
    }
};

//template class LRUEvictionPolicy<string>;
#endif // LRUEVICTIONPOLICY_H
