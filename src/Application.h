#ifndef MYDBMS_APPLICATION_H
#define MYDBMS_APPLICATION_H

/* Contains the Application class definition */

#include "Database.h"
#include "Menu.h"
#include "SQLEngine.h"
#include "SQLFormat.h"

// Class is an abstraction of the application
// and its functionalities
class Application {
private:
    static Database *db; // Database object
    static bool stop; // Stop flag

    // Application initialization procedure
    static void init();

    // Creates a new database
    static void createDatabase();

    // Imports an existing database
    static void importDatabase();

    // Prompts the user to enter a query,
    // executes it and prints the result
    static void executeQuery();

    // Prompts user to enter the filename and the file format
    // and exports database to a file
    static void exportDatabase();

    // Asks user to export database and exits the application
    static void exit();
public:

    // Disable object construction
    Application() = delete;

    // Application entry point
    static void run();
};


#endif
