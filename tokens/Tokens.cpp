#include "Tokens.hpp"

Tokens::Tokens(const std::string line)
{
    
   /* if(!line.empty())
    {
        for (char &c :line)
        {
            c = toupper(c);
        }
        _line = line;
    }
    else
            error("empty");*/
}

void Tokens::processTokens()
{
   char delimiter = ' ';
   
}

void Tokens::split_tokens(std::string line)
{
     (void)line;
}

void Tokens::error(std::string type) const
{
    if(type == "empty")
    {
        std::cout << "Linha vazia" << std::endl;
        return;
    }
}