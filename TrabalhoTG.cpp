#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TFL 10
#define TFC 10
#define TFN 20

#include"MA.h"
#include"MI.h"

int main(){
	char op=2;
    int mi[TFL][TFC*TFC],ma[TFL][TFC],tl,reg;
    char nos[TFL][TFN];
    char arestas[TFC*TFC][TFN];
	// char op=menu();
	switch(op){
		case 1: //Matriz MA

			tl=lerMA(ma,nos);
			exibeMA(ma,nos,tl);
			if(verificaSimplesAdjacencia(ma,tl))
			    printf("\nÉ simples\n");
	        else
	            printf("\nNão é simples\n");
	        reg=verificaRegularAdjacencia(ma,tl);
			if(reg)
			    printf("\nÉ regular %d\n",reg);
	        else
	            printf("\nNão é regular\n");

	        if(verificaOrientadoAdjacencia(ma,tl))
			    printf("\nÉ orientado\n");
	        else {
                printf("\nNão é orientado\n");
	            if(verificaCompletoAdjacencia(ma,tl))
	                printf("\nÉ completo => K%d\n",tl);
	            else
	                printf("\nNão é completo\n");
            }
			break;
	    case 2: //Matriz Mi

	        int tll,tlc;
	        lerMI(mi,nos,arestas,tll,tlc);
	        exibeMI(mi,nos,arestas,tll,tlc);
	        if(verificaSimplesMI(mi,tll,tlc))
	            printf("\nÉ simples\n");
	        else
	            printf("\nNão é simples\n");


	        if(verificaOrientadoMI(mi,tll,tlc)) {
                printf("\nÉ orientado\n");
	            int reg=verificaRegularMI(mi,tl,tlc,0);
	            if(reg) {

                    printf("\nÉ regular chegada %d\n",reg);
	                reg=verificaRegularMI(mi,tl,tlc,0);
	                if(reg)
	                    printf("É regular de saida %d\n",reg);
                }
                else {
                    reg=verificaRegularMI(mi,tl,tlc,0);
                    if(reg)
                        printf("É regular de saida%d\n",reg);
	                else
	                    printf("\nNão é regular\n");
                }
            }
            else {
	            printf("\nNão é orientado\n");
	            if(verificaCompletoMI(mi,tll,tlc))
	                printf("\nÉ completo => K%d\n",tl);
	            else
	                printf("\nNão é completo\n");
	        }
	        break;

	}
}
