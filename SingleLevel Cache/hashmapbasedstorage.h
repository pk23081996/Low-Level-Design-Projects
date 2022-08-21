#ifndef HASHMAPBASEDSTORAGE_H
#define HASHMAPBASEDSTORAGE_H
#include "storage.h"
#include "storagefullexception.h"
#include "elementnotfoundexception.h"
#include <unordered_map>
#include <iostream>
using namespace std;

template <class Key, class Value>
class HashMapBasedStorage : public Storage<Key,Value>
{
    unordered_map<Key, Value> storage;
    const unsigned int capacity;
public:
    HashMapBasedStorage() = default;
    HashMapBasedStorage(unsigned int capacity) : capacity(capacity) { }

    bool isStorageFull() {
        return capacity == storage.size();
    }

    void set(Key key, Value value) {
        if(storage.count(key) == 0 and isStorageFull()) {
            cout << "Storage full!!!\n";
            StorageFullException obj;
            throw obj;
        } else {
            storage[key] = value;
        }
    }

    Value get(Key key) {
        if(storage.count(key)) {
            return storage[key];
        } else {
            ElementNotFoundException obj;
            cout << "Element " << key << " not found in Value get\n";
            throw obj;
        }
    }

    void remove(Key key) {
        cout << "Before count " << storage.count(key) << endl;
        if(storage.count(key)) {
            storage.erase(key);
        } else {
            std::cout << "Key : " << key << " does not exist" << std::endl;
            throw ElementNotFoundException();
        }
        cout << "After count " << storage.count(key) << endl;
    }

    double getCurrentUsage() {
        return ((double) storage.size()) / ((double) capacity);
    }
};
#endif // HASHMAPBASEDSTORAGE_H
