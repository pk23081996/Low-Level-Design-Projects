#ifndef BOARD_H
#define BOARD_H
#include "ladder.h"
#include "snake.h"
#include "player.h"
#include <vector>
#include <map>
using std::vector;
using std::map;

class Board
{
    int size;
    map<string, int> PlayerPieces;
    vector<Snake> Snakes;
    vector<Ladder> Ladders;

public:
    Board(int size = 100);
    void setPlayerPieces(map<string, int> playersPieces) { this->PlayerPieces = playersPieces;}
    void setSnakes(vector<Snake> snakes) {this->Snakes = snakes;}
    void setLadders(vector<Ladder> ladders) {this->Ladders = ladders;}

    map<string, int>& getPlayerPieces() { return PlayerPieces;}
    vector<Snake> getSnakes() { return Snakes;}
    vector<Ladder> getLadders() { return Ladders;}
    int getSize() {return size;}
};

#endif // BOARD_H
