/* Contains the implementation of the NotEqual class methods*/

#include "NotEqual.h"

using namespace std;

// Evaluates a condition for the column value provided and returns a boolean result
bool NotEqual::evaluate(const std::string &actualValue) const {

    // Condition is satisfied if the actual value and the conditioning value are NOT equal
    return actualValue != value;
}
