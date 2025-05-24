#ifndef MYDBMS_DUPLICATECOLUMNEXCEPTION_H
#define MYDBMS_DUPLICATECOLUMNEXCEPTION_H

/*
 * Contains a definition of the DuplicateColumnException class
 * and implementation of its methods
*/

#include <exception>
#include <string>

// Exception thrown after unexpectedly encountering certain column name twice
class DuplicateColumnException : public std::exception {
private:
    std::string column; // Column name which caused error
    std::string message; // Message to display
public:

    // Constructor takes a name of column which caused error
    DuplicateColumnException(const std::string &column)
        : column(column), message("Error: Column names must be unique (column '" + column + "')") {}

    // Returns message as a C-style string
    const char *what() const noexcept override {
        return message.c_str();
    }

    // Returns name of a column which caused error
    const std::string &getColumn() const {
        return column;
    }
};


#endif
