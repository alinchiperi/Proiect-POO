#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "Carte.h"


#define User "admin"
#define Password "admin"
class Administrator
{
    int id;
    public:
        Administrator();
        void AdaugaCarte(Carte c1);
        void StergeCarte();
        void AfisareStudenti();
        void AfisareCarti();
        void CautaStudentId(char ID[50]);
        //void ModificaCarte(Carte c1, Carte c2);
        void AfisareCartiImprumutate();
        virtual ~Administrator();
    protected:

    private:
};

#endif // ADMINISTRATOR_H
