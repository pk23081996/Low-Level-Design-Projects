#ifndef LEVELCACHEINTERFACE_H
#define LEVELCACHEINTERFACE_H
#include "WriteResponse.h"
#include "ReadResponse.h"
#include <vector>
using namespace std;

template <class Key, class Value>
class LevelCacheInterface {
public:
    WriteResponse set(Key key, Value value);
    ReadResponse<Value> get(Key key);
    vector<double> getUsages();
};

#endif // LEVELCACHEINTERFACE_H
