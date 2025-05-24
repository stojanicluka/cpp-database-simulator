/* Contains the implementation of the Filter class methods */

#include "Filter.h"

using namespace std;

// Destructor
Filter::~Filter() {

    // Delete all condition objects
    for (auto &cw : conditions)
        delete cw.condition;
}

// Takes a pointer to a condition object, logical operation type
// that precedes it and adds them to the list
// Adding a condition delegates its memory management responsibility to the filter object
void Filter::addCondition (LogicalOperation operation, Condition *condition) {
    conditions.push_back({operation, condition});
}

// Evaluates the provided Record object based on the condition list and returns a boolean value
bool Filter::evaluate(const Record *r) const {

    // If condition list is empty, all conditions are satisfied
    if (conditions.empty())
        return true;

    // Not considering the first logical operation, evaluate the first condition
    Condition *c = conditions[0].condition;
    bool result = c->evaluate(r->getValue(c->getColumn()));

    // Evaluate the other conditions and combine them with the result
    // considering preceding logical operation
    for (int i = 1; i < conditions.size(); ++i) {
        c = conditions[i].condition;
        bool conditionResult = c->evaluate(r->getValue(c->getColumn()));

        // Apply appropriate logical operation
        switch(conditions[0].operation) {
            case AND:
                result &= conditionResult;
                break;
            default:
                result &= conditionResult;
        }
    }

    return result;
}
