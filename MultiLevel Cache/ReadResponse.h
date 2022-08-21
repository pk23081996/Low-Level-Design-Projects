#ifndef READRESPONSE_H
#define READRESPONSE_H

template <class Value>
class ReadResponse {
  Value value;
  double readTime;
public:
  ReadResponse(Value value, double readTime) {
      this->value = value;
      this->readTime = readTime;
  }

  double getReadTime() { return readTime; }
  Value getValue() { return value; }

};

#endif // READRESPONSE_H
