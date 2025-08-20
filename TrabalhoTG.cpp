#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

#define TFL 10
#define TFC 10
#define TFN 20

#include "MA.h"
#include "MI.h"
#include "LISTA.h"
#include "Molduras.h"

void Executar()
{
	char op, flagSimples, flagOrientado;
	int mi[TFL][TFC * TFC], ma[TFL][TFC], tl, reg;
	char nos[TFL][TFN];
	char arestas[TFC * TFC][TFN];
	do
	{
		op = Quadro();
		switch (op)
		{
			case 'A':
				QuadroInfo();
				textbackground(14);
				textcolor(0);
				gotoxy(3, 3); printf("-> MATRIZ DE ADJACENCIA <-");
				gotoxy(3, 4); printf("RESPOSTA:");
	
				textbackground(14);
				textcolor(0);
	
				tl = lerMA(ma, nos);
				exibeMA(ma, nos, tl);
				flagSimples = verificaSimplesAdjacencia(ma, tl);
				if (flagSimples){
					gotoxy(3, 5); 
					printf(" - E simples");
				}	
				else{
					gotoxy(3, 5);
					printf(" - Nao e simples");	
				} 
				reg = verificaRegularAdjacencia(ma, tl);
				if (reg){
					gotoxy(3, 6);
					printf(" - E regular %d", reg);
				}	
				else{
					gotoxy(3, 6);
					printf(" - Nao e regular");
				}
					
	
				flagOrientado = verificaOrientadoAdjacencia(ma, tl) ;
				if (flagOrientado){
					gotoxy(3, 7);
					printf(" - E orientado");
				}
					
				else
				{
					gotoxy(3, 7);
					printf(" - Nao e orientado");
				}
				if (flagSimples && !flagOrientado && reg && verificaCompletoAdjacencia(ma, tl)){
					gotoxy(3, 8);
					printf(" - E completo => K%d", tl);
				}
					
				else{
					gotoxy(3, 8);
					printf(" - Nao e completo");
				}
				getch();
			break;
			case 'I':
				QuadroInfo();
				textbackground(14);
				textcolor(0);
				gotoxy(3, 3); printf("-> MATRIZ DE INCIDENCIA <-");
				gotoxy(3, 4); printf("RESPOSTA:");
	
				textbackground(14);
				textcolor(0);
	
				int tll, tlc;
		 		lerMI(mi, nos, arestas, tll, tlc);
				exibeMI(mi, nos, arestas, tll, tlc);
				flagSimples=verificaSimplesMI(mi, tll, tlc);
				if (flagSimples){
					gotoxy(3, 5); 
					printf(" - E simples");
				}
				else{
					gotoxy(3, 5);
					printf(" - Nao e simples");	
				} 
	
				flagOrientado=verificaOrientadoMI(mi, tll, tlc);
				if (flagOrientado)
				{
					gotoxy(3, 6); printf(" - E orientado");
					
					int reg = verificaRegularMI(mi, tl, tlc, 0);
					if (reg)
					{
	
						gotoxy(3, 7); printf(" - E regular chegada %d", reg);
						reg = verificaRegularMI(mi, tl, tlc, 1);
						if (reg){
							gotoxy(3, 7);
							printf(" - E regular de saida %d", reg);
						}	
					}
					else
					{
						reg = verificaRegularMI(mi, tl, tlc, 1);
						if (reg){
							gotoxy(3, 7);
							printf(" - E regular de saida%d", reg);
						}
							
						else{
							gotoxy(3, 7);
							printf(" - Nao e regular");
						}
					}
				}
				else
				{
					reg = verificaRegularMI(mi, tl, tlc,0);
					if (reg){
						gotoxy(3, 7);
						printf(" - E regular %d", reg);
					}
						
					else{
						gotoxy(3, 7);
						printf(" - Nao e regular");
					}
					gotoxy(3, 6); printf(" - Nao e orientado");
				}
				if (!flagOrientado && flagSimples && reg && verificaCompletoMI(mi, tll, tlc)){
					gotoxy(3, 8);
					printf(" - E completo => K%d", tl);
				}
				else{
					gotoxy(3,8);
					printf(" - Nao e completo");
				}
				getch();
			break;
			case 'L':
				QuadroInfo();
				textbackground(14);
				textcolor(0);
				gotoxy(3, 3); printf("-> LISTA <-");
				gotoxy(3, 4); printf("RESPOSTA:");
				
				TpLista *listas[TFL];
				tl=lerLista(listas,nos);
				exibeLista(listas,nos,tl);
				
				flagSimples=verificaSimplesLista(listas, nos, tl);
				if (flagSimples){
					gotoxy(3, 5);
					printf(" - E simples");
				}
					
				else{
					gotoxy(3, 5);
					printf(" - Nao e simples");
				}
					
	
				flagOrientado=verificaOrientadoLista(listas,nos,tl);
				if (flagOrientado)
				{
					gotoxy(3, 6); printf(" - E orientado");
					int reg = verificaRegularLista(listas,nos,tl,0);
					if (reg)
					{
	
						gotoxy(3, 7);
						printf(" - E regular chegada %d", reg);
						reg = verificaRegularLista(listas,nos,tl,1);
						if (reg){
							gotoxy(3, 7);
							printf(" - E regular de saida %d", reg);
						}
							
					}
					else
					{
						reg = verificaRegularLista(listas,nos,tl,1);
						if (reg){
							gotoxy(3, 7);
							printf(" - E regular de saida %d", reg);
						}
							
						else{
							gotoxy(3, 7);
							printf(" - Nao e regular");
						}
							
					}
				}
				else
				{
					gotoxy(3, 6);
					printf(" - Nao e orientado");
					reg = verificaRegularLista(listas,nos,tl,0);
					if (reg){
						gotoxy(3, 7);
						printf(" - E regular %d", reg);
					}	
					else{
						gotoxy(3, 7);
						printf(" - Nao e regular");
					}
				}
				if (!flagOrientado && flagSimples && reg && verificaCompletoLista(listas, tl)){
					gotoxy(3, 8);
					printf(" - E completo => K%d", tl);
				}
				else{
					gotoxy(3, 8);
					printf(" - Nao e completo");
				}
				getch();
			break;
		}
	} while (op != 27);
}

int main()
{

	char op = 2;
	int mi[TFL][TFC * TFC], ma[TFL][TFC], tl, reg;
	char nos[TFL][TFN];
	char arestas[TFC * TFC][TFN];
	Executar();
	return 0;
}
