#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>


using namespace std;
string palavra_secreta = "MELANCIA";
vector<char> chutes_errados;
map<char,bool> chutou;


void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){
        arquivo << nova_lista.size() << endl;

        for (string palavra : nova_lista){
            arquivo << palavra << endl;
        }

        arquivo.close();
    }
    else{
        cout << endl << "erro ao abrir o arquivo 'palavras.txt'";
        exit(0);
    }
}

bool letra_existe(char chute){
    for(char letra : palavra_secreta){
        if (chute == letra){
            return true;
        }
    }
    return false;
    
}
bool nao_acertou(){
    for (char letra: palavra_secreta){
    if(!chutou[letra]){
        return true;
    }
    }
    return false;
    
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void banner(){
    cout << "***********************" << endl;
    cout << "*   *JOGO DA FORCA*   *" << endl;
    cout << "* *********************" << endl;

}
void imprime_erros(){
    cout << "chutes errados: ";
    for(char letra: chutes_errados){
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra(){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }

    }
}

void chutar(){
        char chute;
    cout << endl << "seu chute: ";
    cin >> chute;

    chutou[chute] = true;
    if(letra_existe(chute)){
        cout <<"voce acertou, seu chute esta na palavra" << endl << endl;
    }

    else{
        cout <<"voce errou, seu chute nao esta na palavra" << endl;
        chutes_errados.push_back(chute);
        cout << endl << endl;
    }
}
vector<string> le_arquivo(){
    ifstream arquivo;
    arquivo.open("palavras.txt");

    int qtd_palavra;
    arquivo >> qtd_palavra;
        if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo palavras.txt" << endl;
        exit(0);
    }

    vector<string> palavra_arquivo;
    
    for (int i=0; i<qtd_palavra;i++){
        string palavra_lida;
        arquivo >> palavra_lida;
        palavra_arquivo.push_back(palavra_lida);
    }
    arquivo.close();
    return palavra_arquivo;
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand (time(NULL));
    int indice_sorteado = rand() %palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}


void adiciona_palavra(){
    cout << "digite a nova palavra, (somente letras maiusculas)";
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);

}


int main(){
    
    banner();
    le_arquivo();
    sorteia_palavra();
    while(nao_acertou() && nao_enforcou()){
    
    imprime_palavra();
    imprime_erros();
    chutar();

    }
    cout << "Fim de jogo!" << endl;
    if(nao_acertou()){
        cout << "voce perdeu! tente novamente" << endl << endl;
        cout << "a palavra secreta era: " << palavra_secreta << endl;
    }
    else{
        cout << "Parabens! voce adivinhou a palavra secreta";
        cout << "voce desejaria adicionar uma nova palavra ao banco de dados? (S/N)" << endl;
        char resposta;
        cin >> resposta;

        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
}