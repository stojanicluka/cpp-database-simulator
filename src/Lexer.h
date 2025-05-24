#ifndef MYDBMS_LEXER_H
#define MYDBMS_LEXER_H

/* Contains the definition of the Lexer class and the Token struct */

#include <string>

// Lexer class which provides the interface
// for SQL statement tokenization
class Lexer {
private:
    static const std::string literal_pattern; // LITERAL regex pattern
    static const std::string alphanumseq_pattern; // ALPHANUMERIC_SEQUENCE regex pattern
    static const std::string other_pattern; // Short token regex pattern
    static const std::string irregular_pattern; // Irregular token regex pattern
    static const std::string pattern; //  regex pattern
    static const std::string keywords[]; // Keyword list

    std::string line; // Line to be tokenized
    int pos = 0; // Position in the line from where to continue token matching

    // Checks if an alphanumeric sequence contains any digits
    static bool containsDigit(const std::string &str);

public:

    // Token definition
    struct Token {
        static const std::string defaults[];
        enum Type {KEYWORD, LITERAL, ALPHANUMSEQ, ALPHASEQ, ASTERISK, COMMA, DOT, LEFT_PARENTHESIS, RIGHT_PARENTHESIS,
            NOT_EQUAL, EQUAL, SEMICOLON, IRREGULAR, EMPTY} type = EMPTY; // Token type
        std::string value = defaults[type]; // Actual value
        int startIndex = -1; // Line position where a token starts
    };

    // Constructor takes line string that has to be tokenized
    Lexer(const std::string &line);

    // Returns the next token from a line
    Token next();
};


#endif
