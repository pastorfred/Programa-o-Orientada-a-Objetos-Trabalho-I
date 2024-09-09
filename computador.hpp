//Leonardo Chou da Rosa
//l.chou@edu.pucrs.br
//Trabalho 1 de Programação Orientada a Objetos
//Professor Roland Teodorowitsch

//classe computador que define as variaveis e os metodos que afetam o computador
class computador {
private:
    int qBolasc; //quantidade de bolas do computador

public:
    computador(); //metodo que define a quantidade de bolas padrão do computador
    int obtemNumBolasC(); //metodo para obter a quantidade de bolas do computador 
    void defineNumBolasC(int d); //metodo para definir a quantidade de bolas do computador
};