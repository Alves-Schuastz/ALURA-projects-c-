#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(){
    cout << "************************************" << endl; 
    cout << "*Bem-vindos ao jogo da adivinhacao!*" << endl;
    cout << "************************************" << endl;

    cout << "escolha o nivel de dificuldade" << endl;

    cout <<"facil(f)" << endl;
    cout <<"medio(m)" << endl;
    cout <<"dificil(d)" << endl;
    char dificuldade;
    cin >> dificuldade;

    int numero_tentativa;
    if(dificuldade=='f'){
       numero_tentativa = 15;
    }

    else if(dificuldade=='m'){
       numero_tentativa = 10;
    }

    else if(dificuldade=='d'){
       numero_tentativa = 5;
    }
    int tentativas = 0;

    srand(time(NULL));
    const int N_SECRET = rand() % 100;

    bool nao_acertou = true;

    double pontos = 1000.0;
    // while (nao_acertou){}
    for(tentativas = 1; tentativas<=numero_tentativa; tentativas++){
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute?";
        cin >> chute;

        cout << "O valor do seu chute é: " << chute << endl;
        bool acertou = chute == N_SECRET;
        bool maior = chute > N_SECRET;

        double pontos_perdidos = abs (chute - N_SECRET) / 2.0;
        pontos = pontos - pontos_perdidos;
        if (acertou)
        {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break; 
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else
        {
             cout << "Seu chute foi menor que número secreto!" << endl;
        }

}
cout << "Fim de jogo!" << endl;
if(nao_acertou){
    cout << "voce perdeu! tente novamente" << endl;
}

else{
cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
cout.precision(2);
cout << fixed;
cout << "su pontuacao foi de: " << pontos;
}
}

