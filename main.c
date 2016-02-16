#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(void)
{
    menu();//MENU
    printf("\n  Wczytaj: ");scanf("%d",&nr);
    switch (nr) {
        case 1:{rozm_x=3;rozm_y=3;}break;
        case 2:{rozm_x=5;rozm_y=5;}break;
        case 3:{rozm_x=10;rozm_y=10;}break;
        default:{rozm_x=5;rozm_y=5;}break;
    }
//    DEKLARACJA TABLIC MUSI BYĆ TU, INACZEJ BĘDZIE WARIOWAŁ PROGRAM
    struct player{
        int id;
        int tab[rozm_x][rozm_y];
        char ctab[rozm_x][rozm_y];
    };
    struct player p1;
    struct player p2;
//    PRZYPISUJĘ TABLICE DO WSKAŹNIKÓW ŻEBY SIĘ LEPIEJ PO TYM PORUSZAĆ
    wsk_tab_p1=&p1.tab[0];
    wsk_tab_p2=&p2.tab[0];
    wsk_ctab_p1=&p1.ctab[0];
    wsk_ctab_p2=&p2.ctab[0];
    printf("\t   PLAYER 1\n");
        wypelnij_tablice(rozm_x,rozm_y,wsk_tab_p1);
        wypelnij_charowe(rozm_x,rozm_y,wsk_ctab_p1);
    system("cls");
    printf("\t   PLAYER 2\n");
        wypelnij_tablice(rozm_x,rozm_y,wsk_tab_p2);
        wypelnij_charowe(rozm_x,rozm_y,wsk_ctab_p2);
    suma1=licz(rozm_x,rozm_y,wsk_tab_p1);
    suma2=licz(rozm_x,rozm_y,wsk_tab_p2);
    i=0;
    j=0;
    k=0;
    do{
        if(i%2==0)
        {
            system("cls");
            printf("\t   PLAYER 1\n");
            printf("Pol do rozwalenia %d",suma1--);
            wyswietl_pole(rozm_x,rozm_y,wsk_ctab_p1);
            printf("Podaj x, x=");scanf("%d",&x);
            printf("Podaj y, y=");scanf("%d",&y);
            system("cls");
            proba1=zamien_znaki1(rozm_x,rozm_y,x,y,wsk_tab_p1,wsk_ctab_p1);
            wyswietl_pole(rozm_x,rozm_y,wsk_ctab_p1);
            j++;
            if(j==rozm_x*rozm_x && proba1<suma1)
            {
                p2.id=1;
                printf("PRZEGRALES... :(\n");
                break;
            }
            if(proba1==suma1)
            {
                p1.id=1;
                printf("WYGRALES!!! :)\n");
                break;
            }
            system("pause");
        }
        if(i%2!=0)
        {
            system("cls");
            printf("\t   PLAYER 2\n");
            printf("Pol do rozwalenia %d",suma2--);
            wyswietl_pole(rozm_x,rozm_y,wsk_ctab_p2);
            printf("Podaj x, x=");scanf("%d",&x);
            printf("Podaj y, y=");scanf("%d",&y);
            system("cls");
            proba2=zamien_znaki2(rozm_x,rozm_y,x,y,wsk_tab_p2,wsk_ctab_p2);
            wyswietl_pole(rozm_x,rozm_y,wsk_ctab_p2);
            k++;
            if(k==rozm_x*rozm_x && proba2<suma2)
            {
                p1.id=1;
                printf("PRZEGRALES... :(\n");
                break;
            }
            if(proba2==suma2)
            {
                p2.id=1;
                printf("WYGRALES!!! :)\n");
                break;
            }
            system("pause");
        }
        i++;
    }while(i<(rozm_x*rozm_x)*2);
    if(p1.id==1)
        play=1;
    else if(p2.id==1)
        play=2;
    printf("\n\tWYGRYWA PLAYER %d GRATULACJE!!!\n",play);
    return 0;
}
//FUNKCJA WYPEŁNIA TABLICĘ OKREŚLAJĄC POŁOŻENIE STATKU
void wypelnij_tablice(int xx, int yy, int tab[xx][yy])
{
    int i,j,xxx,yyy;
    char decyzja='n';
    for(i=0;i<xx;i++)
        for(j=0;j<yy;j++)
            tab[i][j]=0;
    do{
        wyswietl_wszystko(xx,yy,tab);
        printf("    Podaj wspolrzedne statku:\n");
        printf("\tx=");scanf("%d",&xxx);
        printf("\ty=");scanf("%d",&yyy);
        tab[yyy-1][xxx-1]=1;
        system("cls");
        printf("\n    Podac kolejna wspolrzedna? (T/N) ");scanf("%s",&decyzja);
    }while(decyzja=='t');
}
void menu()
{
    printf("\t    Poziom trudnosci:\n");
    printf("\t1. Low (3x3)\n");
    printf("\t2. Medium (5x5)\n");
    printf("\t3. Hard (10x10)\n");
}
//FUNKCJA WYPEŁNIA TABLICĘ CHAR ABY PÓŹNIEJ ŁADNIE WYŚWIETLAĆ POŁOŻENIE
void wypelnij_charowe(int xx, int yy, char ctab[xx][yy])
{
    int i,j;
    for(i=0;i<xx;i++)
        for(j=0;j<yy;j++)
            ctab[i][j]=' ';
}
//FUNKCJA WYŚWIETLA TABLICĘ INTÓW TAM GDZIE JEST STATEK WYPISUJE 1
//TAM GDZIE STATKU NIE MA TO WYPISUJE 0
void wyswietl_wszystko(int xx, int yy, int tab[xx][yy])
{
    int i,j,k,l,m;//liczniki
    int ascii=65;
    printf("\n\n\t    ");
    for(i=0;i<yy;i++)
        printf("%c=%d ",ascii+i,i+1);
    printf("\n\t   ");
    for(j=0;j<xx;j++)
        printf(" ___");
    printf("\n");
    for(k=0;k<xx;k++)
    {
        printf("\t");
        if(k<9)
            printf("%d  |",k+1);
        else if(k==9)
            printf("%d |",k+1);
        for(l=0;l<yy;l++)
            printf(" %d |",tab[k][l]);
        printf("\n\t   |");
        for(m=0;m<yy;m++)
            printf("___|");
        printf("\n");
    }
}
//FUNKCJA WYPISUJE TABLICĘ CHARÓW TAK ABY SIĘ ZORIENTOWAĆ GDZIE JUŻ SIĘ STRZELAŁO
//TAM GDZIE SIĘ TRAFIŁO W STATEK WYPISUJE X A TAM GDZIE NIE TO WYPISUJE 0
void wyswietl_pole(int xx, int yy, char ctab[xx][yy])
{
    int i,j,k,l,m;//liczniki
    int ascii=65;
    printf("\n\n\t    ");
    for(i=0;i<yy;i++)
        printf("%c=%d ",ascii+i,i+1);
    printf("\n\t   ");
    for(j=0;j<xx;j++)
        printf(" ___");
    printf("\n");
    for(k=0;k<xx;k++)
    {
        printf("\t");
        if(k<9)
            printf("%d  |",k+1);
        else if(k==9)
            printf("%d |",k+1);
        for(l=0;l<yy;l++)
            printf(" %c |",ctab[k][l]);
        printf("\n\t   |");
        for(m=0;m<yy;m++)
            printf("___|");
        printf("\n");
    }
}
//FUNKCJA LICZY ILE JEST PÓL ZAPEŁNIONYCH STATKAMI
int licz(int xx, int yy, int tab[xx][yy])
{
    int i,j,suma;
    suma=0;
    for(i=0;i<xx;i++)
        for(j=0;j<yy;j++)
            if(tab[i][j]==1)
                suma++;
    return suma;
}
//DO ZAMIANY TABLICY CHAROWEJ POTRZEBNE SĄ DWIE FUNKCJE DLA DWÓCH GRACZY, W PRZECIWNYM WYPADKU
//GRA BĘDZIE SIĘ KOŃCZYĆ W NIESPODZIEWANYM MOMENCIE
int zamien_znaki1(int xx, int yy, int xxx, int yyy, int tab[xx][yy], char ctab[xx][yy])
{
    if(tab[yyy-1][xxx-1]==1)
    {
        ctab[yyy-1][xxx-1]='X';
        fproba1++;
    }
    else if(tab[yyy-1][xxx-1]!=1)
        ctab[yyy-1][xxx-1]='0';
    return fproba1;
}
int zamien_znaki2(int xx, int yy, int xxx, int yyy, int tab[xx][yy], char ctab[xx][yy])
{
    if(tab[yyy-1][xxx-1]==1)
    {
        ctab[yyy-1][xxx-1]='X';
        fproba2++;
    }
    else if(tab[yyy-1][xxx-1]!=1)
        ctab[yyy-1][xxx-1]='0';
    return fproba2;
}
