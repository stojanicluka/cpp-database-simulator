#ifndef MYDBMS_INSERTPARSER_H
#define MYDBMS_INSERTPARSER_H

/* Contains the InsertParser class definition */

#include "DMLParser.h"
#include "Insert.h"

// Class provides a parsing interface for SQL INSERT statements
class InsertParser : public DMLParser {
public:

    // Using the DMLParser constructor
    using DMLParser::DMLParser;

    // Parses a statement and returns an Insert object
    virtual Insert *parse(Database *db) override;
};


#endif
