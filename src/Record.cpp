/* Contains an implementation of the Record class methods and global operators */

#include "Record.h"
#include "DuplicateColumnException.h"
#include "InvalidRecordColumnException.h"

using namespace std;

// Record constructor - takes (column, value) pairs in an initializer list
Record::Record(vector<pair<string, string>> columnValuePairs) {

    // Initialize column name-value hash map
    for (auto &pair : columnValuePairs) {

        // Throw exception if one column name is specified twice or more times
        if (values.find(pair.first) != values.cend())
            throw DuplicateColumnException(pair.first);

        values[pair.first] = pair.second;
    }
}

// Returns a hash set consisting of all column names
unordered_set<string> Record::getColumnNames() const {

    // Create and prepare a column hash set
    unordered_set<string> columns;
    for (auto &pair : values)
        columns.insert(pair.first);

    return columns;
}

// Returns a value associated with the given column
const string &Record::getValue(const string &column) const {

    // Throw exception if given column does not exist
    if (values.find(column) == values.cend())
        throw InvalidRecordColumnException(column);

    // Can't use operator [] because it isn't declared as const
    return (*values.find(column)).second;
}

// Sets a value associated with the given column
void Record::setValue(const string &column, const string &value) {

    // Throw exception if given column does not exist
    if (values.find(column) == values.cend())
        throw InvalidRecordColumnException(column);

    values[column] = value;
}

// Equality operator
bool operator == (const Record &r1, const Record &r2) {

    // Two Record objects are equal if their hash maps are equal
    return r1.values == r2.values;
}

// Inequality operator
bool operator != (const Record &r1, const Record &r2) {

    // Use already defined equality operator
    return !(r1 == r2);
}



