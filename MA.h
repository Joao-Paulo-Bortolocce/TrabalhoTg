char verificaSimplesAdjacencia(int mat[TFL][TFC], int tl){
    int i;
    for(i=0;i<tl && mat[i][i]==0;i++);
    return i==tl;
}

char verificaRegularAdjacencia(int mat[TFL][TFC], int tl){
    int i,j,soma=0,aux;
    for(j=0;j<tl;j++)
        soma+=mat[0][j];
    aux=soma;
    for(i=1;i<tl && aux==soma;i++){
        aux=0;
        for(j=0;j<tl;j++)
            aux+=mat[i][j];
    }
    return aux==soma ? soma : 0;
}

char verificaOrientadoAdjacencia(int mat[TFL][TFC], int tl){
    int i,j;
    char flag=0;
    for(i=0;i<tl-1 && !flag;i++)
        for(j=i+1;j<tl && !flag;j++)
            if(mat[i][j]!=mat[j][i])
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
    printf("\t");
    for(i=0;i<tl;i++)
        printf("%s\t",nos[i]);
    printf("\n");
    for(i=0;i<tl;i++)
    {
        printf("%s\t",nos[i]);
        for(j=0;j<tl;j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
}


int lerMA(int mat[TFL][TFC],char nos[TFL][TFN]){
    int tl;
    FILE*ponteiro=fopen("matriz.txt","r");
    char carac[TFN],cara,linha[TFL*TFL];
    int i,j,l,c;
    if(ponteiro!=NULL){
        fgets(linha,TFL*TFL,ponteiro);
        if(!feof(ponteiro)){
            for(tl=0,i=0,j=0;i<strlen(linha);i++){
                if(linha[i]==',' ||linha[i]=='\n'){
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
                if(linha[i]==',' ||linha[i]=='\n'){
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
