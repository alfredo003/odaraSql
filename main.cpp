#include "yousql.hpp"

void imprimir_tokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        std::cout << "Tipo: " << static_cast<int>(token.type) << " | Valor: " << token.value << std::endl;
    }
}

int main()
{
    std::string line;
    while (true)
    {
        menu_func();
        if(!std::getline(std::cin, line))
                break;
        Lexer lexer(line);
        auto tokens = lexer.tokenizar();
        imprimir_tokens(tokens);
    }
    return (0);
}
