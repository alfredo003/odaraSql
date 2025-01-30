/*#include "yousql.hpp"

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
}*/







void imprimir_tokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        std::cout << "Tipo: " << static_cast<int>(token.type) << " | Valor: " << token.value << std::endl;
    }
}

int main() {
    std::string input = R"(CREATE TABLE Persons ( PersonID int,LastName varchar(255),FirstName varchar(255),Address varchar(255),City varchar(255)))";
    Lexer lexer(input);
    auto tokens = lexer.tokenizar();
    imprimir_tokens(tokens);

    return 0;
}
