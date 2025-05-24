#ifndef MYDBMS_UNEXPECTEDTOKENEXCEPTION_H
#define MYDBMS_UNEXPECTEDTOKENEXCEPTION_H

/*
 * Contains a definition of the UnexpectedTokenException class
 * and implementation of its methods
*/

#include <exception>
#include <string>
#include <algorithm>
#include "Lexer.h"

// Exception thrown after encountering a token that
// isn't among the expected ones
class UnexpectedTokenException : public std::exception {
private:
    std::string message; // Message to display
public:

    // Constructor takes the unexpected token and the list of the expected ones
    UnexpectedTokenException(Lexer::Token tok, std::initializer_list<Lexer::Token> expected) {

        // Form the error message
        message = "(Syntax error) " + (tok.type == Lexer::Token::EMPTY ? "Unexpected end of statement" : "Unexpected token: '" + tok.value + "' at position " + std::to_string(tok.startIndex));
        message += ", expected: ";

        // Form the 'expected' part of the message
        // based on the context where certain token types
        // are used
        // ALPHASEQ for the table name
        // ALPHASEQ or ALPHANUMSEQ for the column name
        // Others are displayed as they are
        bool alphaseq = false, alphanumseq = false;
        for (const Lexer::Token &t : expected) {
            if (t.type == Lexer::Token::ALPHASEQ) {
                alphaseq = true;
                continue;
            }
            if (t.type == Lexer::Token::ALPHANUMSEQ) {
                alphanumseq = true;
                continue;
            }
            message += "'" + t.value + "' or ";
        }

        if (alphaseq && alphanumseq)
            message += "'column name (consists only of alphanumeric characters)'";
        else if (alphaseq && !alphanumseq)
            message += "'table name (consists only of letters)'";
        else
            message.resize(message.size()-3);
    }

    // Returns an error message as a C-style formatted string
    const char *what() const noexcept override {
        return message.c_str();
    }
};

#endif
