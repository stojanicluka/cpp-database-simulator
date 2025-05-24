/* Contains the implementation of the SelectParser class methods */

#include <algorithm>
#include "SelectParser.h"

using namespace std;

// Parses a statement and returns a Statement object
Select *SelectParser::parse(Database *db) {

    nextToken({{Token::KEYWORD, "SELECT"}});

    // Fetch the first column name or an ASTERISK token
    Token tok = nextToken({{Token::ASTERISK}, {Token::ALPHANUMSEQ}, {Token::ALPHASEQ}});
    bool allColumns = (tok.type == Token::ASTERISK);

    vector<string> columns;
    if (!allColumns) {

        // Process listed column names;
        columns.push_back(tok.value);
        while (true) {
            tok = nextToken({{Token::COMMA},{Token::KEYWORD, "FROM"}});

            if (tok.type == Token::KEYWORD)
                break;

            tok = nextToken({{Token::ALPHASEQ}, {Token::ALPHANUMSEQ}});
            columns.push_back(tok.value);
        }
    }
    else
        nextToken({{Token::KEYWORD, "FROM"}});

    // Fetch the table
    tok = nextToken({{Token::ALPHASEQ}});
    string table = tok.value;
    Table *t = db->getTable(tok.value);

    // If encountered asterisk earlier, add all columns to the list
    if (allColumns) {
        const unordered_set<string> &tableColumns = t->getColumns();
        for_each(tableColumns.cbegin(), tableColumns.cend(), [&columns](auto &s){columns.push_back(s);});
    }

    tok = nextToken({{Token::EMPTY}, {Token::SEMICOLON}, {Token::KEYWORD, "WHERE"}});

    // Prepare a filter
    Filter *f = (tok.type == Token::KEYWORD ? parseConditionList() : new Filter());

    return new Select(t, f, columns);
}