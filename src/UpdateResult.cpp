/* Contains the implementation of the UpdateResult methods */

#include "UpdateResult.h"

using namespace std;

// Constructor takes altered row count
UpdateResult::UpdateResult(int rowCount) : rowCount(rowCount) {}

// Returns a textual representation of the statement result
UpdateResult::operator std::string() const {
    return string("Altered ") + to_string(rowCount) + string(" rows.");
}

// Returns an altered rows count
int UpdateResult::getResult() const {
    return rowCount;
}
