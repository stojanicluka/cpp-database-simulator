/* Contains the implementation of the InsertResult methods */

#include "InsertResult.h"

using namespace std;

// Constructor takes inserted row count
InsertResult::InsertResult(int rowCount) : rowCount(rowCount) {}

// Returns a textual representation of the statement result
InsertResult::operator std::string() const {
    return string("Inserted ") + to_string(rowCount) + string(" rows.");
}

// Returns an inserted rows count
int InsertResult::getResult() const {
    return rowCount;
}
