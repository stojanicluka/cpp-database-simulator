#ifndef MYDBMS_COLUMNMISMATCHEXCEPTION_H
#define MYDBMS_COLUMNMISMATCHEXCEPTION_H

/*
 * Contains a definition of the ColumnMismatchException class
 * and implementation of its methods
*/

#include <exception>
#include <string>
#include <unordered_set>

// Exception thrown after encountering a mismatch between Record and Table columns
class ColumnMismatchException : public std::exception {
private:
    std::string message; // Message to display
public:

    // Constructor takes a table name, a set consisting of the Table columns
    // and a set consisting of the Record columns
    ColumnMismatchException(const std::string &tableName, const std::unordered_set<std::string> &tableColumns,
                            const std::unordered_set<std::string> &recordColumns) {

        message = "Error (Table '" + tableName + "'): \n";

        // Prepare the difference sets;
        std::unordered_set<std::string> tableMissing;
        std::unordered_set<std::string> recordMissing;

        for (auto &c : recordColumns)
            if (tableColumns.find(c) == tableColumns.cend())
                tableMissing.insert(c);

        for (auto &c : tableColumns)
            if (recordColumns.find(c) == recordColumns.cend())
                recordMissing.insert(c);

        // Print a list of the missing columns
        if (!tableMissing.empty()) {
            message += "Columns [ ";
            for (auto &s : tableMissing)
                message += "'" + s + "' ";
            message += "] do not exist in the table\n";
        }

        // Print a list of the excess columns
        if (!recordMissing.empty()) {
            message += "Columns [ ";
            for (auto &s : recordMissing)
                message += "'" + s + "' ";
            message += "] and their values must be provided";
        }
    }

    // Returns message as a C-style string
    const char *what() const noexcept override {
        return message.c_str();
    }
};

#endif
