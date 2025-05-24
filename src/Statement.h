#ifndef MYDBMS_STATEMENT_H
#define MYDBMS_STATEMENT_H

/* Contains the definition of the Statement class */

#include "Table.h"
#include "StatementResult.h"

// This abstract class represents a statement abstraction
class Statement {
private:
    Table *table; // Table pointer

public:

    // Constructor takes a pointer to the table a query is applied to
    Statement(Table *table);

    // Declaring destructor as pure virtual
    virtual ~Statement() = 0;

    // Returns a pointer to the table a query is applied to
    Table *getTable() const;

    // Executes a statement on the specified table and returns a StatementResult object
    virtual StatementResult *execute() const = 0;
};


#endif
