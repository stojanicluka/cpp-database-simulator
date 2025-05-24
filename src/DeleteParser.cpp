/* Contains the implementation of the DeleteParser class methods */

#include "DeleteParser.h"

using namespace std;

// Parses a statement and returns a Delete object
Delete *DeleteParser::parse(Database *db) {
    nextToken({{Token::KEYWORD, "DELETE"}});
    nextToken({{Token::KEYWORD, "FROM"}});

    // Fetch the table name
    Token tok = nextToken({{Token::ALPHASEQ}});
    Table *t = db->getTable(tok.value);

    // Prepare a filter
    tok = nextToken({{Token::EMPTY}, {Token::SEMICOLON}, {Token::KEYWORD, "WHERE"}});
    Filter *f = (tok.type == Token::KEYWORD ? parseConditionList() : new Filter());

    return new Delete(t, f);
}
