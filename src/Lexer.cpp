/* Contains the implementation of the Lexer class methods and static fields */

#include <string>
#include <algorithm>
#include <regex>
#include "Lexer.h"

using namespace std;

const string Lexer::Token::defaults[]  {"keyword", "literal", "alphanumseq", "alphaseq", "*", ",", ".", "(", ")", "<>", "=", ";", "!", "end of statement"};

// Regex pattern definitions
const string Lexer::literal_pattern = "\"[^\"]*\"|\'[^\']*\'";
const string Lexer::alphanumseq_pattern = "[A-Z|a-z|0-9]+";
const string Lexer::other_pattern = "\\*|\\.|,|\\(|\\)|<>|=|;";
const string Lexer::irregular_pattern = "[\\S]+";
const string Lexer::pattern = literal_pattern+"|"+alphanumseq_pattern+"|"+other_pattern+"|"+irregular_pattern;

// Keyword list definition
const string Lexer::keywords[] {"CREATE", "TABLE", "DROP", "SELECT", "FROM", "WHERE", "AND", "INSERT", "INTO", "VALUES", "UPDATE", "SET", "WHERE", "DELETE", "SHOW", "TABLES"};

// Constructor takes line string that has to be tokenized
Lexer::Lexer(const string& line) :line(line) {}

// Checks if an alphanumeric sequence contains any digits
bool Lexer::containsDigit(const std::string &str) {
    for (char c : str)
        if (c >= '0' && c <= '9') return true;
    return false;
}

// Returns the next token from a line
Lexer::Token Lexer::next() {

    // Search for the next match with any of the defined regex patterns
    smatch res;
    regex_search(line, res, regex(pattern));

    // If there are no chars remaining, return the EMPTY token
    if (res.empty()) return Token();

    // Update remaining line and the next search position
    // based on the length of the found token and
    // number of discarded preceding chars (prefix)
    string s = res[0].str();
    pos += res.prefix().length()+res.length();
    line = line.substr(res.prefix().length()+res.length());

    // Calculate token position
    int startIndex = pos - s.length();

    // Try to fully match found token
    // against every pattern, one by one, to categorize it
    if (regex_match(s, regex(literal_pattern)))
        return Token{Token::LITERAL, s, startIndex};

    if (regex_match(s, regex(alphanumseq_pattern))) {

        // If the matched token is a keyword, convert it to an uppercase string
        // for the case of later comparing its value to the expected values
        string temp = s;
        transform(temp.begin(), temp.end(), temp.begin(), [](char c){return (c >= 'a' && c <= 'z' ? c + 'A' - 'a' : c);});
        if (find(keywords, keywords + sizeof(keywords)/sizeof(*keywords), temp) != keywords + sizeof(keywords)/sizeof(*keywords))
            return Token {Token::KEYWORD, temp, startIndex};

        // Categorize further based on a digit containment
        return Token{(containsDigit(s) ? Token::ALPHANUMSEQ : Token::ALPHASEQ), s, startIndex};
    }

    // Categorize further based on the type of short token
    if (regex_match(s, regex(other_pattern))) {
        if (s == "*") return Token {Token::ASTERISK, "*", startIndex};
        if (s == ".") return Token {Token::DOT, ".", startIndex};
        if (s == "(") return Token {Token::LEFT_PARENTHESIS, "(", startIndex};
        if (s == ")") return Token {Token::RIGHT_PARENTHESIS, ")", startIndex};
        if (s == "=") return Token {Token::EQUAL, "=", startIndex};
        if (s == "<>") return Token {Token::NOT_EQUAL, "<>", startIndex};
        if (s == ";") return Token {Token::SEMICOLON, ";", startIndex};
        if (s == ",") return Token {Token::COMMA, ",", startIndex};
    }

    // If none of the other patterns matched, return IRREGULAR token
    return Token{Token::IRREGULAR, s, startIndex};
}
