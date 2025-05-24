/* Contains the implementation of the Equal class methods */

#include "Equal.h"

using namespace std;

// Evaluates a condition for the column value provided and returns a boolean result
bool Equal::evaluate(const std::string &actualValue) const {

    // Condition is satisfied if the actual value and the conditioning value are equal
    return actualValue == value;
}