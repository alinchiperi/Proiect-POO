#include "Carte.h"
#include <fstream>
#include <stdio.h>

const char* SEPARATOR= ";";

//istream pf(NumeFisier);
/// contructori
Carte::Carte()
{

}
Carte:: Carte(char _isbn[30], char _denumire[30], char _autor[30], char _editura[30], float _pret)
{
    strcpy(isbn,_isbn);
    strcpy(denumire,_denumire);
    strcpy(autor,_autor);
    strcpy(editura, _editura);
    pret=_pret;
}
///end Constructori

char* Carte::getDenumireComplet()
{
    char cpret[10];
    sprintf (cpret,"%5.2f", pret);
    strcpy(buff,isbn);
    strcat(buff, " ");
    strcat(buff,denumire);
    strcat(buff, " ");
    strcat(buff,autor);
    strcat(buff, " ");
    strcat(buff,editura);
    strcat(buff," ");
    strcat(buff,cpret);
    return buff;
}
istream& operator >> (istream& c, Carte x)
{
    cout<<"Denumire ";
    c>>x.denumire;
    fflush(stdin);
    cout<<"ISBN ";
    c>>x.isbn;
    fflush(stdin);
    cout<<"Autor: ";
    c>>x.autor;
    fflush(stdin);
    cout <<"Editura: ";
    c>>x.editura;
    fflush(stdin);
    cout<<"Pret: ";
    c>>x.pret;
    return c;
}
ostream& operator << (ostream& c, Carte x)
{
    c<<x.getDenumireComplet();
    return c;
}

///Functie pentru conversia de salvare in fisier
char* Carte::ConversieFisier()
{
    char cpret[10];
    sprintf (cpret,"%5.2f", pret);
    strcpy(buff,isbn);
    strcat(buff, SEPARATOR);
    strcat(buff,denumire);
    strcat(buff, SEPARATOR);
    strcat(buff,autor);
    strcat(buff, SEPARATOR);
    strcat(buff,editura);
    strcat(buff,SEPARATOR);
    strcat(buff,cpret);
    strcat(buff,SEPARATOR);
    return buff;
}

