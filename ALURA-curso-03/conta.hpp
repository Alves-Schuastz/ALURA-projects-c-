#pragma once
#include <string>

struct conta{
    std::string numeroConta;
    std::string cpfTitular;
    std::string nomeTitular;
    float saldo;

    void sacar(float valor);
    void depositar(float valor);
};