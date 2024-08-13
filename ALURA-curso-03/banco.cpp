#include <iostream>
#include <string>

using namespace std;

struct conta{
    string numeroConta;
    string cpfTitular;
    string nomeTitular;
    float saldo;

};


int main(){
    conta umaConta;
    umaConta.numeroConta = "123456";
    umaConta.cpfTitular = "123-456-789-10";
    umaConta.nomeTitular = "Vinicius";
    umaConta.saldo = 100;

    conta outraConta;
    outraConta.numeroConta = "123456";
    outraConta.cpfTitular = "123-456-789-10";
    outraConta.nomeTitular = "Vinicius";
    outraConta.saldo = 500;

 
    cout << "Uma conta " << umaConta.saldo << endl << "Outra conta: " << outraConta.saldo << endl;
    return 0;
}