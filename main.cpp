#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ofstream out("rezultatai.txt");

struct mokytojai{
    string vardas;
    string pavarde;
    string dalykas;
    int mokSk;

};
struct mokiniai{
    string vardas;
    string pavarde;
    string dalykas;
    int pazymys;
    int mokytojoIndeksas;
    };

void kiekisMokytoju(int &kiekMokyt, const char byla1[]);
void kiekisMokiniu(int &kiekMokin, const char byla2[]);
void skaitomMokytoju(mokytojai Duomenys[], int kiekis, const char byla[]);
void skaitomMokinius(mokiniai Duomenys[], int kiekis, const char byla[]);
void rasomMokytojus(mokytojai Duomenys[], int kiekis, string text);
void rasomMokinius(mokiniai Duomenys[], int kiekis, string text);
void ieskomMokiniuSkMokytojui(mokytojai DuomenysMokyt[], int kiekMokyt, mokiniai DuomenysMokin[], int kiekMokin);

int main()
{
    int kiekMokytoju, kiekMokiniu;
    const char duomenysMokytojai[] = "Mokytojai.txt";
    const char duomenysMokiniai[] = "Mokiniai.txt";

    kiekisMokytoju(kiekMokytoju, duomenysMokytojai);
    cout<<kiekMokytoju<<endl;
    kiekisMokiniu(kiekMokiniu, duomenysMokiniai);
    cout<<kiekMokiniu<<endl;

    mokytojai Mokytojai[kiekMokytoju];
    mokiniai Mokiniai[kiekMokiniu];

    skaitomMokytoju(Mokytojai, kiekMokytoju, duomenysMokytojai);
    skaitomMokinius(Mokiniai, kiekMokiniu, duomenysMokiniai);
    rasomMokytojus(Mokytojai, kiekMokytoju, "  Mokytojai  \n");
    rasomMokinius(Mokiniai, kiekMokiniu, " Mokiniai  \n");

    ieskomMokiniuSkMokytojui(Mokytojai, kiekMokytoju, Mokiniai, kiekMokiniu);


    out.close();
    return 0;
}


void kiekisMokytoju(int &kiekMokyt, const char byla1[]){
    ifstream in(byla1);
    mokytojai LaikStruktura[1];// uztekna man vieno elemento, kad nuskaityti kieki
    kiekMokyt=0;
    while(!in.eof()){
        in>>LaikStruktura[0].vardas>>LaikStruktura[0].pavarde>>LaikStruktura[0].dalykas;//skaitom nuo nulinio-(pirmo) elemento
        kiekMokyt++;
    }
    in.seekg(0);
    in.close();
 }
void kiekisMokiniu(int &kiekMokin, const char byla2[]){
    ifstream in(byla2);
    mokiniai LaikStruktura[1];// uztekna man vieno elemento, kad nuskaityti kieki
    kiekMokin=0;
    while(!in.eof()){
        in>>LaikStruktura[0].vardas>>LaikStruktura[0].pavarde>>LaikStruktura[0].dalykas>>LaikStruktura[0].pazymys;//skaitom nuo nulinio-(pirmo) elemento
        kiekMokin++;
    }
    in.seekg(0);
    in.close();
 }
void skaitomMokytoju(mokytojai Duomenys[], int kiekis, const char byla[]){
    ifstream in(byla);
    for(int i=0; i<kiekis; i++){
        in>>Duomenys[i].vardas>>Duomenys[i].pavarde>>Duomenys[i].dalykas;
    }
    in.close();
}
void skaitomMokinius(mokiniai Duomenys[], int kiekis, const char byla[]){
    ifstream in(byla);
    for(int i=0; i<kiekis; i++){
        in>>Duomenys[i].vardas>>Duomenys[i].pavarde>>Duomenys[i].dalykas>>Duomenys[i].pazymys;
    }
    in.close();
}
void rasomMokytojus(mokytojai Duomenys[], int kiekis, string text){
     out<<text;
    for(int i=0; i<kiekis; i++){
        out<<setw(10)<<left<<Duomenys[i].vardas<<"   "<<Duomenys[i].pavarde<<"   "<<Duomenys[i].dalykas<<Duomenys[i].mokSk;
        out<<endl;
    }
}
void rasomMokinius(mokiniai Duomenys[], int kiekis, string text){
     out<<text;
    for(int i=0; i<kiekis; i++){
        out<<setw(10)<<left<<Duomenys[i].vardas<<"   "<<Duomenys[i].pavarde<<"   "<<Duomenys[i].dalykas<<"   "<<Duomenys[i].pazymys;
        out<<endl;
    }
}
void ieskomMokiniuSkMokytojui(mokytojai DuomenysMokyt[], int kiekMokyt, mokiniai DuomenysMokin[], int kiekMokin){
int laikinas;
    for(int i=0; i< kiekMokyt; i++){
        laikinas=0;
        for(int j=0; j<kiekMokin; j++){

                if(DuomenysMokyt[i].dalykas==DuomenysMokin[j].dalykas){
                    laikinas++;
                }

        }
            DuomenysMokyt[i].mokSk=laikinas;
            cout<<DuomenysMokyt[i].mokSk<<"    "<<DuomenysMokyt[i].dalykas<<endl;

    }

}
