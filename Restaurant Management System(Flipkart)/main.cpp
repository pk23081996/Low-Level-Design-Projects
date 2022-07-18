#include <QCoreApplication>
#include<iostream>
#include "driverclass.h"
#include "restaurant.h"
#include "CommandExecutorFactory.h"
#include "InteractiveMode.h"
using namespace std;

bool isInteractiveMode(int argc) {
    return argc == 1;
}

bool isFileMode(int argc) {
    return argc == 2;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DriverClass *driver = new DriverClass();
    OutputPrinter* printer = new OutputPrinter;
    CommandExecutorFactory* commandExecutorFactory = new CommandExecutorFactory(driver, printer);

    unordered_map<string,double> menu1,menu2,menu3;
    menu1["Veg Biryani"] = 100.0;
    menu1["Chicken Biryani"] = 150.0;

    driver->registerRestaurant(5,menu1,4.5);

    menu2["Chicken Biryani"] = 175.0;
    menu2["Idli"] = 10.0;
    menu2["Veg Biryani"] = 80.0;
    menu2["Dosa"] = 50.0;

    driver->registerRestaurant(5,menu2,4);

    menu3["Chicken Biryani"] = 175.0;
    menu3["Gobi Manchurian"] = 150.0;
    menu3["Dosa"] = 30.0;
    menu3["Idli"] = 15.0;

    driver->registerRestaurant(1,menu3,1);
    driver->showAvailableItems();

    driver->updateRestaurantMenu("R1", UpdateRestaurant::AddItem, "Chicken65", 250);

    if(isInteractiveMode(argc)) {
        InteractiveMode obj(commandExecutorFactory, printer);
        obj.process();
    } /*
    else if(isFileMode(args) {
        new FileMode(commandExecutorFactory, printer, args[0]);
    } */
    // Note: We should use factory pattern here for the mode! Because whenever a new mode will be introduced, we would have to change the main().
//    driver->updateRestaurantMenu("R2", UpdateRestaurant::UpdateItem, "Chicken Biryani", 150);

    driver->placeOrder(Customer("Ashwin"), {make_pair("Idli",3), make_pair("Dosa",1)}, OrderSelectionCriteria::Lowest_Cost);
    driver->placeOrder(Customer("Harish"), {make_pair("Idli",3), make_pair("Dosa",1)}, OrderSelectionCriteria::Lowest_Cost);
    driver->placeOrder(Customer("Shruti"), {make_pair("Veg Biryani",3)}, OrderSelectionCriteria::Max_Rating);

    driver->updateOrderStatus("Order1", OrderStatus::Completed);
    driver->placeOrder(Customer("Harish"), {make_pair("Idli",3), make_pair("Dosa",1)}, OrderSelectionCriteria::Lowest_Cost);
    driver->placeOrder(Customer("xyz"), {make_pair("Paneer Tikka",1), make_pair("Idli",1)}, OrderSelectionCriteria::Lowest_Cost);

    return a.exec();
}
