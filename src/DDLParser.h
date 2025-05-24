#ifndef MYDBMS_DDLPARSER_H
#define MYDBMS_DDLPARSER_H

/* Contains the DDLParser class definition */

#include "Parser.h"
#include "Database.h"

// Class provides the parsing and executing interface for SQL DDL statements
class DDLParser : public Parser {
public:

    // Using the Parser constructor
    using Parser::Parser;

    // Parses and executes a command
    virtual void parse(Database *db) = 0;
};

#endif
