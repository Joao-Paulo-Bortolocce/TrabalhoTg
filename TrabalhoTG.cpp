#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TFL 10
#define TFC 10
#define TFN 20

#include"MA.h"

int main(){
	char op=1;
	// char op=menu();
	switch(op){
		case 1: //Matriz MA
			int mat[TFL][TFC];
			char nos[TFL][TFN];
			int tl=lerMA(mat,nos);
			exibeMA(mat,nos,tl);
			if(verificaSimplesAdjacencia(mat,tl))
			    printf("\nÉ simples\n");
	        else
	            printf("\nNão é simples\n");
	        int reg=verificaRegularAdjacencia(mat,tl);
			if(reg)
			    printf("\nÉ regular %d\n",reg);
	        else
	            printf("\nNão é regular\n");

	        if(verificaOrientadoAdjacencia(mat,tl))
			    printf("\nÉ orientado\n");
	        else {
                printf("\nNão é orientado\n");
	            if(verificaCompletoAdjacencia(mat,tl))
	                printf("\nÉ completo => K%d\n",tl);
	            else
	                printf("\nNão é completo\n");
            }
			break;
	    case 2: //Matriz Mi
	        int mat[TFL][TFC];
	        char nos[TFL][TFN];
	        int tl=lerMA(mat,nos);
	        exibeMA(mat,nos,tl);
	        if(verificaSimplesAdjacenciaMI(mat,tl))
	            printf("\nÉ simples\n");
	        else
	            printf("\nNão é simples\n");
	        int reg=verificaRegularAdjacenciaMI(mat,tl);
	        if(reg)
	            printf("\nÉ regular %d\n",reg);
	        else
	            printf("\nNão é regular\n");

	        if(verificaOrientadoAdjacenciaMI(mat,tl))
	            printf("\nÉ orientado\n");
	        else {
	            printf("\nNão é orientado\n");
	            if(verificaCompletoAdjacenciaMI(mat,tl))
	                printf("\nÉ completo => K%d\n",tl);
	            else
	                printf("\nNão é completo\n");
	        }
	        break;

	}
}
