/* Contains the implementation of the CustomFormat class methods */

#include "CustomFormat.h"

using namespace std;

// Formats a database for writing data into a file
string CustomFormat::formatDatabase(Database *db) const {
    string s;

    for (auto t : *db) {
        s += "<> " + t->getName() + " = ";

        // Print column names
        unordered_set<string> columns = t->getColumns();
        for (auto &c : columns)
            s += c + ",";
        s[s.size()-1] = ' ';
        s += "<>";

        // Print rows
        for (auto r : *t) {
            s += "\n* ";
            for (auto &c : columns)
                s += "'" +r->getValue(c)+ "',";
            s[s.size()-1] = '*';
        }

        s+=";\n";
    }

    return s;
}
