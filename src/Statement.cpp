/* Contains the implementation of the Statement class methods */

#include "Statement.h"

using namespace std;

// Constructor takes a pointer to the table a query is applied to
Statement::Statement(Table *table) : table(table) {}

// Define a pure virtual destructor
Statement::~Statement() {}

// Returns a pointer to the table a query is applied to
Table *Statement::getTable() const {
    return table;
}


