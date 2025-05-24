/* Contains an implementation of the Database class methods */

#include <algorithm>
#include "Database.h"
#include "DuplicateTableException.h"
#include "InvalidTableException.h"

using namespace std;

// Constructor takes a database name
Database::Database(const string &name) : name (name) {}

// Destructor
Database::~Database() {

    // Delete every table
    for_each(tables.cbegin(), tables.cend(), [](auto &p){delete p.second;});
}

// Takes the table name, a hash set of the column names and creates a table
void Database::createTable(const string &name, const unordered_set<string> &columns) {

    // Throws an exception if table with a given name already exists
    if (tables.find(name) != tables.cend())
        throw DuplicateTableException(name);

    tables[name] = new Table(name, columns);
}

// Takes the table name and erases it
void Database::dropTable(const string &name) {

    // Throws an exception if the table with a given name does not exist
    if (tables.find(name) == tables.cend())
        throw InvalidTableException(name);

    // Drop the table
    delete tables[name];
    tables.erase(name);
}

// Takes the table name and returns a pointer to a Table object
Table *Database::getTable(const string &name) const {

    // Throws an exception if the table with a given name does not exist
    if (tables.find(name) == tables.cend())
        throw InvalidTableException(name);

    // Can't use the operator [] because it is not declared as const
    return (*tables.find(name)).second;
}

// Returns a hash set consisting of the table names
unordered_set<string> Database::getTableNames() const {

    // Create and prepare a table name hash set
    unordered_set<string> tableNames;
    for (auto &p : tables)
        tableNames.insert(p.first);

    return tableNames;
}

// Returns an iterator pointing to the first table in the database,
// not necessarily the first one created
Database::Iterator Database::begin() {
    return Iterator(tables.begin());
}

// Returns an iterator pointing to the (imaginary) element behind the last table in the database
Database::Iterator Database::end() {
    return Iterator(tables.end());
}