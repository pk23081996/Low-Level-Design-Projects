#ifndef DICESERVICE_H
#define DICESERVICE_H


class DiceService
{
    int faces;
public:
    DiceService(int numFaces = 6);
    int Roll();
};

#endif // DICESERVICE_H
