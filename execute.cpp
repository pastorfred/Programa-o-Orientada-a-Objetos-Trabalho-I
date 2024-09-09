//Leonardo Chou da Rosa
//l.chou@edu.pucrs.br
//Trabalho 1 de Programação Orientada a Objetos
//Professor Roland Teodorowitsch

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include "execute.hpp"

using namespace std;

//construtor
execute::execute(string n) {
    rodadas = 1;
    usuario.defineNome(n);
}

//getter e setter da quantidade de rodadas
int execute::obtemNumRodadas() { return rodadas; }
void execute::defineNumRodadas(int r) { rodadas = r; }

//metodo que executa quando e a vez do usuario jogar
void execute::playerTurn() {
    //variavel que define quantas vezes o jogador vai lançar o dado
    int lancamentos = 0;
    cout << "Digite quantas vezes voce quer jogar o dado:" << endl;
    cin >> lancamentos;

    //se o usuario escrever um numero menor ou igual a 0 e maior que a quantidade de bolas, o programa pede para ele digitar um novo numero
    int aux = usuario.obtemNumBolasJ();
    if ((lancamentos <= 0) || (lancamentos > aux)) {
        cout << "Digite um numero valido." << endl;
        playerTurn();
    }

    //se o numero de lançamentos esta dentro da quantidade de bolas do usuario, executa o codigo
    if ((lancamentos > 0) && (lancamentos <= aux)) {
        while (lancamentos > 0)
        {
            //a variavel i recebe um valor aleatorio entre 1 e 6
            int i = 1 + (rand() % 6);
            cout << "Voce rolou um " << i << "!" << endl;

            //se o valor de i for 6, remova uma bola do usuario e adiciona ela para a variavel center (centro do tabuleiro), conforme no enunciado
            if (i == 6) {
                tab.defineCenter(tab.obtemCenter() + 1);
                usuario.defineNumBolasJ(usuario.obtemNumBolasJ() - 1);
                cout << "Voce se livrou de uma bola!" << endl;
            }
            //se o valor de i não for 6, faz o seguinte
            else {
                //se o tabuleiro estiver vazio no valor de i, o valor no tabuleiro é aumentado por 1 e o usuario perde uma bola, conforme no enunciado
                if (tab.tab[i - 1] == 0) {
                    tab.tab[i - 1] += 1;
                    usuario.defineNumBolasJ(usuario.obtemNumBolasJ() - 1);
                    cout << "Voce se livrou de uma bola!" << endl;
                }
                else {
                    //se o tabuleiro estiver com uma bola no valor de i, o valor no tabuleiro é reduzido por 1 e o usuario recebe uma bola, conforme no enunciado
                    if (tab.tab[i - 1] == 1) {
                        tab.tab[i - 1] -= 1;
                        usuario.defineNumBolasJ(usuario.obtemNumBolasJ() + 1);
                        cout << "Voce coletou uma bola do tabuleiro." << endl;
                    }
                }
            }
            lancamentos--;

            //imprime o tabuleiro (para ajudar o usuario a visualizar o jogo)
            cout << tab.str() << endl;

            //insere um delay em cada iteração do while, para ficar mais facil de acompanhar o jogo
            Sleep(2000);
        }
    }
}

void execute::cpuTurn() {
    int aux = cpu.obtemNumBolasC();
    cout << tab.str() << endl;

    //mesma coisa que o playerTurn, só que aplica para o computador
    while (aux > 0) {
        int i = 1 + (rand() % 6);
        cout << "O computador rodou um " << i << "." << endl;
        if (i == 6) {
            tab.defineCenter(tab.obtemCenter() + 1);
            cpu.defineNumBolasC(cpu.obtemNumBolasC() - 1);
            cout << "O computador se livrou de uma bola." << endl;
        }
        else {
            if (tab.tab[i - 1] == 0) {
                tab.tab[i - 1] += 1;
                cpu.defineNumBolasC(cpu.obtemNumBolasC() - 1);
                cout << "O computador se livrou de uma bola." << endl;
            }
            else {
                if (tab.tab[i - 1] == 1) {
                    tab.tab[i - 1] -= 1;
                    cpu.defineNumBolasC(cpu.obtemNumBolasC() + 1);
                    cout << "O computador coletou uma bola do tabuleiro." << endl;
                }
            }
        }
        aux--;
        cout << tab.str() << endl;
        Sleep(2000);
    }

    //já que o computador sempre joga depois do usuario, a quantidade de rodadas é aumentada por 1 após a vez do computador
    defineNumRodadas(obtemNumRodadas() + 1);
}

