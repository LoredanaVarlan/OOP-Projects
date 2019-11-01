#include <iostream>
#include <cmath>

using namespace std;
/////////////////////////////////////////////////////////////////

class v{
int valoare;
public:
void Valoare(int nr){
this->valoare=nr;
}
int Afisare1(){
return this->valoare;
}
};

class Obiecte{
v vec;
public:
Obiecte();
void SetValoare(int nr){
this->vec.Valoare(nr);}
void Afisare(){
    cout<<vec.Afisare1();
}

};

Obiecte::Obiecte(){

}

class Management{
    int nr;
    int vec[];
public:
    Management(int nr);
    Management(Management& );

    Management();
    void SetValoare(int poz, int val){
        this->vec[poz]=val;
    }
    Management operator<<(ostream& out);
    friend ostream& operator<<(ostream& out,Management& f);

    Management operator>>(istream& out);
    friend istream& operator>>(istream& out,Management& f);

    Management operator=(int);

};
/*
Management::Management(int nr)
{
    this->nr=nr;
   // this->vec=malloc(nr*sizeof(int));}

Management::Management(Management &f){
    this->nr=f.nr;
for(int i=0;i<f.nr;i++){
    f.vec[i]=this->vec[i];
}
}

Management Management::operator=(int nr){
this->nr=nr;
for(int i=0;i<nr;i++){
    this->vec[i]=nr;
}
}

ostream& operator<<(ostream& out,Management& f){
for(int i=0;i<f.nr;i++){
    out<<f.vec[i]<<' ';
}
out<<endl;
}

istream& operator>>(istream& out,Management& f){
    cin>>f.nr;
for(int i=0;i<f.nr;i++){
    cin>>f.vec[i];
}
}
*/
//////////////////////////////////////////////////////////////////////////
class Fractie{

private:

int numarator;
int numitor;

public:

int GetNumarator(){       //returneaza numarator
return numarator;
}

int GetNumitor(){         //returneaza numitor
return numitor;
}

void SetNumitor(int numi){  //furnizeaza numarator
this->numitor=numi;
}

void SetNumarator(int num){  //furnizeaza numitor
this->numarator=num;
}

//motoda de simplificare
int Simplificare();

Fractie operator<<(ostream& out);
friend ostream& operator<<(ostream& out,Fractie& f);

Fractie operator+(Fractie&);
friend Fractie operator+(Fractie& f);

Fractie operator-(Fractie&);
friend Fractie operator-(Fractie& f);

Fractie operator*(Fractie&);
friend Fractie operator*(Fractie& f);

Fractie operator/(Fractie&);

Fractie operator*(const int&);

Fractie operator/(const int&);


//sisteme
void Sistem(Fractie cx1, Fractie cy1, Fractie rez1, Fractie cx2, Fractie cy2, Fractie rez2);

//constructor de initializare
Fractie(int, int);

Fractie();

//~Fractie();
//constructor de copiere
Fractie(const Fractie&);


};
                                              //initializare
Fractie::Fractie(int num, int numi=1){
this->numarator=num;
this->numitor=numi;
if(numi=0){
    cout<<"Eroare";
}
}
                                                //copiere
Fractie::Fractie(const Fractie& f){
this->numarator=f.numarator;
this->numitor=f.numitor;
}


//metoda de rezolvare a sistemului
void Fractie::Sistem(Fractie cx1, Fractie cy1, Fractie rez1, Fractie cx2, Fractie cy2, Fractie rez2){
Fractie aux=cx1;
    cx1=cx1*cx2;
    cy1=cy1*cx2;
    rez1=rez1*cx2;
    cx2=cx2*aux;
    cy2=cy2*aux;
    rez2=rez2*aux;
Fractie coef=cy1-cy2;
Fractie rez=rez1-rez2;
Fractie y=rez/coef;
y.Simplificare();
    cout<<"y="<<y<<endl;
    cy1=cy1*y;
    rez1=rez1-cy1;
Fractie x=rez1/cx1;
x.Simplificare();
    cout<<"x="<<x<<endl;

}


