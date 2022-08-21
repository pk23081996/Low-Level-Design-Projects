#ifndef GAMESERVICE_H
#define GAMESERVICE_H
#include <queue>
#include "board.h"
#include "diceservice.h"
using std::queue;

class GameService
{
private:
    queue<Player> players;
    Board *board;
    DiceService *dice;
    int numDice;
    int initialPlayers;
public:
    GameService(int boardSize = 100, int numDice = 1, int numFaces = 6);

    void startGame();
    bool isGameCompleted();
    int throwDice();
    void makeMove(Player p, int positions);
    int getNewPositionAfterSnakesAndLadders(int oldPos);
    bool hasPlayerWon(Player p);

    void setPlayers(vector<Player> playersProvided);
    void setSnakes(vector<Snake> snakes) { board->setSnakes(snakes); }
    void setLadders(vector<Ladder> ladders) { board->setLadders(ladders); }
};

#endif // GAMESERVICE_H
