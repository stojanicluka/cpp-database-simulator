/* Contains the implementation of the Delete class methods */

#include <algorithm>
#include "Delete.h"
#include "InvalidRecordColumnException.h"
#include "InvalidTableColumnException.h"

using namespace std;

// Constructor takes a pointer to a table object
// and a pointer to a filter
// Passing a filter pointer delegates its memory management responsibility to an Update object
Delete::Delete(Table *table, Filter *filter) : Statement(table), filter(filter) {}

// Executes a statement on the specified table and returns a DeleteResult object
DeleteResult *Delete::execute() const {

    // Put all records that pass a given filter
    // into the deletion queue
    vector<Record*> toDelete;
    for (auto r : *getTable()) {
        try {
            if (filter->evaluate(r))
                toDelete.push_back(r);
        }
        catch (InvalidRecordColumnException &e) {
            throw InvalidTableColumnException(e.getColumn(), getTable()->getName());
        }
    }

    for(auto r : toDelete) {
        getTable()->removeRecord(r);
        delete r;
    }

    return new DeleteResult(toDelete.size());
}
