#ifndef INTERACTIVEMODE_H
#define INTERACTIVEMODE_H

#include "Mode.h"
#include "ExitCommandExecutor.h"
#include <iostream>
class InteractiveMode : public Mode {


public:
    InteractiveMode(CommandExecutorFactory* commandExecutorFactory, OutputPrinter* outputPrinter) :
        Mode(commandExecutorFactory, outputPrinter) {}

    void process() {
        outputPrinter->welcome();

        while(true) {
            cout << "Enter some command : ";
            string input;
            getline(cin, input);
            cout << "Command = " << input << endl;
            Command command(input);
            processCommand(command);
            if (command.getCommandName() == ExitCommandExecutor::COMMAND_NAME) {
                break;
            }
        }
    }
};

#endif // INTERACTIVEMODE_H
