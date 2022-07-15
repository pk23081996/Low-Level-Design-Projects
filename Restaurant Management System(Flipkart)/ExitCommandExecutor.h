#ifndef EXITCOMMANDEXECUTOR_H
#define EXITCOMMANDEXECUTOR_H

#include "CommandExecutor.h"

class ExitCommandExecutor : public CommandExecutor {
    QStringList params;

public:
    static string COMMAND_NAME;
    ExitCommandExecutor(DriverClass* driver, OutputPrinter* printer)  : CommandExecutor(driver, printer) { }

    bool validate(Command command) {
        return params.empty();
    }

    void execute(Command command) {
        printer->end();
    }
};

string ExitCommandExecutor::COMMAND_NAME = "exit";

#endif // EXITCOMMANDEXECUTOR_H
