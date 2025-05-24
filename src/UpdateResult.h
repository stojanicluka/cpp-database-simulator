#ifndef MYDBMS_UPDATERESULT_H
#define MYDBMS_UPDATERESULT_H

/* Contains the definition of the UpdateResult class */

#include "StatementResult.h"

// Represents an abstraction of the result of the executed UPDATE statement
class UpdateResult : public StatementResult {
private:
    int rowCount; // Altered rows count

public:

    // Constructor takes altered row count
    UpdateResult(int rowCount);

    // Returns a textual representation of the statement result
    virtual operator std::string() const override;

    // Returns an altered rows count
    int getResult() const;
};


#endif
