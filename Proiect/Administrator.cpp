#include "Administrator.h"
#include <string>
#include <fstream>
#include <cstdio>
Administrator::Administrator()
{

}

Administrator::~Administrator()
{
    //dtor
}

void Administrator::AdaugaCarte(Carte c1)
{
     fstream f;
    f.open(NumeFisier,ios::out| ios::app);
    if(f.is_open())
    f<<c1.ConversieFisier()<<endl;
}
void Administrator::AfisareStudenti()
{
    fstream myfile ("Studenti.txt",ios::in);
    if (myfile.is_open())
    {
        string stud;
        while (getline (myfile,stud))
            cout << stud<< "\n";
    }
}
void Administrator::AfisareCarti()
{

    char sep[]=";",*p;
    fstream myfile(NumeFisier,ios::in);
    char Linie_citita[501];
    if(myfile.is_open())
    {
        while(myfile.getline(Linie_citita,501))
        {
            p=strtok(Linie_citita,sep);
            while (p)
            {
                cout<<p<<'\t';
                p=strtok(0,sep);
            }
            cout<<endl;
        }
    }
}
void Administrator::CautaStudentId(char ID[50])
{
    fstream myfile ("Studenti.txt",ios::in);
    char sep[]=" ",*p;
    bool gasit=false;
    char StudGasit[100], buff[100];
    if (myfile.is_open())
    {
        char stud[501];
        while (myfile.getline(stud,501))
        {
            strcpy(buff,stud);
            p=strtok(stud,sep);
            while (p)
            {
                if(strcmp(p,ID)==0)
                {
                    gasit=true;
                    strcpy(StudGasit,buff);
                }

                 p=strtok(0,sep);
            }
        }
    }
    if(gasit)
    {
        cout<<"Student gasit: "<<StudGasit;
    }
    else
        cout<<"Student nexistent";
}
void Administrator::AfisareCartiImprumutate()
{
     string line;
  ifstream myfile ("Imprumutari.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << endl;
    }
    myfile.close();
  }

  else cout << "Nu se poate deschide fisierul";

}
void Administrator::StergeCarte()
{
    string _isbn;
    cout<<"Isbn:";
    cin>>_isbn;
    ifstream read("Carti.txt");
    ofstream write("tmp.txt");
     if (read.is_open()) {
       string line;
       while (getline(read, line)) {
          if (line.find(_isbn) == string::npos)
             write << line<<endl;
       }
     }
       read.close();
    write.close();
    remove("Carti.txt");
    rename("tmp.txt", "Carti.txt");

}
