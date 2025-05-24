/* Contains the implementation of the InsertParser class methods */

#include <algorithm>
#include "InsertParser.h"
#include "ValueCountInsertException.h"

using namespace std;

// Parses a statement and returns an Insert object
Insert *InsertParser::parse(Database *db) {
    nextToken({{Token::KEYWORD, "INSERT"}});
    nextToken({{Token::KEYWORD, "INTO"}});

    // Fetch the table
    Token tok = nextToken({{Token::ALPHASEQ}});
    Table *t = db->getTable(tok.value);

    Insert *stmt = new Insert(t);

    // Fetch the listed column names
    vector<string> columns;
    nextToken({{Token::LEFT_PARENTHESIS}});
    while (true) {

        // Parse one column name
        tok = nextToken({{Token::ALPHASEQ}, {Token::ALPHANUMSEQ}});
        columns.push_back(tok.value);

        tok = nextToken({{Token::COMMA}, {Token::RIGHT_PARENTHESIS}});
        if (tok.type == Token::RIGHT_PARENTHESIS)
            break;
    }

    nextToken({{Token::KEYWORD, "VALUES"}});

    // Fetch the value tuples
    while (true) {
        nextToken({{Token::LEFT_PARENTHESIS}});

        // Fetch one tuple
        vector<string> values;
        while (true) {

            // Parse one column value
            tok = nextToken({{Token::LITERAL}});
            values.push_back(tok.value.substr(1, tok.value.size()-2)); // Push a literal without a quotation marks

            tok = nextToken({{Token::COMMA}, {Token::RIGHT_PARENTHESIS}});
            if (tok.type == Token::RIGHT_PARENTHESIS)
                break;
        }

        // Throw an error if column name count
        // differs from provided values count
        if (columns.size() != values.size())
            throw ValueCountInsertException();

        // Add a new row to the insertion queue
        vector <pair<string, string>> row;
        for (int i = 0; i < columns.size(); ++i)
            row.push_back(pair(columns[i], values[i]));
        stmt->addRow(row);

        tok = nextToken({{Token::COMMA}, {Token::EMPTY}, {Token::SEMICOLON}});
        if (tok.type != Token::COMMA)
            break;
    }

    return stmt;
}
