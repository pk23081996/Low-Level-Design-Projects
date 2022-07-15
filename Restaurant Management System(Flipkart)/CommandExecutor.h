#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include "driverclass.h"
#include "OutputPrinter.h"
#include "Command.h"

class CommandExecutor {
protected:
    DriverClass* driver;
    OutputPrinter* printer;

public:
    CommandExecutor(DriverClass* driver, OutputPrinter* printer) {
        this->driver = driver;
        this->printer = printer;
    }

    DriverClass* getDriver() {
        return driver;
    }

    OutputPrinter* getOutputPrinter() {
        return printer;
    }

    virtual bool validate(Command command) = 0;
    virtual void execute(Command command) = 0;
};

#endif // COMMANDEXECUTOR_H
