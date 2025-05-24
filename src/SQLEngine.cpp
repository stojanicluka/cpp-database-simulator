/* Contains the implementation of the SQLEngine class methods */

#include "SQLEngine.h"
#include "CreateTableParser.h"
#include "DropTableParser.h"
#include "SelectParser.h"
#include "InsertParser.h"
#include "UpdateParser.h"
#include "DeleteParser.h"
#include "UnexpectedTokenException.h"
#include "Statement.h"

using namespace std;

// Constructor takes a query to be executed and
// a database a query is executed upon
SQLEngine::SQLEngine(const std::string &query, Database *db) : query(query), db(db) {
    prepareQuery();
}

// Destructor
SQLEngine::~SQLEngine() {
    deleteParsers();
}

// Deletes created parsers if they exist
void SQLEngine::deleteParsers() {
    if (ddlParser) {
        delete ddlParser;
        ddlParser = nullptr;
    }
    if (dmlParser) {
        delete dmlParser;
        dmlParser = nullptr;
    }
}

// Prepares a query to be executed
void SQLEngine::prepareQuery() {
    // Fetch the first query token
    Lexer l(query);
    Token tok = l.next();

    // Ensure there are no initialized parsers
    deleteParsers();

    // Create parser based on a first query token
    // CREATE and DROP queries are processed by a DDLParser
    // SELECT, INSERT, UPDATE and DELETE queries are processed by a DMLParser
    if (tok.value == "CREATE")
        ddlParser = new CreateTableParser(query);
    else if (tok.value == "DROP")
        ddlParser = new DropTableParser(query);
    else if (tok.value == "SELECT")
        dmlParser = new SelectParser(query);
    else if (tok.value == "INSERT")
        dmlParser = new InsertParser(query);
    else if (tok.value == "UPDATE")
        dmlParser = new UpdateParser(query);
    else if (tok.value == "DELETE")
        dmlParser = new DeleteParser(query);

    // SHOW TABLE is processed independently of DDL and DML parsers
    else if (tok.value == "SHOW") {

        // Parse the remaining of the SHOW TABLES command
        // to detect syntax errors
        tok = l.next();
        if (tok.value != "TABLES")
            throw UnexpectedTokenException(tok, {{Token::KEYWORD, "TABLES"}});
        tok = l.next();
        if (tok.type != Token::EMPTY && tok.type != Token::SEMICOLON)
            throw UnexpectedTokenException(tok, {{Token::EMPTY}, {Token::SEMICOLON}});
    }

    else throw UnexpectedTokenException(tok, {{Token::KEYWORD, "CREATE"}, {Token::KEYWORD, "SELECT"},
                                             {Token::KEYWORD, "DROP"}, {Token::KEYWORD, "INSERT"},
                                             {Token::KEYWORD, "UPDATE"}, {Token::KEYWORD, "DELETE"},
                                             {Token::KEYWORD, "SHOW"}});
}

// Executes the SHOW TABLES query
void SQLEngine::showTables(ostream &os) const {

    // Print table information
    os << "Found " << db->getTableNames().size() << " tables:\n";
    for (auto t : *db) {
        os << t->getName() << " [ ";
        for (auto &s : t->getColumns())
            os << "'" << s << "' ";
        os << "]\n";
    }
}

// Executes the query and prints the eventual results onto the given ostream
void SQLEngine::execute(ostream &os) {

    // If both dmlParser and ddlParsers are not initialized
    // that implies query is of type SHOW TABLE
    if (!dmlParser && !ddlParser) {
        showTables(os);
        return;
    }

    // Parse a DDL query
    if (ddlParser) {
        ddlParser->parse(db);
        os << "Query executed sucessfully\n";
        return;
    }

    // Parse a DML query
    if (dmlParser) {
        Statement *stmt = dmlParser->parse(db);
        StatementResult *stmtRes = stmt->execute();
        os << *stmtRes <<endl;
        delete stmtRes;
        delete stmt;
    }
}