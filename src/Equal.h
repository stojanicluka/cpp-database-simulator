#ifndef MYDBMS_EQUAL_H
#define MYDBMS_EQUAL_H

/* Contains the definition of the Equal class */

#include "Condition.h"

// Class representing the 'equal' condition
// that is satisfied if the actual column value
// and provided conditioning value are equal
class Equal : public Condition {
public:

    // Inherit a Condition constructor
    using Condition::Condition;

    // Evaluates a condition for the actual column value provided and returns an evaluation result
    virtual bool evaluate(const std::string &actualValue) const override;
};


#endif
