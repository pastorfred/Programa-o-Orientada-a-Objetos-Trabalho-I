//Leonardo Chou da Rosa
//l.chou@edu.pucrs.br
//Trabalho 1 de Programação Orientada a Objetos
//Professor Roland Teodorowitsch

#include <iostream>
#include <sstream>
#include <fstream>
#include "computador.hpp"
#include "jogador.hpp"
#include "tabuleiro.hpp"

using namespace std;

//classe execute definda para executar o jogo
class execute {
private:
    int rodadas; //numero da rodada atual
    jogador usuario; //classe jogador com objeto player
    tabuleiro tab; //classe tabuleiro com objeto tab
    computador cpu; //classe computador com objeto cpu

public:
    execute(string n); //construtor que recebe o nome do usuario
    int obtemNumRodadas(); //getter para rodada atual
    void defineNumRodadas(int r); //setter para rodada atual
    void playerTurn(); //metodo para executar a vez de jogar do usuario
    void cpuTurn(); //metodo para executar a vez de jogar do computador
    int isWinner(); //metodo para conferir se algum jogador venceu
    string str(); //metodo para imprimir dados do jogo
    void comeca(); //metodo para iniciar o jogo
    void criaLeaderboard(); //metodo para criar o ranking de melhores jogadores
    void mostraLeaderboard(); //metodo para mostrar os melhores jogadores
    int organizaRank(); //metodo para organizar o ranking de melhores jogadores
};