#ifndef MYDBMS_MENU_H
#define MYDBMS_MENU_H

/* Contains the Menu class definition */

#include <vector>
#include <string>

// Class provides an interface to display a list of options
// and prompt the user to execute one option
class Menu {
private:
    std::vector<void (*)()> exec; // List of option tasks
    std::vector<std::string> options; // List of option texts

    // Prints menu options
    void print() const;

public:

    // Adds option to the menu
    void addOption(const std::string &option, void (*function)());

    // Prints the menu options and prompts the user
    void prompt() const;
};

#endif