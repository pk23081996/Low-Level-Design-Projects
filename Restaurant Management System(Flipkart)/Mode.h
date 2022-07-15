#ifndef MODE_H
#define MODE_H

#include "CommandExecutorFactory.h"

class Mode {
protected:
    CommandExecutorFactory* commandExecutorFactory;
    OutputPrinter* outputPrinter;

public:
    Mode(CommandExecutorFactory* commandExecutorFactory, OutputPrinter* outputPrinter) {
        this->commandExecutorFactory = commandExecutorFactory;
        this->outputPrinter = outputPrinter;
    }

    void processCommand(Command command) {
        CommandExecutor* commandExecutor = commandExecutorFactory->getCommandExecutor(command);
        if(commandExecutor->validate(command)) {
            commandExecutor->execute(command);
        } else {
            //throw exception
        }
    }

    virtual void process() = 0;
};

#endif // MODE_H
