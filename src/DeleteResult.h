#ifndef MYDBMS_DELETERESULT_H
#define MYDBMS_DELETERESULT_H

/* Contains the definition of the DeleteResult class */

#include "StatementResult.h"

// Represents an abstraction of the result of the executed DELETE statement
class DeleteResult : public StatementResult {
private:
    int rowCount; // Deleted rows count
public:

    // Constructor takes deleted row count
    DeleteResult(int rowCount);

    // Returns a textual representation of the statement result
    virtual operator std::string() const override;

    // Returns a deleted rows count
    int getResult() const;
};


#endif
