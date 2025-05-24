#ifndef MYDBMS_UPDATEPARSER_H
#define MYDBMS_UPDATEPARSER_H

/* Contains the UpdateParser class definition */

#include "DMLParser.h"
#include "Update.h"
#include "Filter.h"

// Class provides the parsing interface for SQL UPDATE statements
class UpdateParser : public DMLParser {
public:

    // Using the DMLParser constructor
    using DMLParser::DMLParser;

    // Parses a statement and returns an Update object
    virtual Update *parse(Database *db) override;
};


#endif
