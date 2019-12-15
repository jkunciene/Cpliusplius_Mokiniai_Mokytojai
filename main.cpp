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
    float vidurkis;

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
int ieskomMAXMokiniu(mokytojai Duomenys[], int kiekis);
void ieskomGeriausioVidurkio(mokytojai DuomenysMokyt[], int kiekMokyt, mokiniai DuomenysMokin[], int kiekMokin);
int ieskomMAXVidurkio(mokytojai Duomenys[], int kiekis);

int main()
{
    int kiekMokytoju, kiekMokiniu, daugMok, vidurk;

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

    ieskomMokiniuSkMokytojui(Mokytojai, kiekMokytoju, Mokiniai, kiekMokiniu);

    daugMok=ieskomMAXMokiniu(Mokytojai, kiekMokytoju);
    ieskomGeriausioVidurkio(Mokytojai, kiekMokytoju, Mokiniai, kiekMokiniu);
    vidurk=ieskomMAXVidurkio(Mokytojai, kiekMokytoju);



    rasomMokytojus(Mokytojai, kiekMokytoju, "  Mokytojai  \n");
    rasomMokinius(Mokiniai, kiekMokiniu, " Mokiniai  \n");

    out<<"Daugiausia mokiniu turi   "<<Mokytojai[daugMok].pavarde<<"    "<<Mokytojai[daugMok].vardas<<"kuri desto  "<<Mokytojai[daugMok].dalykas<<"   "<<Mokytojai[daugMok].mokSk<<"-iems mokiniams"<<endl;
    out<<"Mokytojas kurio mokiniai mokosi geriausiai "<<Mokytojai[vidurk].vardas<<"  "<<Mokytojai[vidurk].dalykas<<"   "<<Mokytojai[vidurk].vidurkis<<endl;

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

int ieskomMAXMokiniu(mokytojai Duomenys[], int kiekis){
    int vieta=0;

    for(int i=0; i<kiekis; i++){

        if(Duomenys[i].mokSk>Duomenys[vieta].mokSk)
            vieta=i;

        }
        return vieta;
    }
void ieskomGeriausioVidurkio(mokytojai DuomenysMokyt[], int kiekMokyt, mokiniai DuomenysMokin[], int kiekMokin){
    int laikinas, suma;

    for(int i=0; i< kiekMokyt; i++){
        laikinas=0;
        suma=0;
        for(int j=0; j<kiekMokin; j++){

                if(DuomenysMokyt[i].dalykas==DuomenysMokin[j].dalykas){
                    laikinas++;
                    suma+=DuomenysMokin[j].pazymys;
                }
        }
                DuomenysMokyt[i].vidurkis = float(suma)/float(laikinas);
                cout<<DuomenysMokyt[i].vardas<<"    "<<DuomenysMokyt[i].dalykas<<"  "<<DuomenysMokyt[i].vidurkis<<endl;

    }
}
int ieskomMAXVidurkio(mokytojai Duomenys[], int kiekis){
int vieta=0;

    for(int i=0; i<kiekis; i++){

        if(Duomenys[i].vidurkis>Duomenys[vieta].vidurkis)
            vieta=i;

        }
        return vieta;
    }

void rasomMokytojus(mokytojai Duomenys[], int kiekis, string text){
     out<<text;
    for(int i=0; i<kiekis; i++){
        out<<setw(10)<<left<<Duomenys[i].vardas<<"   "<<Duomenys[i].pavarde<<"   "<<Duomenys[i].dalykas<<"  "<<Duomenys[i].mokSk;
        out<<endl;
    }
}
void rasomMokinius(mokiniai Duomenys[], int kiekis, string text){
     out<<text;
    for(int i=0; i<kiekis; i++){
        out<<setw(10)<<left<<Duomenys[i].vardas<<"   "<<Duomenys[i].pavarde<<"   "<<Duomenys[i].dalykas<<"  "<<Duomenys[i].pazymys;
        out<<endl;
    }
}

