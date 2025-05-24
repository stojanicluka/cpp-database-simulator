#ifndef MYDBMS_DELETE_H
#define MYDBMS_DELETE_H

/* Contains the definition of the Delete class */

#include "Statement.h"
#include "Filter.h"
#include "DeleteResult.h"

// This class represents an DELETE statement abstraction
class Delete : public Statement {
private:
    Filter *filter; // Deletion filter
public:

    // Constructor takes a pointer to a table object
    // and a pointer to a filter
    // Passing a filter pointer delegates its memory management responsibility to an Update object
    Delete(Table *table, Filter *filter);

    // Executes a statement on the specified table and returns a DeleteResult object
    DeleteResult *execute() const override;
};

#endif
