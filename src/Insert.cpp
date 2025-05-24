/* Contains the implementation of the Insert class methods */

#include <algorithm>
#include "Insert.h"
#include "ColumnMismatchException.h"

using namespace std;

// Destructor
Insert::~Insert() {

    // Delete all records from the queue
    for_each(rows.cbegin(), rows.cbegin(), [](auto r){delete r;});
}

// Takes one row, as a vector of column-value pairs
// and adds it to the insertion queue
void Insert::addRow (const vector<pair<string, string> > &row) {
    rows.push_back(new Record(row));
}

// Executes a statement on the specified table and returns a InsertResult object
InsertResult *Insert::execute() const {

    // Keep track of the inserted rows count
    int insertedCount = 0;

    // Try to insert every Record from a queue
    for (auto r : rows) {

        // Create a Record copy to separate lifetime
        // and memory management of a Record in a queue and the inserted one
        Record *newRecord = new Record(*r);

        try {
            getTable()->addRecord(newRecord);
            ++insertedCount;
        }
        catch (ColumnMismatchException &e) {
            delete newRecord;
            throw;
        }
    }

    return new InsertResult(insertedCount);
}
