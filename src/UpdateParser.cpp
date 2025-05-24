/* Contains the implementation of the UpdateParser class methods */

#include <algorithm>
#include "UpdateParser.h"

using namespace std;

// Parses a statement and returns an Update object
Update *UpdateParser::parse(Database *db) {
    nextToken({{Token::KEYWORD, "UPDATE"}});

    // Fetch the table
    Token tok = nextToken({{Token::ALPHASEQ}});
    Table *t = db->getTable(tok.value);

    nextToken({{Token::KEYWORD, "SET"}});

    vector<pair<string, string>> changes;
    // Fetch all changes
    while (true) {
        tok = nextToken({{Token::ALPHASEQ}, {Token::ALPHANUMSEQ}});
        string column = tok.value;

        nextToken({{Token::EQUAL}});
        tok = nextToken({{Token::LITERAL}});
        changes.push_back(pair(column, tok.value.substr(1, tok.value.size()-2))); // Push a literal without a quotation marks

        tok = nextToken({{Token::COMMA}, {Token::EMPTY}, {Token::SEMICOLON}, {Token::KEYWORD, "WHERE"}});
        if (tok.type != Token::COMMA)
            break;
    }

    // Prepare a filter
    Filter *f = (tok.type == Token::KEYWORD ? parseConditionList() : new Filter());

    // Create an Update object and insert changes into a queue
    Update *stmt = new Update(t, f);
    for_each(changes.cbegin(), changes.cend(), [stmt](auto &p){stmt->addChange(p.first, p.second);});

    return stmt;
}
