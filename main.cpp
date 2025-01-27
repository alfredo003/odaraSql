#include "yousql.hpp"

int main(int argc, char *argv[])
{
    std::string line;
    while (true)
    {
        menu_func();
        std::getline(std::cin, line);
        Tokens tokens(line);
    }
    return (0);    
}