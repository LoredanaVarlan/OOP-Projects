#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <set>
#include <iterator>
#include <string.h>

using namespace std;


class locuinta{
protected:
string nume;
int suprafatautila;
int discount;
int pretinchiriere;
double totalchirie;

public:
locuinta(){nume="Fara nume"; suprafatautila=0; discount=0; pretinchiriere=0; totalchirie=0;}
locuinta(string, int, int, int, double);
locuinta(const locuinta&);
~locuinta(){};
locuinta operator=(locuinta&);
locuinta operator>>(istream& in);
friend istream& operator>>(istream& in, locuinta& l);
virtual void afisare()const{
cout<<"Nume:"<<nume<<endl;
cout<<"Suprafata utila:"<<suprafatautila<<endl;
cout<<"Discount(%):"<<discount<<endl;
cout<<"Pret inchiriere:"<<pretinchiriere<<endl;
cout<<"Chirie:"<<totalchirie<<endl;
};
template <class tip> friend void chirie(tip&);
friend bool operator<(const locuinta&, const locuinta&);
int Suprafata()const{
return this->suprafatautila;
}
};

class apartament:public locuinta{

private:
int etaj;
public:
apartament(){etaj=0;};
apartament(int,string,int,int,int,double);
apartament(const apartament&, string, int, int, int, double);
~apartament(){};
apartament operator=(apartament& a);
apartament operator>>(istream& in);
friend istream& operator>>(istream& in, apartament& a);
void afisare()const{
cout<<"Nume:"<<nume<<endl;
cout<<"Suprafata utila:"<<suprafatautila<<endl;
cout<<"Discount(%):"<<discount<<endl;
cout<<"Pret inchiriere:"<<pretinchiriere<<endl;
cout<<"Chirie:"<<totalchirie<<endl;
cout<<"Etaj:"<<etaj<<endl;
}
friend bool operator<(const locuinta&, const locuinta&);
};

class casa:public locuinta{
private:
int curte;
int etaje;
int *suprafatautilaetaj;
int pretcurte;
public:
casa(){curte=0;etaje=0;suprafatautilaetaj=new int[etaje];pretcurte=0;};
casa(int, int, int*, int, string, int, int, int, double);
casa(const casa& c, string, int, int, int, double);
~casa(){};
casa operator=(casa& c);
casa operator>>(istream& in);
friend istream& operator>>(istream& in, casa& c);
void afisare()const{
cout<<"Nume:"<<nume<<endl;
cout<<"Suprafata utila:"<<suprafatautila<<endl;
cout<<"Discount(%):"<<discount<<endl;
cout<<"Pret inchiriere:"<<pretinchiriere<<endl;
cout<<"Chirie:"<<totalchirie<<endl;
cout<<"Metri patrati curte:"<<curte<<endl;
cout<<"Nr etaje:"<<etaje<<endl;
cout<<"Suprafata utila pentru fiecare etaj:"<<endl;
for(int i=0;i<etaje;i++){
    cout<<suprafatautilaetaj[i]<<endl;
}
cout<<"Pretul pe curte este:"<<pretcurte<<endl;
};
friend void chirie(casa &);
friend bool operator<(const locuinta&, const locuinta&);
};

locuinta::locuinta(string nume, int suprafatautila, int discount , int pretinchiriere, double totalchirie){
this->nume=nume;
this->suprafatautila=suprafatautila;
this->discount=discount;
this->pretinchiriere=pretinchiriere;
this->totalchirie=totalchirie;
}

locuinta::locuinta(const locuinta& l){
this->nume=l.nume;
this->suprafatautila=l.suprafatautila;
this->discount=l.discount;
this->pretinchiriere=l.pretinchiriere;
this->totalchirie=l.totalchirie;
}

locuinta locuinta::operator=(locuinta& l){
this->nume=l.nume;
this->suprafatautila=l.suprafatautila;
this->discount=l.discount;
this->pretinchiriere=l.pretinchiriere;
this->totalchirie=l.totalchirie;
}

istream& operator>>(istream& in, locuinta& l){
cout<<"Introdu numele clientului."<<endl;
in>>l.nume;
cout<<"Introdu suprafata utila."<<endl;
in>>l.suprafatautila;
cout<<"Introdu discountul."<<endl;


//tratarea exceptiilor
char aux[20];
int ok=0;
do{
try{
in>>aux;
l.discount=atoi(aux);
if((l.discount<0)||(l.discount>10)){
    throw(5);
}
ok=0;
}
catch(int n){
cout<<"Numarul nu este intre 0 si 10!"<<endl;
ok=1;
}
}
while(ok==1);


cout<<"Introdu pretul de inchiriere:"<<endl;
in>>l.pretinchiriere;
}

apartament::apartament(int etaj,string nume,int suprafata,int discount,int pret,double chirie):locuinta(nume, suprafata, discount, pret, chirie){
this->etaj=etaj;
}

