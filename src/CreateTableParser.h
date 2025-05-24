#ifndef MYDBMS_CREATETABLEPARSER_H
#define MYDBMS_CREATETABLEPARSER_H

/* Contains the CreateTableParser definition */

#include "DDLParser.h"

// Class provides the parsing interface for SQL CREATE TABLE commands
class CreateTableParser : public DDLParser {
public:

    // Using the DDLParser constructor
    using DDLParser::DDLParser;

    // Parses and executes a command
    virtual void parse(Database *db);
};


#endif
