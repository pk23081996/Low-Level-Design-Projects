#ifndef LADDER_H
#define LADDER_H


class Ladder
{
private:
    int start, end;
public:
    Ladder(int start, int end);
    int getStartPos() {return start;}
    int getEndPos() {return end;}
    void setStartPos(int start) {this->start = start;}
    void setEndPos(int end) {this->end = end;}
};

#endif // LADDER_H