apartament::apartament(const apartament& a, string nume, int suprafata, int discount, int pret, double chirie):locuinta(nume, suprafata, discount, pret, chirie){
this->etaj=a.etaj;
}

apartament apartament::operator=(apartament& a){
this->etaj=a.etaj;
}

istream& operator>>(istream& in, apartament& a){
in>>dynamic_cast<locuinta &>(a);
cout<<"Introdu etajul."<<endl;
in>>a.etaj;
}

casa::casa(int curte, int etaje, int* suprafatautilaetaj, int pretcurte, string nume, int suprafata, int discount, int pret,  double chirie):locuinta(nume, suprafata, discount, pret, chirie){
this->curte=curte;
this->etaje=etaje;
this->suprafatautilaetaj=new int[etaje];
for(int i=0;i<etaje;i++){
    this->suprafatautilaetaj[i]=0;
    }
this->pretcurte=pretcurte;
}

casa::casa(const casa& c, string nume, int suprafata, int discount, int pret, double chirie):locuinta(nume, suprafata, discount, pret, chirie){
this->curte=c.curte;
this->etaje=c.etaje;
for(int i=0;i<c.etaje;i++){
this->suprafatautilaetaj[i]=c.suprafatautilaetaj[i];}
this->pretcurte=c.pretcurte;
}

casa casa::operator=(casa& c){
this->curte=c.curte;
this->etaje=c.etaje;
this->suprafatautilaetaj=c.suprafatautilaetaj;
this->pretcurte=c.pretcurte;
}

istream& operator>>(istream& in, casa& c){
in>>dynamic_cast<locuinta &>(c);
cout<<"Introdu metri patrati ai curtii."<<endl;
in>>c.curte;
cout<<"Introdu numarul de etaje."<<endl;
in>>c.etaje;
cout<<"Introdu numarul de metri patrati ai fiecarui etaj."<<endl;
for(int i=0;i<c.etaje;i++){
in>>c.suprafatautilaetaj[i];}
cout<<"Introdu pretul pe curte."<<endl;
in>>c.pretcurte;
}

template <class tip> void chirie(tip& loc){//apartament
double chirie=loc.pretinchiriere*loc.suprafatautila;
chirie=chirie-chirie*loc.discount/100;
loc.totalchirie=chirie;
}

void chirie(casa& c){//casa
int suprafata=0;
for(int i=0;i<c.etaje;i++){
    suprafata=suprafata+c.suprafatautilaetaj[i];
}
double chirie=c.pretinchiriere*suprafata;
chirie=chirie-chirie*c.discount/100;
chirie=chirie+(c.pretcurte*c.curte);
c.totalchirie=chirie;
}

bool operator<(const locuinta& l1, const locuinta& l2){
return l1.Suprafata()>l2.Suprafata();
}

void adaugare_apt(set<pair<int, apartament> > &apt,apartament* pa, int &contor){//apartament
pa=new apartament;
cin>>*pa;
chirie(*pa);
pair<int, apartament> apt1=make_pair(contor, *pa);
apt.insert(apt1);
contor++;
}

void adaugare_cs(set<pair<int,casa> >cs, casa* pc, int &contor){//casa
pc=new casa;
cin>>*pc;
chirie(*pc);
pair<int, casa> cs1=make_pair(contor, *pc);
cs.insert(cs1);
contor++;
}

void afisare_apt(set<pair<int, apartament> >apt){//apartamnet
set<pair<int,apartament> >::iterator it;
for(it=apt.begin();it!=apt.end();it++){
    cout<<it->first<<endl;
    it->second.afisare();
}
}

void afisare_cs(set<pair<int, casa> >cs){//casa
set<pair<int,casa> >::iterator it;
for(it=cs.begin();it!=cs.end();it++){
    cout<<it->first<<endl;
    it->second.afisare();
}
}

int main()
{
    int contorapt=0;
    int contorcs=0;
    apartament *pa;
    casa *pc;
    set<pair<int,apartament> >apt;
    set<pair<int,casa> >cs;
    int comanda;
    int comanda2;
    while(1){
       cout<<"Adaugare locuinta-1"<<endl<<"Afisare locuinte-2"<<endl;
       cin>>comanda;
       if(comanda==1){
        cout<<"Apartament-1"<<endl<<"Casa-2"<<endl;
        cin>>comanda2;
        if(comanda2==1){
            adaugare_apt(apt, pa, contorapt);
        }
        else if(comanda2==2){
            adaugare_cs(cs, pc, contorcs);
        }
        else{
            cout<<"Comanda introdusa incorect!"<<endl;
        }
       }
       else if(comanda==2){
        cout<<"Apartament-1"<<endl<<"Casa-2"<<endl;
        cin>>comanda2;
        if(comanda2==1){
            afisare_apt(apt);
        }
        else if(comanda2==2){
            afisare_cs(cs);
        }
        else{
            cout<<"Comanda introdusa incorect!"<<endl;
        }
       }
       else{
        cout<<"Comanda introdusa incorect!"<<endl;
       }
    }

    return 0;
}
