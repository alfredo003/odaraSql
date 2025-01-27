#include "Tokens.hpp"

Tokens::Tokens(std::string line)
{
    if(!line.empty())
        _line = line;
    else
            error("empty");
}

void Tokens::processTokens()
{
    std::cout << _line << std::endl;
}

void Tokens::error(std::string type) const
{
    if(type == "empty")
    {
        std::cout << "Linha vazia" << std::endl;
        return;
    }

}