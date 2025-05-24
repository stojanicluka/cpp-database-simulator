#ifndef MYDBMS_INVALIDTABLEEXCEPTION_H
#define MYDBMS_INVALIDTABLEEXCEPTION_H

/*
 * Contains a definition of the InvalidTableException class
 * and implementation of its methods
*/

#include <exception>
#include <string>

// Exception thrown when a table with a given name does not exist
class InvalidTableException : public std::exception {
private:
    std::string table; // Table name which caused an error
    std::string message; // Message to display
public:

    // Constructor takes a table name that caused an error
    InvalidTableException(const std::string &table)
            : table(table), message("Error: Table with the given name '" + table + "' does not exist") {}

    // Returns a message as a C-style string
    const char *what() const noexcept override {
        return message.c_str();
    }

    // Returns a table name that caused an error
    const std::string &getTableName() const {
        return table;
    }
};

#endif
