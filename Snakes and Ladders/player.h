#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using std::string;

class Player
{
    string name, id;
public:
    Player(string name, string id);
    string getName() {return name;}
    string getID() {return id;}
    void setName(string name) { this->name = name;}
    void setID(string id) {this->id = id;}
};

#endif // PLAYER_H
