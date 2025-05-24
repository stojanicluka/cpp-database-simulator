#ifndef MYDBMS_SELECT_H
#define MYDBMS_SELECT_H

/* Contains the definition of the Select class */

#include <vector>
#include "Statement.h"
#include "Filter.h"
#include "SelectResult.h"

// This class represents a SELECT statement abstraction
class Select : public Statement {
private:
    Filter *f; // Selection filter
    std::vector<std::string> columns; // Selected columns

public:

    // Constructor takes a pointer to a table object
    // and a pointer to a filter
    // Passing a filter pointer delegates its memory management responsibility to a Select object
    Select (Table *t, Filter *f, const std::vector<std::string> &columns);

    // Destructor
    ~Select() override;

    // Executes a statement on the specified table and returns a SelectResult object
    virtual SelectResult *execute() const override;

};

#endif
