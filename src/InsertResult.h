#ifndef MYDBMS_INSERTRESULT_H
#define MYDBMS_INSERTRESULT_H

/* Contains the definition of the InsertResult class */

#include "StatementResult.h"

// Represents an abstraction of the result of the executed INSERT statement
class InsertResult : public StatementResult {
private:
    int rowCount; // Inserted rows count

public:

    // Constructor takes inserted row count
    InsertResult(int rowCount);

    // Returns a textual representation of the statement result
    virtual operator std::string() const override;

    // Returns an inserted rows count
    int getResult() const;
};


#endif
