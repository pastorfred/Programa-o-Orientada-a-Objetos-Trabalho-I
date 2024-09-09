#include <iostream>

#include "execute.cpp"

using namespace std;

int main() {
    //recebe o nome do usuario
    string n;
    cout << "Digite o seu nome" << endl;
    cin >> n;

    execute jogo(n); //define o nome do usuario com o nome recebido
    jogo.comeca(); //inicia o jogo
    return 0;
}