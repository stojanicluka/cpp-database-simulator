#ifndef MYDBMS_DATABASE_H
#define MYDBMS_DATABASE_H

/* Contains a definition of the Database class and its iterator */

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <fstream>
#include "Table.h"

// Class representing a database
class Database {
private:
    std::string name; // Database name
    std::unordered_map<std::string, Table*> tables; // (table name, Table*) associative container
public:

    // Database iterator class
    class Iterator {
    private:
        std::unordered_map<std::string, Table*>::iterator it; // Table* list iterator
    public:

        // Constructor takes a Table* list iterator
        Iterator(std::unordered_map<std::string, Table*>::iterator it) : it(it) {}

        // Dereferencing operator
        Table *&operator * () const { return (*it).second; }

        // Predecrement operator
        Iterator &operator ++ () { ++it; return *this; }

        // Inequality operator
        bool operator != (const Iterator &i) { return i.it != it;}
    };

    // Constructor takes a database name
    Database(const std::string &name);

    // Destructor
    ~Database();

    // Takes a table name, column name set and creates a table
    void createTable(const std::string &name, const std::unordered_set<std::string> &columns);

    // Takes a table name and erases a table
    void dropTable(const std::string &name);

    // Takes a table name and returns a pointer to Table object
    Table *getTable(const std::string &name) const;

    // Returns a hash set consisting of the table names
    std::unordered_set<std::string> getTableNames() const;

    // Returns an iterator pointing to the first table in the database,
    // not necessarily the first one created
    Iterator begin();

    // Returns an iterator pointing to the (imaginary) element behind the last table in the database
    Iterator end();
};


#endif
