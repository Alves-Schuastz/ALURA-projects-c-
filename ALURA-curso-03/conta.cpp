#include "conta.hpp"
#include <iostream>

void conta::sacar(float valor){
    if (valor < 0){
        std::cout << "nao e possivel realizar esta transacao" << std::endl;

    }

    else if (valor > saldo){
        std::cout << "saldo insuficiente" << std::endl;
    }

    saldo -= valor;
}

void conta::depositar(float valor){
    if (valor < 0){
        std::cout << "nao e possivel realizar este deposito" << std::endl;

    }

    saldo += valor;
}

