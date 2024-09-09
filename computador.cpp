//Leonardo Chou da Rosa
//l.chou@edu.pucrs.br
//Trabalho 1 de Programação Orientada a Objetos
//Professor Roland Teodorowitsch

#include "computador.hpp"

//construtor da classe computador
computador::computador() {
    qBolasc = 15; //quantidade de bolas do computador
}
int computador::obtemNumBolasC() { return qBolasc; } //obtem o numero de bolas do computador
void computador::defineNumBolasC(int d) { qBolasc = d; } //define o numero de bolas do computador