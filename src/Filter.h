#ifndef MYDBMS_FILTER_H
#define MYDBMS_FILTER_H

/* Contains the definition of the Filter class */

#include <vector>
#include "Condition.h"
#include "Record.h"

// Filter filters Record object by evaluating a set of
// conditions on its column values
class Filter {
public:
    enum LogicalOperation {AND}; // Logical operation type

private:

    // ConditionWrapper stores logical operation
    // which possibly precedes the condition
    struct ConditionWrapper {
        enum LogicalOperation operation;
        Condition *condition;
    };

    std::vector<ConditionWrapper> conditions; // Vector of conditions
public:

    // Destructor
    ~Filter();

    // Takes a pointer to a condition object, logical operation type
    // that precedes it and adds them to the list
    // Adding a condition delegates its memory management responsibility to the filter object
    void addCondition (LogicalOperation operation, Condition *condition);

    // Evaluates the provided Record object based on the condition list and returns a boolean value
    bool evaluate(const Record *r) const;
};

#endif