//metodo que confere se alguem venceu o jogo
int execute::isWinner() {
    //se o usuario venceu (usuario não tem mais bolas na mão), retorna 1
    if (usuario.obtemNumBolasJ() == 0) {
        return 1;
    }
    
    //se o computador venceu (computador não tem mais bolas na mão), retorna 0
    if (cpu.obtemNumBolasC() == 0) {
        return 0;
    }

    //se nenhum dos dois venceu, retorna 2
    return 2;
}

//metodo que imprime a rodada atual, a quantidade de bolas do usuario, do computador e quantas bolas ha no centro do tabuleiro
string execute::str() {
    stringstream ss;
    ss << "Rodada " << obtemNumRodadas() << ":" << endl;
    ss << "Numero de bolas do jogador: " << usuario.obtemNumBolasJ() << endl;
    ss << "Numero de bolas do computador: " << cpu.obtemNumBolasC() << endl;
    ss << "Numero de bolas no centro do tabuleiro: " << tab.obtemCenter() << endl;
    return ss.str();
}

//metodo que inicia o jogo
void execute::comeca() {
    //define se o usuario gostaria de ver o ranking dos melhores resultados ou nao
    char r;

    //inicia o gerador de numeros aleatorios
    srand(time(NULL));

    cout << "Bem vindo, " << usuario.obtemNome() << "!" << endl;
    cout << "Voce gostaria de olhar o ranking dos melhores resultados? S/N ";
    cin >> r;

    //se o usuario inserir "S" ou "s", os melhores resultados são mostrados. Qualquer outra letra o ranking não é mostrado e o jogo inicia
    if (r == 's' || r == 'S') {
        //se o metodo organizaRank retornar 0 (se não existe arquivo "ranking.txt"), o programa avisa que não há ranking e o jogo inicia
        if (organizaRank() == 0) {
            cout << "O ranking esta vazio." << endl
                 << endl;
        } else {mostraLeaderboard(); cout << endl;} //se o arquivo "ranking.txt" existe, os melhores resultados são mostrados
    }
    else {
        cout << endl;
    }

    //enquanto 1, o jogo é executado
    while (1) {
        //imrpime a atual rodada, a quantidade de bolas do usuario, do computador e quantas bolas ha no centro
        cout << str();
        cout << "E a sua vez de jogar: " << endl;

        //se é a primeira rodada, mostra o tabuleiro antes da vez do usuario
        if (rodadas == 1) {
            cout << tab.str() << endl;
        }

        //roda o metodo playerTurn, que indica a vez do usuario
        playerTurn();

        //se o usuario venceu, roda o metodo criaLeaderboard, que cria/reescreve os melhores resultados e o jogo acaba
        if (isWinner() == 1) {
            criaLeaderboard();
            cout << "Acabou!" << endl;
            break;
        }

        //roda o metodo cpuTurn, que indica a vez do computador
        cout << "Acabou a sua vez. Agora e a vez do computador: ";
        cpuTurn();

        //se o computador venceu, o jogo acaba
        if (isWinner() == 0) {
            cout << endl;
            cout << "O computador venceu." << endl;
            break;
        }
        cout << "Proxima rodada iniciando..." << endl;

        //apos cada rodada, há um delay e o tabuleiro é imprimido
        Sleep(2000);
        cout << tab.str() << endl;
    }
}

