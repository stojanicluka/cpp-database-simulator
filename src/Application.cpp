/* Contains the implementation of the Application class methods and static field */

#include <sstream>
#include "Application.h"
#include "CustomFormatParser.h"
#include "CustomFormat.h"

using namespace std;

Database *Application::db = nullptr; // Database object
bool Application::stop = false; // Stop flag

// Application initialization procedure
void Application::init() {
    Menu mm;
    mm.addOption("Create a new database", &Application::createDatabase);
    mm.addOption("Import an existing database", &Application::importDatabase);
    mm.addOption("Exit", &Application::exit);
    while (!db && !stop)
        mm.prompt();
}

// Creates a new database
void Application::createDatabase() {
    db = new Database("DB");
}


// Imports an existing database
void Application::importDatabase() {

    cout << "Enter a filename (custom format) to import database from: ";
    string filename;
    cin >> filename;

    try {
        ifstream is(filename);

        if (!is.is_open()) {
           cout << "File with a given name doesn't exist." <<endl;
           return;
        }

        // Read whole file at once
        stringstream ss;
        ss << is.rdbuf();

        // Parse file contents
        CustomFormatParser cf(ss.str());
        db = cf.parse();
        cout << "Database imported sucessfully" <<endl;
        is.close();
    }
    catch (exception &e) {
        cout << e.what() <<endl;
    }
}

// Prompts the user to enter a query,
// executes it and prints the result
void Application::executeQuery() {

    cout << "Enter queries - one query by row. Remaining characters after ';' are ignored.\n "
            "Enter an empty string to go back to the menu.\n";

    // Ignore a newline character
    cin.ignore();

    // Execute queries until encountered an empty string
    while (true) {

        // Fetch a query
        string s;

        getline(cin, s);
        if (s.empty())
            break;

        try {

            // Execute
            SQLEngine engine(s, db);
            engine.execute(cout);
        }
        catch (exception &e) {
            cout << e.what() <<endl;
        }
    }
}

// Prompts user to enter the filename and the file format
// and exports database to a file
void Application::exportDatabase() {

    // Prompt user to enter a file format
    // until entered format is correct
    string s = "";
    while (s != "sql" && s != "custom") {
        cout << "Pick a file format for exported database [sql, custom]: ";
        cin >> s;
    }

    // Prompt user to enter a filename
    string filename;
    cout << "Enter a name of a file to export a database into: ";
    cin >> filename;

    // Format string
    string format = (s == "sql" ? SQLFormat().formatDatabase(db) : CustomFormat().formatDatabase(db));

    // Write to a file
    try {
        ofstream os(filename, ios::trunc);
        os << format;
        os.close();
        cout << "Database exported successfully" <<endl;
    }
    catch (exception &e) {
        cout << e.what() <<endl;
    }
}


// Asks user to export database and exits the application
void Application::exit() {

    // Ask user if he really wants to exit
    cout << "Are you sure? ('y' for yes) ";
    string s;
    cin >> s;
    if (s != "y")
        return;

    // Prompts user to export database in order to save it
    if (!db)
        return;
    cout << "Exiting... Do you want to export the database to a file? ('y' for yes) ";
    cin >> s;

    if (s == "y")
        exportDatabase();

    stop = true;
    delete db;
}

// Application entry point
void Application::run() {

    // Database initialization;
    init();

    // Menu setup
    Menu m;
    m.addOption("Execute a query", &executeQuery);
    m.addOption("Export database to a file", &exportDatabase);
    m.addOption("Exit", &exit);

    // Prompt user to pick an option
    // Repeat until user called exit
    while (!stop)
        m.prompt();
}
