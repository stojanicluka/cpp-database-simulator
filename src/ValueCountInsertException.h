#ifndef MYDBMS_VALUECOUNTINSERTEXCEPTION_H
#define MYDBMS_VALUECOUNTINSERTEXCEPTION_H

/*
 * Contains a definition of the ValueCountInsertException class
 * and implementation of its methods
*/

#include <exception>

// Exception thrown after parsing a tuple with the value count
// different from the provided column names count
class ValueCountInsertException : public std::exception {
public:

    // Returns an error message as a C-style string
    const char *what() const noexcept override {
        return "Error: Every value tuple must have same field count as the provided columns count";
    }
};

#endif
