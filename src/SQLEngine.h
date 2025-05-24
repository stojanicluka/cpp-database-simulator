#ifndef MYDBMS_SQLENGINE_H
#define MYDBMS_SQLENGINE_H

/* Contains the SQLEngine class definition */

#include <iostream>
#include <string>
#include "DDLParser.h"
#include "DMLParser.h"

// Provides an interface for parsing
// and executing SQL queries
class SQLEngine {
private:
    std::string query; // Query to be executed
    Database *db; // Database a query is applied to
    DDLParser *ddlParser = nullptr; // DDLParser object
    DMLParser *dmlParser = nullptr; // DMLParser object

    // Prepares a query to be executed
    void prepareQuery();

    // Deletes created parsers if they exist
    void deleteParsers();

    // Executes the SHOW TABLES query
    void showTables(std::ostream &os) const;
public:

    // Constructor takes a query to be executed and
    // a database a query is executed upon
    SQLEngine(const std::string &query, Database *db);

    // Destructor
    ~SQLEngine();

    // Executes the query and prints the eventual results onto the given ostream
    void execute(std::ostream &os);
};


#endif
