//Leonardo Chou da Rosa
//l.chou@edu.pucrs.br
//Trabalho 1 de Programação Orientada a Objetos
//Professor Roland Teodorowitsch

#include <string>

using namespace std;

//classe tabuleiro que contem variaveis e metodos que afetam o tabuleiro do jogo
class tabuleiro {
private:
    int center; //numero de bolas no centro do tabuleiro

public:
    int tab[5]; //vetor que indica as posicoes do tabuleiro (public para facilitar acesso)
    tabuleiro(); //construtor tabuleiro
    int obtemCenter(); //metodo para obter o numero de bolas no centro do tabuleiro
    void defineCenter(int c); //metodo para definir o numero de bolas no centro do tabuleiro
    string str(); //metodo para imprimir o tabuleiro
};