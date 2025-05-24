#ifndef MYDBMS_INSERT_H
#define MYDBMS_INSERT_H

/* Contains the definition of the Insert class */

#include <vector>
#include "Statement.h"
#include "InsertResult.h"

// This class represents an INSERT statement abstraction
class Insert : public Statement {
private:
    std::vector<Record*> rows; // Rows to insert
public:

    // Using the base class constructor
    using Statement::Statement;

    // Destructor
    ~Insert();

    // Takes one row, as a vector of column-value pairs
    // and adds it to the insertion queue
    void addRow (const std::vector<std::pair<std::string, std::string> > &row);

    // Executes a statement on the specified table and returns a InsertResult object
    virtual InsertResult *execute() const override;
};


#endif
