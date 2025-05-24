/* Contains the implementation of the SQLFormat class methods */

#include "SQLFormat.h"

using namespace std;

// Formats a database for writing data into a file
string SQLFormat::formatDatabase(Database *db) const {
    string s = "BEGIN TRANSACTION;\n";

    for (auto t : *db) {

        // Write a CREATE TABLE statement
        s += "CREATE TABLE IF NOT EXISTS \"" + t->getName() + "\" (";

        unordered_set<string> columns = t->getColumns();
        for (auto &c : columns)
            s += "\n\"" + c + "\" TEXT,";

        s[s.size()-1] = '\n';
        s += ");\n";

        // Write all INSERT TABLE statements
        for (auto r : *t) {
            s += "INSERT INTO \"" + t->getName() + "\" VALUES (";

            for (auto &c : columns)
                s += "'" + r->getValue(c) + "',";

            s[s.size()-1] = ')';
            s += ";\n";
        }
    }

    return s + "COMMIT;";
}
