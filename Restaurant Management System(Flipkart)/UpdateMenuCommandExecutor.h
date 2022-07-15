#ifndef UPDATEMENUCOMMANDEXECUTOR_H
#define UPDATEMENUCOMMANDEXECUTOR_H

#include "CommandExecutor.h"

class UpdateMenuCommandExecutor : public CommandExecutor {
    QStringList params;

public:
    static string COMMAND_NAME;
    UpdateMenuCommandExecutor(DriverClass* driver, OutputPrinter* printer)  : CommandExecutor(driver, printer) { }
    bool validate(Command command) {
        params = command.getParams();
        if(params.size() < 4) //command, restaurant_id, item, price
            return false;

        return true;
    }

    void execute(Command command) {
        string id = params[0].toStdString(); params.pop_front();
        string item = params[0].toStdString(); params.pop_front();
        bool ok;
        double price = params[0].toDouble(&ok);
        while(ok == false) {
            item += " " + params[0].toStdString();
            params.pop_front();
            price = params[0].toDouble(&ok);
        }

        DriverClass* driver = getDriver();
        driver->updateRestaurantMenu(id, UpdateRestaurant::UpdateItem, item, price);

        OutputPrinter* printer = getOutputPrinter();
        QString temp = QString("Updated restaurant %1 with item %2 and price %3").arg(id.c_str()).arg(item.c_str()).arg(price);
        printer->printWithNewLine(temp.toStdString());
    }
};

string UpdateMenuCommandExecutor::COMMAND_NAME = "update_menu";

#endif // UPDATEMENUCOMMANDEXECUTOR_H
