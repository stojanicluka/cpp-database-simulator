/* Contains a definition of the Table class methods */

#include <algorithm>
#include "Table.h"
#include "DuplicateRecordException.h"
#include "InvalidRecordException.h"
#include "ColumnMismatchException.h"

using namespace std;

// Constructor takes a table name and a set of a column names
Table::Table(const string &name, const unordered_set<string> &columns) : name(name), columns(columns) {}

// Returns the table name
const string &Table::getName() const {
    return name;
}

// Returns a set consisting of the column names
const unordered_set<string> &Table::getColumns() const {
    return columns;
}

// Takes a pointer to a record object and adds it to the table
// Adding a record delegates its memory management responsibility to the table object
void Table::addRecord(Record *r) {

    // Throw an exception if the same Record object is already in the table
    if (find(records.cbegin(), records.cend(), r) != records.cend())
        throw DuplicateRecordException();

    // Throw an exception if the Record and Table column names do not match
    unordered_set<string> recordColumns = r->getColumnNames();
    if (recordColumns != columns) {
        throw ColumnMismatchException(name, columns, recordColumns);
    }

    records.push_front(r);
}

// Takes a pointer to a record object and removes it from the table
// Removing a record delegates its memory management responsibility to the caller
void Table::removeRecord(Record *r) {

    // Throw an exception if the given Record object is not in the table
    if (find(records.cbegin(), records.cend(), r) == records.cend())
        throw InvalidRecordException();

    records.remove(r);
}

// Returns an iterator pointing to the first record in the table,
// not necessarily the first one inserted
Table::Iterator Table::begin() {
    return Iterator(records.begin());
}

// Returns an iterator pointing to the (imaginary) element behind the last record in the table
Table::Iterator Table::end() {
    return Iterator(records.end());
}

// Destructor
Table::~Table() {

    // Delete every Record object
    for_each(records.cbegin(), records.cend(), [](auto r){delete r;});
}

