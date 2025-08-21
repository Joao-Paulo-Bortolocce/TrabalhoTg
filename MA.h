char verificaSimplesAdjacencia(int mat[TFL][TFC], int tl){
    int i;
    for(i=0;i<tl && mat[i][i]==0;i++);
    return i==tl;
}

int verificaRegularAdjacencia(int mat[TFL][TFC], int tl){
    int i,j,cont=0,aux;
    for(j=0;j<tl;j++)
        if (mat[0][j]!=0)
            cont++;
    aux=cont;
    for(i=1;i<tl && aux==cont;i++){
        aux=0;
        for(j=0;j<tl;j++)
            if (mat[i][j]!=0)
                aux++;
    }
    return aux==cont ? cont : 0;
}

char verificaOrientadoAdjacencia(int mat[TFL][TFC], int tl){
    int i,j;
    char flag=0;
    for(i=0;i<tl-1 && !flag;i++)
        for(j=i+1;j<tl && !flag;j++)
            if(mat[i][j]==0 || mat[j][i]==0)
                flag=1;
    return flag;
}

char verificaCompletoAdjacencia(int mat[TFL][TFC], int tl){
    int i,j;
    char flag=verificaSimplesAdjacencia(mat,tl);
    for(i=0;i<tl-1 && flag;i++)
        for(j=i+1;j<tl && flag;j++)
            if(mat[i][j]==mat[j][i] && mat[i][j]==0)
                flag=0;
    return flag;
}

void exibeMA(int mat[TFL][TFC],char nos[TFL][TFN], int tl){
    int i,j;
    int lin, col, lin2, col2;
	lin = 4, col = 32;
    for(i=0;i<tl;i++, col += 8){
    	gotoxy(col,lin); printf("%s",nos[i]);
    }
    lin = 5, col = 32;
    lin2 = 5, col2 = 30;
    for(i=0;i<tl;i++, lin2++)
    {
        gotoxy(col2,lin2);
        printf("%s",nos[i]);
        for(j=0;j<tl;j++, col += 8){
            gotoxy(col,lin);
            printf("%d",mat[i][j]);
        }
        lin++; col = 32;
    }
    printf("\n");
}


int lerMA(int mat[TFL][TFC],char nos[TFL][TFN]){
    int tl;
    FILE*ponteiro=fopen("ma.txt","r");
    char carac[TFN],cara,linha[TFL*TFL];
    int i,j,l,c;
    if(ponteiro!=NULL){
        fgets(linha,TFL*TFL,ponteiro);
        if(!feof(ponteiro)){
            for(tl=0,i=0,j=0;i<strlen(linha);i++){
                if(linha[i]==' ' ||linha[i]=='\n'){
                    carac[j]='\0';
                    strcpy(nos[tl],carac);
                    tl++;
                    j=0;
                }
                else{
                    carac[j]=linha[i];
                    j++;
                }
            }
        }
        fgets(linha,TFL*TFL,ponteiro);
        l=0;
        while(!feof(ponteiro)){
            c=0;
            for(i=0,j=0;i<strlen(linha);i++){
                if(linha[i]==' ' || linha[i]=='\n' || linha[i]=='\0'){
                    carac[j]='\0';
                    mat[l][c]=atoi(carac);
                    j=0;
                    c++;
                }
                else{
                    carac[j]=linha[i];
                    j++;
                }
            }
            l++;
            fgets(linha,TFL*TFL,ponteiro);
        }
    }
    return tl;
}
