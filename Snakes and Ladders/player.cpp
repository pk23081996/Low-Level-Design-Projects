#include "player.h"

Player::Player(string name, string id)
{
    this->name = name;
    this->id = id;
}

int test::getY() const
{
    return y;
}

void test::setY(int value)
{
    y = value;
}

string test::getName() const
{
    return name;
}

void test::setName(const string &value)
{
    name = value;
}

string test::getId() const
{
    return id;
}

void test::setId(const string &value)
{
    id = value;
}

int test::getX() const
{
    return x;
}

void test::setX(int value)
{
    x = value;
}
