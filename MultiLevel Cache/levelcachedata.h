#ifndef LEVELCACHEDATA_H
#define LEVELCACHEDATA_H
#include <iostream>
using namespace std;
class LevelCacheData
{
    double readTime, writeTime;
public:
    LevelCacheData() = default;
    LevelCacheData(double readTime, double writeTime) : readTime(readTime), writeTime(writeTime) {
        cout << "New level defined with readTime = " << readTime << " and writeTime = " << writeTime << endl;
    }

    double getReadTime() { return readTime;}
    double getWriteTime() { return writeTime;}
};

#endif // LEVELCACHEDATA_H
