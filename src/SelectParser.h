#ifndef MYDBMS_SELECTPARSER_H
#define MYDBMS_SELECTPARSER_H

/* Contains the SelectParser class definition */

#include "DMLParser.h"
#include "Select.h"

// Class provides the parsing interface for SQL SELECT statements
class SelectParser : public DMLParser {
public:

    // Using the DMLParser constructor
    using DMLParser::DMLParser;

    // Parses a statement and returns a Select object
    virtual Select *parse(Database *db) override;
};


#endif
