#ifndef OUTPUTPRINTER_H
#define OUTPUTPRINTER_H

#include <iostream>
using namespace std;

class OutputPrinter {
public:
  void printWithNewLine(string msg) {
    cout << msg << endl;
  }

  void welcome() {
    printWithNewLine("Welcome to my Restaurant Management System!.");
  }

  void end() {
    printWithNewLine("Thanks for using my Restaurant Management System!.");
  }

  void notFound() {
    printWithNewLine("Not found");
  }

  void statusHeader() {
    printWithNewLine("Slot No.    Registration No    Colour");
  }

  void parkingLotFull() {
    printWithNewLine("Sorry, parking lot is full");
  }

  void parkingLotEmpty() {
    printWithNewLine("Parking lot is empty");
  }

  void invalidFile() {
    printWithNewLine("Invalid file given.");
  }
};

#endif // OUTPUTPRINTER_H
