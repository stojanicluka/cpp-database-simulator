/* Contains the implementation of the Update class methods */

#include "Update.h"
#include "InvalidTableColumnException.h"
#include "InvalidRecordColumnException.h"

using namespace std;

// Constructor takes a pointer to a table object
// and a pointer to a filter
// Passing a filter pointer delegates its memory management responsibility to an Update object
Update::Update(Table *table, Filter *filter) : Statement(table), filter(filter) {}

// Takes column name and a new column value and puts the change in a queue
void Update::addChange (const string &column, const string &value) {
    changes.push_back(pair(column, value));
}

// Executes a statement on the specified table and returns a StatementResult object
UpdateResult *Update::execute() const {

    // Check if all queued column names are present in the table
    unordered_set<string> tableColumns = getTable() -> getColumns();
    for (auto &p : changes)
        if (tableColumns.find(p.first) == tableColumns.cend())
            throw InvalidTableColumnException(p.first, getTable()->getName());

    int alteredCount = 0;

    // Iterate through all table records and apply an update
    // to rows that pass the given filter
    for (auto r : *getTable()) {
        try {
            if (filter->evaluate(r)) {
                ++alteredCount;
                for (auto &p: changes)
                    r->setValue(p.first, p.second);
            }
        }
        catch (InvalidRecordColumnException &e) {
            throw InvalidTableColumnException(e.getColumn(), getTable()->getName());
        }
    }

    return new UpdateResult(alteredCount);
}