//functie ce returneaza cel mai mare divizor comun
//functia foloseste metoda euclid
int gcd(int a, int b){
if(a==0)
    return b;
return gcd(b%a,a);
}

//metoda de simplificare
int Fractie::Simplificare(){

int r=gcd(numarator, numitor);
numarator=numarator/r;
numitor=numitor/r;
}

//supraincarcarea operatorului <<
ostream& operator<<(ostream& out, Fractie& f){

//conditii pentru a afisa fractia intr-un mod cat mai placut
if(f.numitor==1){
    out<<f.numarator<<endl;
}
else if(f.numitor==-1){
    out<<-f.numarator<<endl;
}else if((f.numarator<0)&&(f.numitor<0)){
    out<<-f.numarator<<"/"<<-f.numitor<<endl;
}else if((f.numarator>0)&&(f.numitor<0)){
    out<<-f.numarator<<"/"<<-f.numitor<<endl;
}else
    out<<f.numarator<<"/"<<f.numitor<<endl;
}

//supraincarcarea operatorului +
//permite adunarea a doua fractii folosind operatorul +
Fractie Fractie::operator+(Fractie& f){
Fractie sum=Fractie(1,1);
int numithis, numif;
numithis=this->numitor;
numif=f.numitor;
this->numarator=this->numarator*numif;
this->numitor=this->numitor*numif;
f.numarator=f.numarator*numithis;
f.numitor=f.numitor*numithis;
sum.numarator=f.numarator+this->numarator;
sum.numitor=f.numitor;
return sum;

}

//supraincarcarea operatorului -
//permite aflarea diferentei a doua fractii folosind operatorul -
Fractie Fractie::operator-(Fractie& f){
Fractie dif=Fractie(1,1);
int numithis, numif;
numithis=this->numitor;
numif=f.numitor;
this->numarator=this->numarator*numif;
this->numitor=this->numitor*numif;
f.numarator=f.numarator*numithis;
f.numitor=f.numitor*numithis;
dif.numarator=this->numarator-f.numarator;
dif.numitor=f.numitor;
return dif;

}

//supraincarcarea operatorului *
//permite inmultirea a doua fractii folosind operatorul *
Fractie Fractie::operator*(Fractie& f){
Fractie multip=Fractie(1,1);
multip.numarator=this->numarator*f.numarator;
multip.numitor=this->numitor*f.numitor;
multip.Simplificare();
return multip;
}

//supraincarcarea operatorului /
//permite impartirea a doua fractii folosind operatorul /
Fractie Fractie::operator/(Fractie& f){
Fractie div=Fractie(1,1);
div.numarator=this->numarator*f.numitor;
div.numitor=this->numitor*f.numarator;
div.Simplificare();
return div;
}

//permite inmultirea unei fractii cu un numar intreg
Fractie Fractie::operator*(const int& a){
Fractie total=Fractie(1,1);
total.numarator=a*this->numarator;
total.numitor=this->numitor;
return total;
}

//permite impartirea unei fractii la un numar intreg
Fractie Fractie::operator/(const int& a){
Fractie total=Fractie(1,1);
total.numarator=this->numarator;
total.numitor=a*this->numitor;
return total;
}

int main()
{
    //dam valori catorva fractii pentru a verifica functia Sistem
    Fractie f1=Fractie(2,4);
    f1.Simplificare();//f1=1/2
    Fractie f2=Fractie(5,-3);
    Fractie f3=Fractie(-1,2);
    Fractie f4=Fractie(-3,5);
    Fractie f5=Fractie(-2,-14);
    Fractie f6=Fractie(-2);

    f1.Sistem(f1,f2,f3,f4,f5,f6);


    Obiecte v[5];
    v[1].SetValoare(5);
    v[1].Afisare;

   return 0;}
