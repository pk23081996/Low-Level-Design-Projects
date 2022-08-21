#ifndef WRITERESPONSE_H
#define WRITERESPONSE_H

class WriteResponse {
    double timeTaken;
public:
    WriteResponse(double timeTaken) : timeTaken(timeTaken) {

    }

    double getTimeTaken() {return timeTaken;}
};
#endif // WRITERESPONSE_H
