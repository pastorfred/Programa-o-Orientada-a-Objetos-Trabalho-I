#Makefile do jogo Speculate para o Trabalho 1 de Programação Orientada a Objetos
#Desenvolvido pelo aluno Leonardo Chou da Rosa
#l.chou@edu.pucrs.br

Speculate=jogo
CFLAGS=-c -std=c++11

all:			${Speculate}

${Speculate}: 	main.o jogador.o computador.o tabuleiro.o
				@g++ main.o jogador.o computador.o tabuleiro.o -o ${Speculate}

main.o: 		main.cpp execute.cpp execute.hpp
				@g++ ${CFLAGS} main.cpp

jogador.o:		jogador.cpp jogador.hpp
				@g++ ${CFLAGS} jogador.cpp

computador.o:	computador.cpp computador.hpp
				@g++ ${CFLAGS} computador.cpp

tabuleiro.o:	tabuleiro.cpp tabuleiro.hpp
				@g++ ${CFLAGS} tabuleiro.cpp

run:			${Speculate}
				@./${Speculate}

clean:			
				@rm -f main.o jogador.o computador.o tabuleiro.o ${Speculate}