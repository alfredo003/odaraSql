#include "Lexer.hpp"

   std::vector<Token> Lexer::tokenizar()
   {
        std::vector<Token> tokens;
        
        while (pos < input.size())
        {
            char currentChar = input[pos];
            
            if (isspace(currentChar)) {
                pos++;
                continue;
            }
            
            if (isalpha(currentChar)) {
                tokens.push_back(parseKeywordOrIdentifier());
            }
            else if (isdigit(currentChar) || currentChar == '.') {
                tokens.push_back(parseNumber());
            }
            else if (currentChar == '*') {
                tokens.push_back({TokenType::ASTERISK, "*"});
                pos++;
            }
            else if (currentChar == ',') {
                tokens.push_back({TokenType::COMMA, ","});
                pos++;
            }
            else if (currentChar == '(') {
                tokens.push_back({TokenType::LPAREN, "("});
                pos++;
            }
            else if (currentChar == ')') {
                tokens.push_back({TokenType::RPAREN, ")"});
                pos++;
            }
            else if (currentChar == '"') {
                tokens.push_back(parseString());
            }
            else if (currentChar == '=') {
                tokens.push_back({TokenType::OPERATOR, "="});
                pos++;
            }
            else if (currentChar == '>' || currentChar == '<' || currentChar == '!') {
                tokens.push_back(parseComparisonOperator());
            }
            else if (currentChar == '&' || currentChar == '|') {
                tokens.push_back(parseLogicalOperator());
            }
            else {
                throw std::runtime_error("Unexpected character: " + std::string(1, currentChar));
            }
        }

        tokens.push_back({TokenType::END, ""});
        return tokens;
    }

    Token Lexer::parseKeywordOrIdentifier()
    {
        size_t start = pos;
        while (pos < input.size() && (isalnum(input[pos]) || input[pos] == '_')) {
            pos++;
        }
        std::string value = input.substr(start, pos - start);

        static std::unordered_map<std::string, TokenType> keywords = {
            {"CREATE", TokenType::CREATE},
            {"SELECT", TokenType::SELECT},
            {"FROM", TokenType::FROM},
            {"WHERE", TokenType::WHERE},
            {"AND", TokenType::AND},
            {"OR", TokenType::OR}
        };

        if (keywords.find(value) != keywords.end()) {
            return {keywords[value], value};
        } else {
            return {TokenType::IDENTIFIER, value};
        }
    }

    Token Lexer::parseNumber() 
    {
        size_t start = pos;
        bool hasDecimal = false;
        
        while (pos < input.size() && (isdigit(input[pos]) || input[pos] == '.')) {
            if (input[pos] == '.') {
                if (hasDecimal) {
                    throw std::runtime_error("Invalid number format.");
                }
                hasDecimal = true;
            }
            pos++;
        }
        
        return {TokenType::VALUE, input.substr(start, pos - start)};
    }

    Token Lexer::parseString()
    {
        size_t start = ++pos;
        while (pos < input.size() && input[pos] != '"') {
            pos++;
        }
        if (pos >= input.size()) {
            throw std::runtime_error("Unterminated string literal.");
        }
        
        std::string value = input.substr(start, pos - start);
        pos++;
        return {TokenType::STRING, value};
    }

    Token Lexer::parseComparisonOperator()
    {
        char firstChar = input[pos];
        char secondChar = (pos + 1 < input.size()) ? input[pos + 1] : '\0';

        if (firstChar == '>' || firstChar == '<') {
            pos++;
            if (secondChar == '=') {
                pos++;
                return {TokenType::OPERATOR, std::string(1, firstChar) + "="};
            }
            return {TokenType::OPERATOR, std::string(1, firstChar)};
        } 
        else if (firstChar == '!') {
            pos++;
            if (secondChar == '=') {
                pos++;
                return {TokenType::OPERATOR, "!="};
            }
        }
        return {TokenType::OPERATOR, std::string(1, firstChar)};
    }

    Token Lexer::parseLogicalOperator()
    {
        char firstChar = input[pos];
        if ((firstChar == '&' && input[pos + 1] == '&') || (firstChar == '|' && input[pos + 1] == '|')) {
            pos += 2;
            return {firstChar == '&' ? TokenType::AND : TokenType::OR, std::string(1, firstChar) + std::string(1, input[pos-1])};
        }
        throw std::runtime_error("Invalid logical operator.");
    }
