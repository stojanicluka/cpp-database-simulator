/* Contains the implementation of the DMLParser class methods */

#include "DMLParser.h"
#include "Equal.h"
#include "NotEqual.h"

using namespace std;

// Parses a condition list and returns a Filter object
Filter *DMLParser::parseConditionList() {
    Filter *f = new Filter();

    while (true) {
        // Fetch the column name
        Token tok = nextToken({{Token::ALPHASEQ}, {Token::ALPHANUMSEQ}});
        string columnName = tok.value;

        // Determine the type of condition (EQUAL or NOTEQUAL)
        tok = nextToken({{Token::EQUAL}, {Token::NOT_EQUAL}});
        bool equal = tok.type == Token::EQUAL;

        // Fetch the compared value
        tok = nextToken({{Token::LITERAL}});
        string value = tok.value.substr(1, tok.value.size()-2);

        // Create a Condition object
        if (equal)
            f->addCondition(Filter::AND, new Equal(columnName, value));
        else
            f->addCondition(Filter::AND, new NotEqual(columnName, value));

        // If reached the end of the list, break
        tok = nextToken({{Token::EMPTY}, {Token::SEMICOLON}, {Token::KEYWORD, "AND"}});
        if (tok.type != Token::KEYWORD)
            break;
    }

    return f;
};

