#include "yousql.hpp"

int main()
{
    std::string line;
    while (true)
    {
        menu_func();
        std::getline(std::cin, line);
        Lexer lexer(line);
        auto tokens = lexer.tokenizar();
        imprimir_tokens(tokens);
    }
    return (0);
}
