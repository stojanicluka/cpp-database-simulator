/* Contains the implementation of the Menu class methods */

#include <iostream>
#include "Menu.h"

using namespace std;

// Adds option to the menu
void Menu::addOption(const string &option, void (*function)()) {
    options.push_back(option);
    exec.push_back(function);
}

// Prints menu options
void Menu::print() const {
    cout << "\nChoose an option: " <<endl;
    cout << "---------------------------------------------" <<endl;

    for (int i = 0; i < options.size(); ++i)
        cout << to_string(i) + ") " + options[i] <<endl;
}

// Prints the menu options and prompts the user
void Menu::prompt() const {
    print();

    // Wait for the user to execute a valid option from the list
    int option = -1;
    while (true) {
        cout << "> ";
        string line;
        cin >> line;
        try {
            option = stoi(line);
        }
        catch (exception &e) {
            option = -1;
        }
        if (option >= 0 && option < options.size())
            break;
        cout << "Enter a valid option number" <<endl;
    }

    // Execute a chosen item
    (*exec[option])();
}
