#ifndef MYDBMS_NOTEQUAL_H
#define MYDBMS_NOTEQUAL_H

/* Contains the definition of the NotEqual class */

#include "Condition.h"

// Class representing the 'not equal' condition
// that is satisfied if the actual column value
// and provided conditioning value are NOT equal
class NotEqual : public Condition {
public:

    // Inherit a Condition constructor
    using Condition::Condition;

    // Evaluates a condition for the actual column value provided and returns a boolean result
    virtual bool evaluate(const std::string &actualValue) const override;
};

#endif
