#ifndef MYDBMS_TABLE_H
#define MYDBMS_TABLE_H

/* Contains a definition of the Table class and its Iterator class */

#include <unordered_set>
#include <string>
#include <forward_list>
#include "Record.h"

// Class representing a database table
class Table {
private:
    std::string name; // Table name
    std::unordered_set<std::string> columns; // Column names set
    std::forward_list<Record*> records; // Record pointer list
public:

    // Table iterator class
    class Iterator {
    private:
        std::forward_list<Record*>::iterator it; // Record* list iterator
    public:

        // Constructor takes a Record* list iterator
        Iterator(std::forward_list<Record*>::iterator it) : it(it) {}

        // Dereferencing operator
        Record *&operator * () const { return *it; }

        // Predecrement operator
        Iterator &operator ++ () { ++it; return *this; }

        // Inequality operator
        bool operator != (const Iterator &i) { return i.it != it;}
    };

    // Constructor takes a table name and a set of a column names
    Table(const std::string &name, const std::unordered_set<std::string> &columns);

    // Destructor
    ~Table();

    // Returns a table name
    const std::string &getName() const;

    // Returns a hash set consisting of column names
    const std::unordered_set<std::string> &getColumns() const;

    // Takes a pointer to a record object and adds it to the table
    // Adding a record delegates its memory management responsibility to the table object
    void addRecord(Record *r);

    // Takes a pointer to a record object and removes it from the table
    // Removing a record delegates its memory management responsibility to the caller
    void removeRecord(Record *r);

    // Returns an iterator pointing to the first record in the table,
    // not necessarily the first one inserted
    Iterator begin();

    // Returns an iterator pointing to the (imaginary) element behind the last record in the table
    Iterator end();
};


#endif
