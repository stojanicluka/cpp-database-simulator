/* Contains the implementation of the Select class methods */

#include "Select.h"
#include "InvalidRecordColumnException.h"
#include "InvalidTableColumnException.h"

using namespace std;

// Constructor takes a pointer to a table object,
// a pointer to a filter and a vector of columns to select
// Passing a filter pointer delegates its memory management responsibility to a Select object
Select::Select(Table *t, Filter *f, const vector<string> &columns) : Statement(t), f(f), columns(columns) {}

// Destructor
Select::~Select() {

    delete f;
}

// Executes a statement on the specified table and returns a SelectResult object
SelectResult *Select::execute() const {

    SelectResult *sr = new SelectResult();

    // Iterate through all table records
    for (auto r : *getTable()) {

        // If a table record satisfied given filter conditions, add it to the result
        try {
            if (f->evaluate(r)) {
                vector<pair<string, string> > pairs;

                // Pick only the requested columns
                for (auto &c: columns)
                    pairs.push_back(pair(c, r->getValue(c)));
                sr->addRow(Record(pairs));
            }
        }
        catch (InvalidRecordColumnException &e) {
            throw InvalidTableColumnException(e.getColumn(), getTable()->getName());
        }
    }

    return sr;
}
