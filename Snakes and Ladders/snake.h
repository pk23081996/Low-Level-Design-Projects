#ifndef SNAKE_H
#define SNAKE_H

class Snake
{
private:
    int start, end;
public:
    Snake(int start, int end);
    int getStartPos() {return start;}
    int getEndPos() {return end;}
    void setStartPos(int start) {this->start = start;}
    void setEndPos(int end) {this->end = end;}
};

#endif // SNAKE_H
