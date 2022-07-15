#ifndef COMMANDEXECUTORFACTORY_H
#define COMMANDEXECUTORFACTORY_H

#include "CommandExecutor.h"
#include "UpdateMenuCommandExecutor.h"
#include "ExitCommandExecutor.h"

class CommandExecutorFactory {
    map<string, CommandExecutor*> commands;

public:
    CommandExecutorFactory(DriverClass* driver, OutputPrinter* printer) {
        commands[UpdateMenuCommandExecutor::COMMAND_NAME] = new UpdateMenuCommandExecutor(driver, printer);
        commands[ExitCommandExecutor::COMMAND_NAME] = new ExitCommandExecutor(driver, printer);
    }

    CommandExecutor* getCommandExecutor(Command command) {
        CommandExecutor* commandExecutor = commands[command.getCommandName()];
        if(!commandExecutor) {
            //throw exception
        }
        return commandExecutor;
    }
};

#endif // COMMANDEXECUTORFACTORY_H
