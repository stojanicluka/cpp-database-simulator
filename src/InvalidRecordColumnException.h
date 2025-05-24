#ifndef MYDBMS_INVALIDRECORDCOLUMNEXCEPTION_H
#define MYDBMS_INVALIDRECORDCOLUMNEXCEPTION_H

/*
 * Contains a definition of the InvalidRecordColumnException class
 * and implementation of its methods
*/

#include <exception>
#include <string>

// Exception thrown after trying to access a column
// that doesn't exist in a given Record object
class InvalidRecordColumnException : public std::exception {
private:
    std::string column; // Column that caused an error
    std::string message; // Message to display
public:

    // Constructor takes a column name that caused an error
    InvalidRecordColumnException(const std::string &column)
        : column(column), message("Error: Column '" + column + "' does not exist in a record") {}

    // Returns prepared message as a C-style string
    const char *what() const noexcept override {
        return message.c_str();
    }

    // Returns name of a column which caused error
    const std::string &getColumn() const {
        return column;
    }
};

#endif
