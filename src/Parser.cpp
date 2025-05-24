/* Contains the implementation of the Parser class methods */

#include "Parser.h"
#include "UnexpectedTokenException.h"

using namespace std;

// Returns the next token
// Throws an error if the token isn't among the expected ones
Token Parser::nextToken(std::initializer_list<Token> expected) {
    Token tok = lexer.next();

    // Compare the next token to every one in the expected list
    for (const Token &t : expected) {

        // If both tokens are keyword, their values must be compared
        if (t.type == Token::KEYWORD && tok.type == Token::KEYWORD && t.value == tok.value)
            return tok;

        // Else, compare only token types
        if (t.type == tok.type && t.type != Token::KEYWORD)
            return tok;
    }

    throw UnexpectedTokenException(tok, expected);
}

// Constructor takes a line to be parsed
Parser::Parser(const std::string &line) : lexer(line) {}
