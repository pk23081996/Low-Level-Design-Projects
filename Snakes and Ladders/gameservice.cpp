#include "gameservice.h"
#include <iostream>
using namespace std;

GameService::GameService(int boardSize, int numDice, int numFaces) {
    board = new Board(boardSize);
    dice = new DiceService(numFaces);
    this->numDice = numDice;
}

void GameService::setPlayers(vector<Player> playersProvided) {
    initialPlayers = playersProvided.size();
    auto playerPieces = board->getPlayerPieces();
    for(auto p : playersProvided) {
        players.push(p);
        playerPieces[p.getID()] = 0;
    }
}

int GameService::throwDice() {
    int ans = 0;
    for(int i = 0 ; i < numDice ; i++) {
        ans += dice->Roll();
    }
    if(ans == 6) {
        int secondRoll = throwDice();
        int thirdRoll = 0;
        if(secondRoll == 6) {
            thirdRoll = throwDice();
            if(thirdRoll == 6)
                return 0;
        }
        ans += secondRoll + thirdRoll;
    }
    cout << "Returning " << ans << endl;
    return ans;
}

void GameService::startGame() {
    cout << "Game started!" << endl;
    while(!isGameCompleted()) {
        Player p = players.front();
        players.pop();
        int diceVal = throwDice();

        cout << "Its " << p.getName() << "'s turn." << "Dice val = " << diceVal << endl;
        makeMove(p,diceVal);
        cout << p.getName() << " moved to " << board->getPlayerPieces()[p.getID()] << endl;
        if(hasPlayerWon(p)) {
//            auto playerPieces = board->getPlayerPieces();
//            playerPieces.erase(playerPieces.find(p.getID()));
            std::cout << "Player : " << p.getName() << " won!!" << std::endl;
            initialPlayers--;
        } else {
            players.push(p);
        }
    }
    cout << "Game ends\n";
}

void GameService::makeMove(Player p, int positions) {
    auto& players = board->getPlayerPieces();
    int oldPos = players[p.getID()];
    int newPos = oldPos + positions;

    int boardSize = board->getSize();

    if(newPos > boardSize) {
        newPos = oldPos;
    } else {
        newPos = getNewPositionAfterSnakesAndLadders(newPos);
    }

    players[p.getID()] = newPos;
}

int GameService::getNewPositionAfterSnakesAndLadders(int pos)
{
    int oldPos;

    do {
        oldPos = pos;
        for(auto ladder : board->getLadders()) {
            if(ladder.getStartPos() == pos) {
                pos = ladder.getEndPos();
                break;
            }
        }

        for(auto snake : board->getSnakes()) {
            if(snake.getStartPos() == pos) {
                pos = snake.getEndPos();
                break;
            }
        }
    } while(pos != oldPos);

    return pos;
}

bool GameService::hasPlayerWon(Player p) {
    int pos = board->getPlayerPieces()[p.getID()];
    int boardSize = board->getSize();

    return pos == boardSize;
}

bool GameService::isGameCompleted() {
    int currentPlayers = players.size();
    return currentPlayers < initialPlayers;
}
