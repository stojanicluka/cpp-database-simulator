/* Contains the implementation of the CreateTableParser class methods */

#include "CreateTableParser.h"

using namespace std;

// Parses and executes a command
void CreateTableParser::parse(Database *db) {
    nextToken({{Token::KEYWORD, "CREATE"}});
    nextToken({{Token::KEYWORD, "TABLE"}});

    // Fetch the table name
    Token tok = nextToken({{Token::ALPHASEQ}});
    string name = tok.value;

    nextToken({{Token::LEFT_PARENTHESIS}});

    // Fetch the column names
    unordered_set<string> columns;
    while (true) {
        tok = nextToken({{Token::ALPHASEQ}, {Token::ALPHANUMSEQ}});
        columns.insert(tok.value);

        tok = nextToken({{Token::COMMA}, {Token::RIGHT_PARENTHESIS}});
        if (tok.type == Token::RIGHT_PARENTHESIS)
            break;
    }
    nextToken({{Token::EMPTY}, {Token::SEMICOLON}});

    db->createTable(name, columns);
}
