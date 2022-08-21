#ifndef STATSRESPONSE_H
#define STATSRESPONSE_H
#include <vector>

class StatsResponse {
    double avgReadTime;
    double avgWriteTime;
    std::vector<double>* usages;

public:
    StatsResponse(double readTime, double writeTime, std::vector<double>* usages) {
        this->avgReadTime = readTime;
        this->avgWriteTime = writeTime;
        this->usages = usages;
    }

    double getAvgReadTime() { return avgReadTime;}
    double getAvgWriteTime() { return avgWriteTime;}
    std::vector<double>* getUsages() { return usages; }
};

#endif // STATSRESPONSE_H
