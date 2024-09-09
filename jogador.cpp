//Leonardo Chou da Rosa
//l.chou@edu.pucrs.br
//Trabalho 1 de Programação Orientada a Objetos
//Professor Roland Teodorowitsch

#include "jogador.hpp"

using namespace std;

//define o nome e a quantidade de bolas padrão do jogador (15)
jogador::jogador() {
    qBolasj = 15; //quantidade de bolas do usuario
    nome = ""; //nome do usuario
}
int jogador::obtemNumBolasJ() { return qBolasj; } //obtem número de bolas que o jogador tem
void jogador::defineNumBolasJ(int d) { qBolasj = d; } //define quantidade de bolas que o jogador tem
string jogador::obtemNome() { return nome; } //obtem o nome do jogador
void jogador::defineNome(string n) { nome = n; } //define o nome do jogador