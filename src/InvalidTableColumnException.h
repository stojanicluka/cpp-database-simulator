#ifndef MYDBMS_INVALIDTABLECOLUMNEXCEPTION_H
#define MYDBMS_INVALIDTABLECOLUMNEXCEPTION_H

/*
 * Contains a definition of the InvalidTableColumnException class
 * and implementation of its methods
*/

#include <exception>
#include <string>

// Exception thrown after trying to access or reference a column
// that doesn't exist in the given table
class InvalidTableColumnException : public std::exception {
private:
    std::string column; // Column that caused an error
    std::string table; // Name of the table an exception is about
    std::string message; // Message to display
public:

    // Constructor takes a column name that caused an error
    // and the name of a table that unexpectedly lacks a column
    InvalidTableColumnException(const std::string &column, const std::string &table)
            : column(column), table(table), message("Error: Column '" + column + "' does not exist in the table '" + table + "'") {}

    // Returns prepared message as a C-style string
    const char *what() const noexcept override {
        return message.c_str();
    }

    // Returns name of a column which caused error
    const std::string &getColumn() const {
        return column;
    }

    // Returns name of a table an exception is about
    const std::string &getTable() const {
        return table;
    }
};

#endif
