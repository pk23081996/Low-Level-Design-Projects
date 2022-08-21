#ifndef MULTILEVELCACHESERVICEDRIVER_H
#define MULTILEVELCACHESERVICEDRIVER_H
#include "DefaultLevelCache.h"
#include "LevelCacheInterface.h"
#include "../SingleLevelCache/cacheservice.h"
#include "StatsResponse.h"
#include <queue>
#include <numeric>
using namespace std;

template <class Key, class Value>
class MultiLevelCacheServiceDriver {
    DefaultLevelCache<Key,Value>* multiLevelCache;
    vector<double> readTimes;
    vector<double> writeTimes;
    const int lastCount;
public:
    MultiLevelCacheServiceDriver(DefaultLevelCache<Key,Value>* multiLevelCache, int lastCount) :
        lastCount(lastCount),
        multiLevelCache(multiLevelCache)
    {

    }

    void addTimes(vector<double>& times, double time) {
        if(times.size() == lastCount) {
            std::reverse(times.begin(), times.end());
            times.pop_back();
            std::reverse(times.begin(), times.end());
        } //list.pop_front will do

        times.push_back(time);
    }

    WriteResponse set(Key key, Value val) {
        WriteResponse* writeResponse = multiLevelCache->set(key,val);
        addTimes(writeTimes, writeResponse->getTimeTaken());
        return *writeResponse;
    }

    ReadResponse<Value> get(Key key) {
        ReadResponse<Value>* readResponse = nullptr;
        try {
            readResponse = multiLevelCache->get(key);
        } catch(...) {
            cout << "\nCame here FELLA\n";
        }
        if(readResponse)
            addTimes(readTimes, readResponse->getReadTime());
        else
            cout << endl << " Not there :(\n";
        return *readResponse;
    }

    double getSum(vector<double> times) {
        cout << "Res 1 : " << std::accumulate(times.begin(), times.end(), 0.0) << endl;
        double sum = 0.0;
        for (double time: times) {
            sum += time;
        }
        return sum;
    }

    double getAvgReadTime() {
        return getSum(readTimes)/readTimes.size();
    }

    double getAvgWriteTime() {
        return getSum(writeTimes)/writeTimes.size();
    }

    StatsResponse stats() {
        StatsResponse obj(getAvgReadTime(),getAvgWriteTime(), multiLevelCache->getUsages());
        return obj;
    }

};

#endif // MULTILEVELCACHESERVICEDRIVER_H
