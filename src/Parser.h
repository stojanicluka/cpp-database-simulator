#ifndef MYDBMS_PARSER_H
#define MYDBMS_PARSER_H

/* Contains the Parser class definition */

#include "Lexer.h"

typedef Lexer::Token Token;

class Parser {
private:
    Lexer lexer; // Tokenizer
protected:

    // Returns the next token
    // Throws an error if the token isn't among the expected ones
    Token nextToken(std::initializer_list<Token> expected);

public:

    // Constructor takes a line to be parsed
    Parser(const std::string &line);
};


#endif
