#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <cstring>

static const char* NumeFisier="Carti.txt";
using namespace std;
class Carte
{
    char isbn[30], denumire[30], autor[30], editura[30];
    float pret;
    char buff[100];
    public:
        Carte();
        Carte(char _isbn[30], char _denumire[30], char _autor[30], char _editura[30], float _pret);
        inline char* getIsbn() {return isbn;}
        inline char* getDenumire() {return denumire;}
        inline char* getAutor() {return autor;}
        inline char* getEditura() {return editura;}
        inline float getPret(){return pret;}
        char* getDenumireComplet();
        char* ConversieFisier(); /// functie pentru crearea intr-un format specific scrierii in fisier
        /// functii de citire si afisare
        friend istream& operator >> (istream& c, Carte x);
        friend ostream& operator << (ostream& c, Carte x);
    protected:


};

#endif // CARTE_H
