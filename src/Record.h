#ifndef MYDBMS_RECORD_H
#define MYDBMS_RECORD_H

/* Contains a definition of the Record class */

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

// Class representing one database record (row)
class Record {
private:
    std::unordered_map<std::string, std::string> values; // (column, value) associative container
public:

    // Record constructor - takes (column, value) pairs in an initializer list
    Record(std::vector<std::pair<std::string, std::string> > columnValuePairs);

    // Returns a hash set consisting of all column names
    std::unordered_set<std::string> getColumnNames () const;

    // Returns a value associated with the given column
    const std::string &getValue(const std::string &column) const;

    // Sets a value associated with the given column
    void setValue(const std::string &column, const std::string &value);

    // Equality operator
    friend bool operator == (const Record &r1, const Record &r2);

    // Inequality operator
    friend bool operator != (const Record &r1, const Record &r2);
};


#endif
