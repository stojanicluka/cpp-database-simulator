#ifndef MYDBMS_DELETEPARSER_H
#define MYDBMS_DELETEPARSER_H

/* Contains the DeleteParser class definition */

#include "DMLParser.h"
#include "Delete.h"

// Class provides the parsing interface for SQL DELETE statements
class DeleteParser : public DMLParser {
public:

    // Using the DMLParser constructor
    using DMLParser::DMLParser;

    // Parses a statement and returns a Delete object
    virtual Delete *parse(Database *db) override;
};


#endif
