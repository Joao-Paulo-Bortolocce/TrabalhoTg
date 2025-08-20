void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF){
    int i;
    textcolor(CorT);
    textbackground(CorF);
    gotoxy(CI,LI); printf("%c",201);
    gotoxy(CI,LF); printf("%c",200);
    gotoxy(CF,LI); printf("%c",187);
    gotoxy(CF,LF); printf("%c",188);

    for(i=CI+1; i<CF; i++) {
        gotoxy(i,LI); printf("%c",205);
        gotoxy(i,LF); printf("%c",205);
    }
    for(i=LI+1; i<LF; i++) {
        gotoxy(CI,i); printf("%c",186);
        gotoxy(CF,i); printf("%c",186);
    }
    textcolor(7);
    textbackground(0);
}

void MenuPrincipal(void) {
    textbackground(14);
    textcolor(0);
	gotoxy(12,5); printf("SELECIONE QUAL OPCAO");
    gotoxy(10,6); printf("DESEJA OU [ESC PARA SAIR]");
}

void QuadroInfo() {
    textbackground(0);
    clrscr();
    int i,j;
    for(i = 2; i < 30; i++)
        for(j = 2;j < 120; j++){
            textbackground(14);
            gotoxy(j,i);
            printf(" ");
        }
    Moldura(1,1,120,30,15,7);
    i=15;
    gotoxy(2,15);
}

char Quadro() {
    textbackground(0);
    clrscr();
    int i,j;
    for(i = 2; i < 20; i++)
        for(j = 2;j < 45; j++){
            textbackground(14);
            gotoxy(j,i);
            printf(" ");
        }
    Moldura(1,1,45,20,15,7);
    i=15;
    MenuPrincipal();
    // OPÇÕES
    gotoxy(10,10); printf("[A]->MATRIZ DE ADJACENCIA");
    gotoxy(10,12); printf("[I]->MATRIZ DE INCIDENCIA");
    gotoxy(10,14); printf("[L]->LISTA");
    //
    gotoxy(10,15);
    return toupper(getche());
}
