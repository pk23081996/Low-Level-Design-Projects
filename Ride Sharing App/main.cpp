#include <QCoreApplication>
#include "RideManager.h"
#include "mostvacantstrategy.h"
#include "prefferedvehiclestrategy.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    RideManager* app = RideManager::getInstance();

    app->add_user("Rohan", 'M', 36);
    app->add_vehicle("Rohan", "Swift", "KA-01-12345");

    app->add_user("Shashank", 'M', 29);
    app->add_vehicle("Shashank", "Baleno", "TS-05-62395");

    app->add_user("Nandini", 'F', 29);
    app->add_user("Shipra", 'F', 27);
    app->add_vehicle("Shipra", "Polo", "KA-05-41491");
    app->add_vehicle("Shipra", "Activa", "KA-12-12332");

    app->add_user("Gaurav", 'M', 29);
    app->add_user("Rahul", 'M', 35);
    app->add_vehicle("Rahul", "XUV", "KA-05-1234");

    app->offer_ride("Rohan", "Hyderabad", 1, "Swift", "KA-01-12345", "Bangalore");
    app->offer_ride("Shipra", "Bangalore", 1, "Activa", "KA-12-12332", "Mysore");
    app->offer_ride("Shipra", "Bangalore", 2, "Polo", "KA-05-41491", "Mysore");
    app->offer_ride("Shashank", "Hyderabad", 2, "Baleno", "TS-05-62395", "Bangalore");
    app->offer_ride("Rahul", "Hyderabad", 5, "XUV",  "KA-05-1234", "Bangalore");
    app->offer_ride("Rohan", "Bangalore", 1, "Swift", "KA-01-12345", "Pune");

    app->select_ride("Nandini", new MostVacantStrategy("Bangalore", "Mysore", 1));
    app->select_ride("Gaurav",  new PrefferedVehicleStrategy("Bangalore", "Mysore", 1, "Activa"));
    app->select_ride("Shashank", new MostVacantStrategy("Mumbai", "Bangalore", 1));
    app->select_ride("Rohan", new PrefferedVehicleStrategy("Hyderabad", "Bangalore", 1,"Baleno"));
    app->select_ride("Shashank", new PrefferedVehicleStrategy("Hyderabad", "Bangalore", 1,"Polo"));

    app->end_ride("2-a");
    app->end_ride("2-b");
    app->end_ride("2-c");
    app->end_ride("2-d");

    app->print_ride_stats();

    return a.exec();
}
