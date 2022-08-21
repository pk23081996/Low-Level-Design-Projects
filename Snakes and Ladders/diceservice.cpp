#include "diceservice.h"
#include <random>
#include <time.h>
#include <chrono>
using namespace std;
DiceService::DiceService(int numFaces) : faces(numFaces)
{

}

int DiceService::Roll() {
    srand(time(NULL));
    return rand()%faces + 1;
}
