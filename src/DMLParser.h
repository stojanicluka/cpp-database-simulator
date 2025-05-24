#ifndef MYDBMS_DMLPARSER_H
#define MYDBMS_DMLPARSER_H

/* Contains the definition of the DMLParser class */

#include <string>
#include "Parser.h"
#include "Statement.h"
#include "Filter.h"
#include "Database.h"


// Class provides the parsing interface for SQL DML statements
class DMLParser : public Parser {
protected:

    // Parses a condition list and returns a Filter object
    Filter *parseConditionList();
public:

    // Using the Parser constructor
    using Parser::Parser;

    // Parses a statement and returns a Statement object
    virtual Statement *parse(Database *db) = 0;
};


#endif
