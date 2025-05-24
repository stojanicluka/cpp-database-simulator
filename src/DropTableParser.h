#ifndef MYDBMS_DROPTABLEPARSER_H
#define MYDBMS_DROPTABLEPARSER_H

/* Contains the DropTableParser definition */

#include "DDLParser.h"

// Class provides the parsing interface for SQL DROP TABLE commands
class DropTableParser : public DDLParser {
public:

    // Using the DDLParser constructor
    using DDLParser::DDLParser;

    // Parses and executes a command
    virtual void parse(Database *db);
};


#endif
