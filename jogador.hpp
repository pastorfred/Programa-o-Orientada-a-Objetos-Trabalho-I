//Leonardo Chou da Rosa
//l.chou@edu.pucrs.br
//Trabalho 1 de Programação Orientada a Objetos
//Professor Roland Teodorowitsch

#include <string>

using namespace std;

//classe para definir as variaveis e os metodos que afetam o usuario
class jogador {
private:
    int qBolasj; //quantidade de bolas do jogador
    string nome; //nome do jogador

public:
    jogador(); //define o nome e a quantidade de bolas padrão do jogador (15)
    int obtemNumBolasJ(); //obtem número de bolas que o jogador tem
    void defineNumBolasJ(int d); //define o numero de bolas que o jogador tem
    string obtemNome(); //obtem o nome do jogador
    void defineNome(string n); //define o nome do jogador
};