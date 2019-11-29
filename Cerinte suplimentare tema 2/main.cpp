#include <iostream>

using namespace std;

class Farmacie_abstracta{
string denumire;
public:
Farmacie_abstracta(){};
~Farmacie_abstracta(){};
Farmacie_abstracta(string denumire){
this->denumire=denumire;
}
virtual double calcul_venit()=0;
virtual void Afisare()=0;
};

class Farmacie_offline:public Farmacie_abstracta{
int nr_luni;
double *cifra_afaceri_luna;
public:
double calcul_venit(){
double sum=0;
for(int i=0;i<nr_luni;i++){
    sum=sum+*(cifra_afaceri_luna+i);
}
return sum;
}
Farmacie_offline(){};
~Farmacie_offline(){};
Farmacie_offline(int nr_luni){
this->nr_luni=nr_luni;
cifra_afaceri_luna = new double[nr_luni];
for(int i = 0; i<nr_luni;i++){
    cin>>cifra_afaceri_luna[i];
}
//->cifra_afaceri_luna=vec;
}
Farmacie_offline(const Farmacie_offline& f):Farmacie_abstracta(" "){
this->nr_luni=f.nr_luni;
this->cifra_afaceri_luna=f.cifra_afaceri_luna;}
Farmacie_offline operator=(Farmacie_offline&);
void Afisare(){
cout<<nr_luni<<endl;
for(int i=0;i<nr_luni;i++){
cout<<*(cifra_afaceri_luna+i)<<endl;}
}
};


class Farmacie_online:public Farmacie_abstracta{
char *adresa_web;
int nr_vizitatori;
public:
Farmacie_online(){};
~Farmacie_online(){};
Farmacie_online(char adresa, int nr):Farmacie_abstracta(" "){
this->adresa_web=&adresa;
this->nr_vizitatori=nr;
}
Farmacie_online(const Farmacie_online& f):Farmacie_abstracta(" "){
this->adresa_web=f.adresa_web;
this->nr_vizitatori=f.nr_vizitatori;
}
Farmacie_online operator=(Farmacie_online&);
void Afisare(){
cout<<*adresa_web<<endl;
cout<<nr_vizitatori<<endl;
}
double calcul_venit(){return 0;}
};

class Farmacie_dubla_Specializare:public Farmacie_offline, Farmacie_online{
int nr_angajati;
public:
Farmacie_dubla_Specializare(){};
~Farmacie_dubla_Specializare(){};
Farmacie_dubla_Specializare(int nr):Farmacie_offline(0),Farmacie_online(0,0){
this->nr_angajati=nr;
}
Farmacie_dubla_Specializare(const Farmacie_dubla_Specializare& f){
this->nr_angajati=f.nr_angajati;
}
Farmacie_dubla_Specializare operator=(Farmacie_dubla_Specializare&);
void Afisare(){
cout<<nr_angajati<<endl;
}
double calcul_venit(){return Farmacie_offline::calcul_venit();}
};


Farmacie_offline Farmacie_offline::operator=(Farmacie_offline& f){
this->nr_luni=f.nr_luni;
this->cifra_afaceri_luna=f.cifra_afaceri_luna;
}

Farmacie_online Farmacie_online::operator=(Farmacie_online& f){
this->adresa_web=f.adresa_web;
this->nr_vizitatori=f.nr_vizitatori;
}

Farmacie_dubla_Specializare Farmacie_dubla_Specializare::operator=(Farmacie_dubla_Specializare& f){
this->nr_angajati=f.nr_angajati;
}

int main()
{
   Farmacie_abstracta* fa;
   Farmacie_offline fo(5);
   fa = &fo;
    fo.Afisare();
    cout<<fo.calcul_venit()<<endl;

    return 0;
}
