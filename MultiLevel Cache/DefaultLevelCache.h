#ifndef DEFAULTLEVELCACHE_H
#define DEFAULTLEVELCACHE_H
#include "LevelCacheInterface.h"
#include <algorithm>
#include "levelcachedata.h"
#include "../SingleLevelCache/cacheservice.h"
#define watch(x) cout << "Debug : " <<  (#x) << " = " << x << endl

template <class Key, class Value>
class DefaultLevelCache : public LevelCacheInterface<Key,Value> {
    LevelCacheData levelCacheData;
    DefaultLevelCache<Key,Value>* next;
    CacheService<Key, Value>* cacheService;
public:
    DefaultLevelCache(LevelCacheData levelCacheData, CacheService<Key, Value>* cache, DefaultLevelCache<Key,Value>* next = nullptr) {
        this->levelCacheData = levelCacheData;
        this->cacheService = cache;
        this->next = next;
    }

    WriteResponse* set(Key key, Value value) {
        double curTime = 0.0;
        curTime += levelCacheData.getReadTime();
        Value curLevelValue;
        try {
            curLevelValue = cacheService->get(key);
            if(value != curLevelValue) {
                cacheService->put(key,value);
                curTime += levelCacheData.getWriteTime();
            }
        } catch(std::exception& e) {
            cout << "Exception : " << e.what() << endl;
            cacheService->put(key,value);
            curTime += levelCacheData.getWriteTime();
        }

        if(next)
            curTime += next->set(key,value)->getTimeTaken();

        return new WriteResponse(curTime);
    }

    ReadResponse<Value>* get(Key key) {
        double curTime = 0.0;
        curTime += levelCacheData.getReadTime();
        Value curLevelValue = "null";
        try {
            curLevelValue = cacheService->get(key);
        } catch(...) {
            if(next) {
                try {
                    ReadResponse<Value>* nextResponse = next->get(key);
                    curTime += nextResponse->getReadTime();
                    curLevelValue = nextResponse->getValue();
                    if(curLevelValue != "null") {
                        cacheService->put(key, curLevelValue);
                        curTime += levelCacheData.getWriteTime();
                    }
                } catch(...) {
                }
            }
        }

        return new ReadResponse<Value>(curLevelValue,curTime);
    }

    vector<double>* getUsages() {
        vector<double>* usages = new vector<double>;
        if(next) {
            usages = next->getUsages();
        }

        usages->push_back(cacheService->getCurrentUsage());
        std::reverse(usages->begin(), usages->end());
        return usages;
    }
};

#endif // DEFAULTLEVELCACHE_H