void execute::criaLeaderboard() {
    //se o arquivo não existe, cria
    ifstream test;
    test.open("ranking.txt", ios::in);
    if (!test.good()) {
        test.close();
        ofstream crialeaderboard;
        crialeaderboard.open("ranking.txt", ios::out);
        crialeaderboard << usuario.obtemNome() << " " << rodadas;
        crialeaderboard.close();
        return;
    }

    //abre arquivo para leitura
    ifstream leleaderboard;
    leleaderboard.open("ranking.txt", ios::in);

    //define dois vetores auxiliares
    int ordem[11] = {0};
    string nomes[11];

    //insere os valores do arquivo nas variaveis auxiliares
    for (int i = 0; leleaderboard.good(); i++) {
        leleaderboard >> nomes[i] >> ordem[i];
    }

    //termina de ler o arquivo
    leleaderboard.close();

    //abre o arquivo para escrita
    ofstream reescreveleaderboard;
    reescreveleaderboard.open("ranking.txt", ios::out);

    //reescreve o arquivo com o novo vencedor
    for (int i = 0; i < sizeof(ordem)/sizeof(ordem[0]); i++) {
        if (ordem[i] == 0) {break;}
        reescreveleaderboard << endl;
        reescreveleaderboard << nomes[i] << " " << ordem[i];
    }
    reescreveleaderboard << endl << usuario.obtemNome() << " " << rodadas;

    //termina de escrever o novo arquivo
    reescreveleaderboard.close();

    //chama o metodo organizaRank, que arranja os vencedores de forma crescente
    organizaRank();
}

//metodo que organiza o arquivo "ranking.txt" para que os vencedores estejam organizados em ordem crescente
int execute::organizaRank() {
    //abre o arquivo "ranking.txt" para leitura
    ifstream releleaderboard;
    releleaderboard.open("ranking.txt", ios::in);

    //se nao existir o arquivo ou há algum erro, retorna 0
    if (!releleaderboard.good()) {return 0;}

    //variaveis auxiliares
    string nomes[11];
    int ordem[11] = {0};

    //lê e coloca os conteudos dos arquivos nas variaveis aux
    for (int i = 0; releleaderboard.good() && i < 11; i++) {
        releleaderboard >> nomes[i] >> ordem[i];
    }

    //organiza os conteudos do arquivo
    for (int i = 0; i < sizeof(ordem)/sizeof(ordem[0]) && ordem[i] != 0; i++) {
        for (int a = 0; a < sizeof(ordem)/sizeof(ordem[0]) && ordem[i] != 0; a++) {
        if (ordem[i] < ordem[a]) {
            int aux = ordem[i];
            string temp = nomes[i];
            ordem[i] = ordem[a];
            nomes[i] = nomes[a];
            ordem[a] = aux;
            nomes[a] = temp;
            }
        }
    }

    //fecha o arquivo de leitura
    releleaderboard.close();

    //abre o arquivo para escrita novamente para leitura
    ofstream rereescreveleaderboard;
    rereescreveleaderboard.open("ranking.txt", ios::out);

    //reescreve o arquivo em ordem
    for (int i = 0; rereescreveleaderboard.good() && i < 10; i++) {
        rereescreveleaderboard << nomes[i] << " " << ordem[i] << endl;
    }

    //fecha o arquivo
    rereescreveleaderboard.close();
    return 1;
}

void execute::mostraLeaderboard() {
    //abre o arquivo para leitura
    ifstream leleaderboard; 
    leleaderboard.open("ranking.txt", ios::in);

    //le e exibe os valores dentro do arquivo
    for (int i = 0; leleaderboard.good() && i < 10; i++) {
        string aux;
        int temp;
        leleaderboard >> aux;
        leleaderboard >> temp;
        if (temp == 0) {break;}
        cout << (i + 1) << " - " << aux << " venceu em " << temp << " rodadas." << endl;
    }

    //fecha o arquivo
    leleaderboard.close();
}
