char verificaSimplesMI(int mat[TFL][TFC*TFC], int tll,int tlc){
    int l,c,i,j,cont=2; //c=coluna, l=linha, i=coluna auxiliar, j= linha auxiliar
    char flag=0,flag2;
    for (c=0;c<tlc && cont>1;c++) { //verifica se não há laço
        cont=0;
        for (l=0;l<tll;l++) {
            if (mat[l][c]!=0)
                cont++;
        }
    }
    if (c==tlc)
        flag=1;
    for (l=0;l<tll-1 && flag;l++) {
        flag2=1;
        for (c=0;c<tlc && flag2;c++) {
            if (mat[l][c]!=0) {
                cont=0;
                for (i=c+1;i<tlc && flag2;i++) {
                    if (mat[l][i]!=0) {
                        cont++;
                        for (j=l+1;j<tll && mat[j][c]==mat[j][i];j++);
                        if (j==tll)
                            flag=flag2=0;
                    }
                }
                if (cont<2)
                    flag2=0;
            }
        }
    }
    return flag;
}

int verificaRegularMI(int mat[TFL][TFC*TFC], int tll, int tlc, char orientado) {
    int l,c,cont=0,aux;
    if (orientado) {
        for(c=0;c<tlc;c++)
            if (mat[0][c]<0)
                cont++;
        aux=cont;
        for(l=1;l<tll && aux==cont;l++){
            aux=0;
            for(c=0;c<tlc;c++)
                if (mat[l][c]<0)
                    aux++;
        }
    }
    else {
        for(c=0;c<tlc;c++)
            if (mat[0][c]>0)
                cont++;
        aux=cont;
        for(l=1;l<tll && aux==cont;l++){
            aux=0;
            for(c=0;c<tlc;c++)
                if (mat[l][c]>0)
                    cont++;
        }
    }
    return aux==cont ? cont : 0;
}

char verificaOrientadoMI(int mat[TFL][TFC*TFC], int tll, int tlc) {
    int l,c, cont=0;;
    for (c=0;c<tlc && cont==0;c++) {
        cont=0;
        for (l=0;l<tll;l++) {
            if (mat[l][c]>0)
                cont++;
            else
                if (mat[l][c]<0)
                    cont--;
        }
    }
    return cont==0;
}

char verificaCompletoMI(int mat[TFL][TFC*TFC], int tll, int tlc) {
    int l,c=0,i=tll;
    for (l=0;l<tll-1 && i==tll;l++) {
        for (i=l+1;i<tll && c<tlc;i++) {
            for (c=0;c<tlc && (mat[l][c]==0 || mat[i][c]==0);c++);
        }
    }
    return i==tll;
}

void exibeMI(int mat[TFL][TFC*TFC],char nos[TFL][TFN],char arestas[TFC*TFC][TFN], int tll, int tlc){
    int i,j;
    printf("\t");
    for(i=0;i<tlc;i++)
        printf("%s\t",arestas[i]);
    printf("\n");
    for(i=0;i<tll;i++)
    {
        printf("%s\t",nos[i]);
        for(j=0;j<tlc;j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
}

void lerMI(int mat[TFL][TFC*TFC],char nos[TFL][TFN], char arestas[TFC*TFC][TFN], int &tll, int &tlc){
    FILE*ponteiro=fopen("matriz.txt","r");
    char carac[TFN],linha[TFL*TFL];
    int i,j,l,c;
    if(ponteiro!=NULL){
        fgets(linha,TFL*TFL,ponteiro);
        if(!feof(ponteiro)){
            for(tll=0,i=0,j=0;i<strlen(linha);i++){
                if(linha[i]==' ' ||linha[i]=='\n'){
                    carac[j]='\0';
                    strcpy(nos[tll],carac);
                    tll++;
                    j=0;
                }
                else{
                    carac[j]=linha[i];
                    j++;
                }
            }
        }
        fgets(linha,TFL*TFL,ponteiro);
        if(!feof(ponteiro)){
            for(tlc=0,i=0,j=0;i<strlen(linha);i++){
                if(linha[i]==' ' ||linha[i]=='\n'){
                    carac[j]='\0';
                    strcpy(arestas[tlc],carac);
                    tlc++;
                    j=0;
                }
                else{
                    carac[j]=linha[i];
                    j++;
                }
            }
        }
        l=0;
        fgets(linha,TFL*TFL,ponteiro);
        while(!feof(ponteiro)){
            c=0;
            for(i=0,j=0;i<strlen(linha);i++){
                if(linha[i]==' ' ||linha[i]=='\n'){
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
}
