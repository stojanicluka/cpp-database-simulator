#ifndef MYDBMS_CONDITION_H
#define MYDBMS_CONDITION_H

/* Contains the definition of the Condition class */

#include <string>

// Abstract class representing a condition
class Condition {
private:
    std::string column; // Column that condition is applied to
protected:
    std::string value; // Value that the actual column value is conditioned with
public:

    // Constructor takes the column name and a value the column is conditioned with
    Condition (const std::string &column, const std::string &value);

    // Returns the name of the column a condition is applied to
    const std::string &getColumn() const;

    // Evaluates a condition for the column value provided and returns an evaluation result
    virtual bool evaluate(const std::string &actualValue) const = 0;
};

#endif
