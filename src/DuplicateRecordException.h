#ifndef MYDBMS_DUPLICATERECORDEXCEPTION_H
#define MYDBMS_DUPLICATERECORDEXCEPTION_H

/*
 * Contains a definition of the DuplicateRecordException class
 * and implementation of its methods
*/
#include <exception>

// Exception thrown after unexpectedly encountering a
class DuplicateRecordException : public std::exception {
public:

    // Returns a message as a C-style string
    const char *what() const noexcept override {
        return "Error: Given Record object is already present in the table.";
    }
};

#endif
