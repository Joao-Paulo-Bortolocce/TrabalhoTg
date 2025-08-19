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
#include"LISTA.h"
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
			gotoxy(18, 5);
			printf("MATRIZ DE ADJACENCIA");

			textbackground(14);
			textcolor(0);

			tl = lerMA(ma, nos);
			exibeMA(ma, nos, tl);
			flagSimples = verificaSimplesAdjacencia(ma, tl) if (flagSimples)
				printf("\n\tE simples\n");
			else printf("\n\tNao e simples\n");
			reg = verificaRegularAdjacencia(ma, tl);
			if (reg)
				printf("\n\tE regular %d\n", reg);
			else
				printf("\n\tNao e regular\n");

			flagOrientado = verificaOrientadoAdjacencia(ma, tl) if (flagOrientado)
				printf("\n\tE orientado\n");
			else
			{
				printf("\n\tNao e orientado\n");
			}
			if (flagSimples && flagOrientado && verificaCompletoAdjacencia(ma, tl))
				printf("\n\tE completo => K%d\n", tl);
			else
				printf("\n\tNao e completo\n");

			getch();
			break;
		case 'I':
			QuadroInfo();
			textbackground(14);
			textcolor(0);
			gotoxy(18, 5);
			printf("MATRIZ DE INCIDENCIA");

			textbackground(14);
			textcolor(0);

			int tll, tlc;
			lerMI(mi, nos, arestas, tll, tlc);
			exibeMI(mi, nos, arestas, tll, tlc);
			flagSimples=verificaSimplesMI(mi, tll, tlc);
			if (flagSimples)
				printf("\n\tE simples\n");
			else
				printf("\n\tNao e simples\n");

			flagOrientado=verificaOrientadoMI(mi, tll, tlc);
			if (flagOrientado)
			{
				printf("\n\tE orientado\n");
				int reg = verificaRegularMI(mi, tl, tlc, 0);
				if (reg)
				{

					printf("\n\tE regular chegada %d\n", reg);
					reg = verificaRegularMI(mi, tl, tlc, 0);
					if (reg)
						printf("\n\tE regular de saida %d\n", reg);
				}
				else
				{
					reg = verificaRegularMI(mi, tl, tlc, 0);
					if (reg)
						printf("\n\tE regular de saida%d\n", reg);
					else
						printf("\n\tNao e regular\n");
				}
			}
			else
			{
				printf("\nNao e orientado\n");
			}
			if (flagOrientado && flagSimples && verificaCompletoMI(mi, tll, tlc))
				printf("\nE completo => K%d\n", tl);
			else
				printf("\nNao e completo\n");

			getch();
			break;
		case 'L':
			QuadroInfo();
			textbackground(14);
			textcolor(0);
			gotoxy(26, 5);
			printf("LISTA");
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
