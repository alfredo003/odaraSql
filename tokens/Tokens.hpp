#ifndef PROCESSTOKENS_H
#define PROCESSTOKENS_H
#include "../yousql.hpp"
#include <sstream>
#include <vector>
#include <cctype>
#include <unordered_map>

enum class TokenType {
    SELECT, FROM, WHERE, AND, OR, IDENTIFIER, OPERATOR, VALUE, ASTERISK, COMMA, LPAREN, RPAREN, STRING, END
};


struct Token {TokenType type; std::string value;};

class Lexer
{
    public:
        Lexer(const std::string& input) : input(input), pos(0){};
        std::vector<Token> tokenizar();

    private:
        std::string input;
        size_t pos;
        Token parseKeywordOrIdentifier();
        Token parseNumber(); 
        Token parseString();
        Token parseComparisonOperator();
        Token parseLogicalOperator();
};

class Tokens
{
    private:
    std::string _line;
        
    public:
        Tokens(std::string line);
        void processTokens();
        void error(std::string type) const;
        static void split_tokens(std::string line);
};

#endif