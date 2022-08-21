#include <QCoreApplication>
#include "gameservice.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <initializer_list>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    GameService *game = new GameService(100,1,6);

    cout << "Players count : ";
    int numPlayers;
    cin >> numPlayers;
    vector<Player> players;
    for(int i = 0 ; i < numPlayers ; i++) {
        string name, id;
        cin >> name >> id;
        Player obj(name,id);
        players.push_back(obj);
    }

    cout << "Snakes count : ";
    int numSnakes;
    cin >> numSnakes;
    vector<Snake> snakes;
    for(int i = 0 ; i < numSnakes ; i++)
    {
        int s,e;
        cin >> s >> e;
        Snake obj(s,e);
        snakes.push_back(obj);
    }

    cout << "Ladders count : ";
    int numLadders;
    cin >> numLadders;
    vector<Ladder> ladders;
    for(int i = 0 ; i < numLadders ; i++)
    {
        int s,e;
        cin >> s >> e;
        Ladder obj(s,e);
        ladders.push_back(obj);
    }

    game->setPlayers(players);
    game->setSnakes(snakes);
    game->setLadders(ladders);
    game->startGame();
    return a.exec();
}
