#ifndef MYDBMS_CUSTOMFORMATPARSER_H
#define MYDBMS_CUSTOMFORMATPARSER_H

/* Contains the CustomFormatParser definition */

#include "Parser.h"
#include "Database.h"

// Provides an interface for parsing a database
// exported in a 'custom format'
class CustomFormatParser : public Parser {
public:

    // Using the Parser constructor
    using Parser::Parser;

    // Parses a given string and returns a Database object
    Database *parse();

};


#endif
