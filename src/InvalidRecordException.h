#ifndef MYDBMS_INVALIDRECORDEXCEPTION_H
#define MYDBMS_INVALIDRECORDEXCEPTION_H

/*
 * Contains a definition of the InvalidRecordException class
 * and implementation of its methods
*/

#include <exception>

// Exception thrown after trying to access an invalid Record object
class InvalidRecordException : public std::exception {
public:

    // Returns a message as a C-style string
    const char *what() const noexcept override {
        return "Error: Given Record object does not exist in the table";
    }
};

#endif
