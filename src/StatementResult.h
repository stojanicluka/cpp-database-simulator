#ifndef MYDBMS_STATEMENTRESULT_H
#define MYDBMS_STATEMENTRESULT_H

/* Contains the definition of the StatementResult */

#include <string>
#include <iostream>

// Represents an abstraction of the result of the executed statement
class StatementResult {
public:

    // Returns a textual representation of the statement result
    virtual operator std::string() const = 0;

    // Stream operator
    friend std::ostream &operator << (std::ostream &os, const StatementResult &sr);
};


#endif
