#ifndef MAIN_H
#define MAIN_H
//    ++++++++++++++++++++ ZMIENNE ++++++++++++++++++++
    int suma1,suma2,i,j,k,x,y,rozm_x,rozm_y,nr,proba1,proba2,play;
    int fproba1=0,fproba2=0;//To musi być tutaj zadeklarowane i wyzerowane, globalna dla liczenia prob
//    ++++++++++++++++++++ WSKAŹNIKOWE ++++++++++++++++++++
    int *wsk_tab_p1,*wsk_tab_p2;
    char *wsk_ctab_p1,*wsk_ctab_p2;
//    ++++++++++++++++++++ FUNKCJE BEZ ZWRACANIA ++++++++++++++++++++
    void wypelnij_tablice(int xx, int yy, int tab[xx][yy]);
    void wypelnij_charowe(int xx, int yy, char ctab[xx][yy]);
    void wyswietl_wszystko(int xx, int yy, int tab[xx][yy]);
    void wyswietl_pole(int xx, int yy, char ctab[xx][yy]);
    void menu();
//    ++++++++++++++++++++ FUNKCJE ZE ZWRACANIEM ++++++++++++++++++++
    int licz(int xx, int yy, int tab[xx][yy]);
    int zamien_znaki1(int xx, int yy, int xxx, int yyy, int tab[xx][yy], char ctab[xx][yy]);
    int zamien_znaki2(int xx, int yy, int xxx, int yyy, int tab[xx][yy], char ctab[xx][yy]);
#endif // MAIN_H
