/* Contains the implementation of the Condition class methods */

#include "Condition.h"

using namespace std;

// Constructor takes the column name and a value the column is conditioned with
Condition::Condition (const string &column, const string &value) : column(column), value(value) {}

// Returns the name of the column a condition is applied to
const string &Condition::getColumn() const {
    return column;
}