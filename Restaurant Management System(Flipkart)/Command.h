#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <list>
#include <QStringList>
#include <QString>
using namespace std;

class Command {
    const QString SPACE = " ";
    string commandName;
    QStringList params;

public:
    Command(string inputLine) {
        QString temp = QString::fromStdString(inputLine);
        temp = temp.trimmed();
        QStringList tokensList = temp.split(SPACE);

        if(tokensList.size() == 0) {
            //throw exception
        }

        commandName = tokensList[0].toStdString();
        tokensList.pop_front();
        params = tokensList;
    }
    string getCommandName() {
        return commandName;
    }

    QStringList getParams() {
        return params;
    }
};

#endif // COMMAND_H
