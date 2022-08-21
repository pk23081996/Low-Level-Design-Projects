#include <QCoreApplication>
#include "MultiLevelCacheServiceDriver.h"
#include "../SingleLevelCache/hashmapbasedstorage.h"
#include "../SingleLevelCache/lruevictionpolicy.h"
#include <string>
#include <assert.h>
#include "StatsResponse.h"
using namespace std;

CacheService<string, string>* createCache(int capacity, string name) {
    LRUEvictionPolicy<string>* policy = new LRUEvictionPolicy<string>();
    HashMapBasedStorage<string, string>* storage =
                new HashMapBasedStorage<string, string>(capacity);
    return new CacheService<string, string>(*policy, *storage,name);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CacheService<string,string>* c1 = createCache(10,"c1");
    CacheService<string,string>* c2 = createCache(20,"c2");

    LevelCacheData cl1 = LevelCacheData(1, 3);
    LevelCacheData cl2 = LevelCacheData(2, 4);

    DefaultLevelCache<string, string>* l2Cache = new DefaultLevelCache<string,string>(cl2, c2, nullptr);
    DefaultLevelCache<string, string>* l1Cache = new DefaultLevelCache<string,string>(cl1, c1, l2Cache);

    MultiLevelCacheServiceDriver<string, string>* cacheService = new MultiLevelCacheServiceDriver<string, string>(l1Cache, 5);

    WriteResponse w1 = cacheService->set("k1", "v1");
    WriteResponse w2 = cacheService->set("k2", "v2");

    cout << "First : " << w1.getTimeTaken() << endl;
    cout << "Second : " << w2.getTimeTaken() << endl;
    assert(10 == w1.getTimeTaken());
    assert(10 == w2.getTimeTaken());

    ReadResponse<string> r1 = cacheService->get("k1");
    cout << "Third : " << r1.getValue() << endl;
    cout << "Fourth : " << r1.getReadTime() << endl;
    assert("v1" == r1.getValue());
    assert(1 == r1.getReadTime());

    ReadResponse<string> r2 = cacheService->get("k2");
    cout << "Fifth : " << r2.getValue() << endl;
    cout << "Sixth : " << r2.getReadTime() << endl;
    assert("v2" == r2.getValue());
    assert(1 == r2.getReadTime());

    // Explicitly remove key from l1 for testing.
    c1->remove("k1");

    ReadResponse<string> r1AfterRemovalFromL1 = cacheService->get("k1");
    cout << "Seventh : " << r1AfterRemovalFromL1.getValue() << endl;
    cout << "Eighth : " << r1AfterRemovalFromL1.getReadTime() << endl;
    assert("v1" == r1AfterRemovalFromL1.getValue());
    assert(6 == r1AfterRemovalFromL1.getReadTime());

    ReadResponse<string> reRead = cacheService->get("k1");
    cout << "Ninth : " << reRead.getValue() << endl;
    cout << "Tenth : " << reRead.getReadTime() << endl;
    assert("v1" == reRead.getValue());
    assert(1 == reRead.getReadTime());

    WriteResponse reWritingValue = cacheService->set("k1", "v1");
    cout << "Eleventh : " << reWritingValue.getTimeTaken() << endl;
    assert(3 == reWritingValue.getTimeTaken());

    StatsResponse res = cacheService->stats();
    cout << res.getAvgReadTime() << " " << res.getAvgWriteTime() << endl;
    cout << "Usages : ";
    for(auto t : *res.getUsages()) {
        cout << t << " ";
    }
    return a.exec();
}
