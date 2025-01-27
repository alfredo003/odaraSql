#ifndef PROCESSTOKENS_H
#define PROCESSTOKENS_H
#include "../yousql.hpp"

class Tokens
{
private:
    std::string cmd;
    std::string type;
    std::string _line;

public:
    Tokens(std::string line);
    void processTokens();
    void error(std::string type) const;
};

#endif