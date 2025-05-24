#ifndef MYDBMS_UPDATE_H
#define MYDBMS_UPDATE_H

/* Contains the definition of Update class */

#include <vector>
#include "Statement.h"
#include "Filter.h"
#include "UpdateResult.h"

// This class represents an UPDATE statement abstraction
class Update : public Statement{
private:
    Filter *filter; // Update filter
    std::vector<std::pair<std::string, std::string> > changes; // List of columns with a new values
public:

    // Constructor takes a pointer to a table object
    // and a pointer to a filter
    // Passing a filter pointer delegates its memory management responsibility to an Update object
    Update(Table *table, Filter *filter);

    // Takes column name and a new column value and puts the change in a queue
    void addChange (const std::string &column, const std::string &value);

    // Executes a statement on the specified table and returns a UpdateResult object
    UpdateResult *execute() const override;
};


#endif
