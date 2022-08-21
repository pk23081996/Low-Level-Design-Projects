#ifndef CACHESERVICE_H
#define CACHESERVICE_H
#include <iostream>
#include "lruevictionpolicy.h"
#include "hashmapbasedstorage.h"

template <class Key, class Value>
class CacheService
{
    LRUEvictionPolicy<Key> evictionPolicy;
    HashMapBasedStorage<Key, Value> storage;
public:
    string name;
    CacheService() = default;
    CacheService(LRUEvictionPolicy<Key> evictionPolicy, HashMapBasedStorage<Key, Value> storage, string name="C0") {
        this->evictionPolicy = evictionPolicy;
        this->storage = storage;
        this->name = name;
    }

    void put(Key key, Value val) {
        try {
            storage.set(key,val);
            evictionPolicy.keyAccessed(key);
        } catch (StorageFullException) {
            cout << "Storage is full\n";
            try {
                Key keyToRemove = evictionPolicy.evictKey();
                storage.remove(keyToRemove);
                put(key, val);
                cout << "Removing key : " << keyToRemove << endl;
            } catch (...) {
                cout << "Could not evict key!" << endl;
            }
        }
    }

    Value get(Key key) {
        try {
            Value val = storage.get(key);
            evictionPolicy.keyAccessed(key);
            cout << "Inside get, returning : " << val << endl;
            return val;
        } catch (ElementNotFoundException& e) {
            cout << "Exception occured!! " << e.what() << endl;
            throw e;
        }
    }

    void remove(Key key) {
        //put in catch
        storage.remove(key);
    }

    double getCurrentUsage() {
        return storage.getCurrentUsage();
    }
};

#endif // CACHESERVICE_H
