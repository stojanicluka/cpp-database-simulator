#ifndef MYDBMS_SELECTRESULT_H
#define MYDBMS_SELECTRESULT_H

/* Contains the definition of the SelectResult class */

#include <vector>
#include "Record.h"
#include "StatementResult.h"

// Represents an abstraction of the result of the executed SELECT statement
class SelectResult : public StatementResult {
private:
    std::vector<Record> rows; // Fetched rows

    // Prints given matrix of data in a form of a table and returns a string
    std::string printTable(const std::vector<std::vector<std::string>> &data) const;

public:

    // Returns a textual representation of the statement result
    virtual operator std::string () const override;

    // Takes a pointer to Record object and adds it to the rows array
    void addRow(const Record &r);

    // Returns a statement result as a vector of pointers to Record objects
    const std::vector<Record> &getResult() const;
};


#endif
