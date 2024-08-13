#include <vector>
#include "le_arquivo.hpp"

extern std::vector<char> chutes_errados;

std::string sorteia_palavra()
{
    std::vector<std::string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    return palavras[indice_sorteado];
}