/* Contains the implementation of the DropTableParser class methods */

#include "DropTableParser.h"

using namespace std;

// Parses and executes a command
void DropTableParser::parse(Database *db) {
    nextToken({{Token::KEYWORD, "DROP"}});
    nextToken({{Token::KEYWORD, "TABLE"}});

    Token tok = nextToken({{Token::ALPHASEQ}});
    db->dropTable(tok.value);
}
