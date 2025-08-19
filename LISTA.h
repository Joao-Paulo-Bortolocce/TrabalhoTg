#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
    char rotulo[TFN];
    int peso;
    struct lista *prox;
};

typedef struct lista TpLista;

TpLista* NovaCaixa(char rotulo[TFN], int peso) {
    TpLista *nova = (TpLista*)malloc(sizeof(TpLista));
    strcpy(nova->rotulo,rotulo);
    nova->peso=peso;
    nova->prox=NULL;
    return nova;
}

char verificaDuplo(char rotulos[TFL][TFN],int &tl,char rotulo[TFN]) { // verifica se ja não houve ligação com o nó, caso não insere na lista de verificação
    int pos;
    for (pos=0;pos<tl && stricmp(rotulos[pos],rotulo);pos++);
    if (pos==tl) {
        strcpy(rotulos[tl++],rotulo);
        return 1;
    }
    return 0;
}

char verificaSimplesLista(TpLista *listas[TFL],char nos[TFL][TFN],int tl) {
    char rotulos[TFL][TFN],flag=1;
    TpLista *aux;
    int pos,tlAux;
    for (pos=0;pos<tl && flag;pos++) {
        aux=listas[pos];
        tlAux=0;
        while (aux!=NULL && flag) {
            if (stricmp(aux->rotulo,nos[pos])) {
                flag=verificaDuplo(rotulos,tlAux,aux->rotulo);
            }
            else
                flag=0;
        }
    }
    return flag;
}

char verificaOrientadoLista(TpLista *listas[TFL],char nos[TFL][TFN],int tl) {
    char flag=0;
    TpLista *aux,*busca;
    int i,j;
    for (i=0;i<tl && !flag;i++) {
        aux=listas[i];
        while (aux!=NULL && !flag) {
            for (j=0;j<tl && stricmp(nos[j],aux->rotulo);j++);
            busca=listas[j];
            while (busca!=NULL && stricmp(busca->rotulo,nos[i]))
                busca=busca->prox;
            if (busca!=NULL)
                flag=1;
        }
    }
    return flag;
}

int verificaRegularLista(TpLista *lista[TFL],char nos[TFL][TFN], int tl, char orientado) {
    int recepcao[TFL]={};
    int regularidade=0,cont;
    TpLista *aux;
    if (orientado) {
        aux=TpLista[0];
        while (aux!=NULL) {
            aux=aux->prox;
            regularidade++;
        }
        cont=regularidade;
        for (i=1;i<tl && cont==regularidade;i++) {
            aux=TpLista[i];
            cont=0;
            while (aux!=NULL) {
                aux=aux->prox;
                cont++;
            }
        }
        return regularidade==cont ? regularidade: 0;
    }
    else {
        for (i=0;i<tl;i++) {
            aux=lista[i];
            while (aux!=NULL) {
                for (j=0;j<tl && stricmp(nos[j],aux->rotulo);j++);
                recepcao[j]++;
                aux=aux->prox;
            }
        }
        for (i=1;i<tl && recepcao[j]==recepcao[0];i++);
        return i==tl? recepcao[0]:0;
    }
}

char verificaCompletoLista(TpLista *lista[TFL], int tl) {
    int i,cont=tl;
    TpLista *aux;
    for (i=0;i<tl && cont==tl;i++) {
        aux=lista[i];
        cont=0;
        while (aux!=NULL) {
            cont++;
            aux=aux->prox;
        }
    }
    return cont==tl;
}

void inserir(TpLista *listas[TFL], int i, char rotulo[TFN], int peso) {
    TpLista *nova=NovaCaixa(rotulo,peso),*aux;
    if (listas[i]==NULL)
        listas[i]=nova;
    else {
        aux=listas[i];
        while (aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=nova;
    }
}

void exibeLista(TpLista *listas[TFL],char nos[TFL][TFN], int tl){
    int i,j;
    TpLista *aux;
    printf("\t");
    for(i=0;i<tl;i++)
        printf("%s  -> ",nos[i]);
    printf("\n");
    for(i=0;i<tl;i++)
    {
        aux=listas[i];
        while (aux!=NULL) {
            printf("%s, %d  ->  ",aux->rotulo,aux->peso);
            aux=aux->prox;
        }
        printf("NULL\n");
    }
}

int lerLista(TpLista *listas[TFL],char nos[TFL][TFN]) {
    int tl;
    FILE*ponteiro=fopen("matriz.txt","r");
    char carac[TFN],linha[TFL*TFL],num[TFN];
    int i,j,l,c;
    if(ponteiro!=NULL){
        fgets(linha,TFL*TFL,ponteiro);
        tl=0;
        while (!feof(ponteiro)) {
            for (i=0;linha[i]!=' ' && linha[i]!='\n';i++)
                carac[i]=linha[i];
            carac[i]='\0';
            strcpy(nos[tl],carac);
            for (;i<strlen(linha);i++) {
                for (j=0;linha[i]!=',';i++,j++)
                    carac[j]=linha[i];
                carac[j]='\0';
                i++;
                for (j=0;linha[i]!=' ' && linha[i]!='\n';i++,j++)
                    num[j]=linha[i];
                num[j]='\0';
                inserir(listas,tl,carac,atoi(num));
            }
            tl++;
            fgets(linha,TFL*TFL,ponteiro);
        }
    }
    return tl;
}