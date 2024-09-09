//Leonardo Chou da Rosa
//l.chou@edu.pucrs.br
//Trabalho 1 de Programação Orientada a Objetos
//Professor Roland Teodorowitsch

#include <sstream>
#include <string>
#include "tabuleiro.hpp"

using namespace std;

//define o tabuleiro padrao com 3 bolas; elas estão nas casas 1, 3 e 5 conforme o enunciado
//define a quantidade de bolas no centro do tabuleiro
tabuleiro::tabuleiro() {
    tab[0] = 1;
    tab[1] = 0;
    tab[2] = 1;
    tab[3] = 0;
    tab[4] = 1;
    center = 0;
}
int tabuleiro::obtemCenter() { return center; } //obtem o numero de bolas no centro do tabuleiro
void tabuleiro::defineCenter(int c) { center = c; } //define o numero de bolas no centro do tabuleiro
string tabuleiro::str() { //imprime o tabuleiro
    stringstream ss;
    ss << endl
       << "Tabuleiro atual:" << endl
       << "Casa 1:"
       << "[" << tab[0] << "]"
       << " "
       << "Casa 2:"
       << "[" << tab[1] << "]"
       << " "
       << "Casa 3:"
       << "[" << tab[2] << "]"
       << " "
       << "Casa 4:"
       << "[" << tab[3] << "]"
       << " "
       << "Casa 5:"
       << "[" << tab[4] << "]" << endl;
    return ss.str();
}
