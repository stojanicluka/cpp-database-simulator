/* Contains the implementation of the CustomFormatParser class methods */

#include "CustomFormatParser.h"
#include "ValueCountInsertException.h"

using namespace std;

Database *CustomFormatParser::parse() {
    Database *db = new Database("DB");

    Token tok;
    while (true) {
        tok = nextToken({{Token::NOT_EQUAL}, {Token::EMPTY}});
        if (tok.type == Token::EMPTY)
            break;

        // Parse the table name
        tok = nextToken({{Token::ALPHASEQ}});
        string tableName = tok.value;

        nextToken({{Token::EQUAL}});

        // Parse column names
        unordered_set<string> columns; // For table creation
        vector<string> orderedColumns; // For row insertion
        while (true) {
            tok = nextToken({{Token::ALPHASEQ}, {Token::ALPHANUMSEQ}});
            columns.insert(tok.value);
            orderedColumns.push_back(tok.value);

            tok = nextToken({{Token::COMMA}, {Token::NOT_EQUAL}});
            if (tok.type == Token::NOT_EQUAL)
                break;
        }

        // Create table
        db->createTable(tableName, columns);
        Table *t = db->getTable(tableName);

        // Fetch rows
        while (true) {
            tok = nextToken({{Token::SEMICOLON}, {Token::ASTERISK}});
            if (tok.type == Token::SEMICOLON)
                break;

            vector<string> values;
            while (true) {
                tok = nextToken({{Token::LITERAL}});
                values.push_back(tok.value.substr(1, tok.value.size()-2)); // Push without quotation marks

                tok = nextToken({{Token::COMMA}, {Token::ASTERISK}});
                if (tok.type == Token::ASTERISK)
                    break;
            }

            // Throw an exception if column count and value count mismatch
            if (orderedColumns.size() != values.size())
                throw ValueCountInsertException();

            // Insert a new record
            vector<pair<string, string> > columnValuePairs;
            for (int i = 0; i < columns.size(); ++i)
                columnValuePairs.push_back(pair(orderedColumns[i], values[i]));
            t->addRecord(new Record(columnValuePairs));
        }
    }
    return db;
}