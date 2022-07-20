#include "RideManager.h"

int RideManager::count = 0;
mutex RideManager::mtx;
RideManager* RideManager::driver = nullptr;
