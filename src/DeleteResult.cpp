/* Contains the implementation of the DeleteResult methods */

#include "DeleteResult.h"

using namespace std;

// Constructor takes deleted row count
DeleteResult::DeleteResult(int rowCount) : rowCount(rowCount) {}

// Returns a textual representation of the statement result
DeleteResult::operator std::string() const {
    return string("Deleted ") + to_string(rowCount) + string(" rows.");
}

// Returns a deleted rows count
int DeleteResult::getResult() const {
    return rowCount;
}
