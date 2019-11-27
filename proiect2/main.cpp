#include <iostream>
#include <typeinfo>

using namespace std;

class Persoana{
private:
int id;
string nume;
public:
Persoana(){id=0; nume=" ";}
Persoana(int, string);
Persoana(const Persoana&);
~Persoana(){};
Persoana operator>>(istream& in);
friend istream& operator>>(istream& in, Persoana& p);
Persoana operator<<(ostream& out);
friend ostream& operator<<(ostream& in, Persoana& p);
Persoana operator=(Persoana&);
virtual void Tara(){}
string Nume(){
return nume;
}
};

class Abonat:public Persoana{
private:
string nr_telefon;
public:
Abonat(string);
Abonat(const Abonat&);
Abonat(){nr_telefon="0";}
~Abonat(){};
Abonat operator>>(istream& in);
friend istream& operator>>(istream& in, Abonat& a);
Abonat operator<<(ostream& out);
friend ostream& operator<<(ostream& out, Abonat& a);
Abonat operator=(Abonat&);
};

class Abonat_Skype:public Abonat{
private:
int id_skype;
public:
Abonat_Skype(int);
Abonat_Skype(const Abonat_Skype&);
Abonat_Skype(){id_skype=0;}
~Abonat_Skype(){};
Abonat_Skype operator>>(istream& in);
friend istream& operator>>(istream& in, Abonat_Skype& as);
Abonat_Skype operator<<(ostream& out);
friend ostream& operator<<(ostream& out, Abonat_Skype& as);
Abonat_Skype operator=(Abonat_Skype&);
};

class Abonat_Skype_Romania:public Abonat_Skype{
private:
string adresa_mail;
public:
Abonat_Skype_Romania(string);
Abonat_Skype_Romania(const Abonat_Skype_Romania&);
Abonat_Skype_Romania(){adresa_mail="0";}
~Abonat_Skype_Romania(){};
Abonat_Skype_Romania operator>>(istream& in);
friend istream& operator>>(istream& in, Abonat_Skype_Romania& asa);
Abonat_Skype_Romania operator<<(ostream& out);
friend ostream& operator<<(ostream& out, Abonat_Skype_Romania& asa);
Abonat_Skype_Romania operator=(Abonat_Skype_Romania&);
void Tara(){
cout<<"Tara in care se afla domiciliul altual al utilizatorului este: Romania."<<endl;
}
};

class Abonat_Skype_Extern:public Abonat_Skype{
private:
string tara;
public:
Abonat_Skype_Extern(string);
Abonat_Skype_Extern(const Abonat_Skype_Extern&);
Abonat_Skype_Extern(){};
~Abonat_Skype_Extern(){};
Abonat_Skype_Extern operator>>(istream& in);
friend istream& operator>>(istream& in, Abonat_Skype_Extern& as);
Abonat_Skype_Extern operator<<(ostream& out);
friend ostream& operator<<(ostream& out, Abonat_Skype_Extern& as);
Abonat_Skype_Extern operator=(Abonat_Skype_Extern&);
void Tara(){
cout<<"Tara in care se afla domiciliul altual al utilizatorului este: "<<tara<<"."<<endl;
}
};

//constructor de initializare
Persoana::Persoana(int id, string nume){
this->id=id;
this->nume=nume;
}
//constructor de copiere
Persoana::Persoana(const Persoana& p){
this->id=p.id;
this->nume=p.nume;
}

Abonat::Abonat(string nr_telefon):Persoana(0,"Fara nume"){
this->nr_telefon=nr_telefon;
}

Abonat::Abonat(const Abonat& a):Persoana(0,"Fara nume"){
this->nr_telefon=a.nr_telefon;
}

Abonat_Skype::Abonat_Skype(int id_skype):Abonat(0){
this->id_skype=id_skype;
}

Abonat_Skype::Abonat_Skype(const Abonat_Skype& as):Abonat(0){
this->id_skype=as.id_skype;
}

Abonat_Skype_Romania::Abonat_Skype_Romania(string adresa_mail):Abonat_Skype(0){
this->adresa_mail=adresa_mail;
}

Abonat_Skype_Romania::Abonat_Skype_Romania(const Abonat_Skype_Romania& asr):Abonat_Skype(0){
this->adresa_mail=asr.adresa_mail;
}

Abonat_Skype_Extern::Abonat_Skype_Extern(string tara):Abonat_Skype(0){
this->tara=tara;
}

Abonat_Skype_Extern::Abonat_Skype_Extern(const Abonat_Skype_Extern& ase):Abonat_Skype(0){
this->tara=ase.tara;
}

istream& operator>>(istream& in, Persoana& p){
cout<<"Introdu id-ul."<<endl;
in>>p.id;
cout<<"Introdu numele."<<endl;
in>>p.nume;
}

ostream& operator<<(ostream& out, Persoana& p){
out<<p.id<<endl;
out<<p.nume<<endl;
}

Persoana Persoana::operator=(Persoana& p){
this->id=p.id;
this->nume=p.nume;
}

istream& operator>>(istream& in,Abonat& a){
in>>(Persoana&)a;
cout<<"Introdu numarul de telefon."<<endl;
in>>a.nr_telefon;
}

ostream& operator<<(ostream& out, Abonat& a){
out<<(Persoana&)a;
out<<a.nr_telefon<<endl;
}

Abonat Abonat::operator=(Abonat& a){
this->nr_telefon=a.nr_telefon;
}

istream& operator>>(istream& in, Abonat_Skype& as){
in>>(Abonat&)as;
cout<<"Introdu id-ul de skype."<<endl;
in>>as.id_skype;
}

ostream& operator<<(ostream& out, Abonat_Skype& as){
out<<(Abonat&)as;
out<<as.id_skype<<endl;
}

Abonat_Skype Abonat_Skype::operator=(Abonat_Skype& as){
this->id_skype=as.id_skype;
}

istream& operator>>(istream& in,Abonat_Skype_Romania& asa){
in>>(Abonat_Skype&)asa;
cout<<"Introdu adresa de mail."<<endl;
in>>asa.adresa_mail;
}

ostream& operator<<(ostream& out, Abonat_Skype_Romania& asa){
out<<(Abonat_Skype&)asa;
out<<asa.adresa_mail<<endl;
}

Abonat_Skype_Romania Abonat_Skype_Romania::operator=(Abonat_Skype_Romania& asa){
this->adresa_mail=asa.adresa_mail;
}

istream& operator>>(istream& in,Abonat_Skype_Extern& ase){
in>>(Abonat_Skype&)ase;
cout<<"Introdu tara."<<endl;
in>>ase.tara;
}

ostream& operator<<(ostream& out, Abonat_Skype_Extern& ase){
out<<(Abonat_Skype&)ase;
out<<ase.tara<<endl;
}

Abonat_Skype_Extern Abonat_Skype_Extern::operator=(Abonat_Skype_Extern& ase){
this->tara=ase.tara;
}

class Agenda{
//Persoana *persoana= new Abonat_Skype_Extern;
//Abonat_Skype_Romania *asa=dynamic_cast<Abonat_Skype_Romania *>(persoana);
Persoana ** p;
int n;
public:
Agenda(){
cout<<"Marimea listei:"<<endl;
cin>>n;
p=new Persoana*[n];
int loop=0;
int comanda;
int nr_lista=0;
while(loop<n){
    cout<<"Abonat extern:1"<<endl<<"Abonat roman:2"<<endl;
    cin>>comanda;
    if(comanda==1){
        p[nr_lista]=new Abonat_Skype_Extern();
        cin>>*dynamic_cast<Abonat_Skype_Extern*>(p[nr_lista]);
        loop++;
        nr_lista++;
    }
    else if(comanda==2){
        p[nr_lista]=new Abonat_Skype_Romania();
        cin>>*dynamic_cast<Abonat_Skype_Romania*>(p[nr_lista]);
        loop++;
        nr_lista++;
    }
    else{
        cout<<"Comanda nu exista! Introduceti doar 1 sau 2."<<endl;
    }
}
}


void Afisare_lista(){
for(int i=0;i<n;i++){
   if(typeid(*p[i])==typeid(Abonat_Skype_Extern))
    cout<<*dynamic_cast<Abonat_Skype_Extern*>(p[i])<<endl;
   else cout<<*(Abonat_Skype_Romania*)(p[i])<<endl;
    }
}

string operator[](string nume){
for(int i=0;i<n;i++){
    if(p[i]->Nume()==nume){
        if(typeid(*p[i])==typeid(Abonat_Skype_Extern))
            cout<<*dynamic_cast<Abonat_Skype_Extern*>(p[i]);
        else cout<<*(Abonat_Skype_Romania*)(p[i])<<endl;
    }
}
}

void getn(int new_n){
this->n=new_n;
}

void Adaugare(){
int loop=n;
int nr_lista=loop;
int ab_adaugati;
int comanda;
cout<<"Cati abonati doriti sa adaugati?"<<endl;
cin>>ab_adaugati;
getn(loop+ab_adaugati);
while(loop<n){
    cout<<"Abonat extern:1"<<endl<<"Abonat roman:2"<<endl;
    cin>>comanda;
    if(comanda==1){
        p[nr_lista]=new Abonat_Skype_Extern();
        cin>>*dynamic_cast<Abonat_Skype_Extern*>(p[nr_lista]);
        loop++;
        nr_lista++;
    }
    else if(comanda==2){
        p[nr_lista]=new Abonat_Skype_Romania();
        cin>>*dynamic_cast<Abonat_Skype_Romania*>(p[nr_lista]);
        loop++;
        nr_lista++;
    }
    else{
        cout<<"Comanda nu exista! Introduceti doar 1 sau 2."<<endl;
    }
}
}

};

int main()
{
    int comanda;
    string cautare;
    cout<<"Incepeti prin a adauga valori/abonati in lista de abonati skype."<<endl;
    Agenda a;
    while(1){
        cout<<"1-Afiseaza lista"<<endl;
        cout<<"2-Cauta abonat in lista dupa nume"<<endl;
        cout<<"3-Adauga abonati in lista"<<endl;
        cin>>comanda;
        if(comanda==1){
            a.Afisare_lista();}
        else if(comanda==2){
            cout<<"Introduceti numele pe care vreti sa il cautati."<<endl;
            cin>>cautare;
            a[cautare];
        }
        else if(comanda==3){
            a.Adaugare();
        }
        else cout<<"Comanda introdusa nu exista!"<<endl;
        }




    return 0;
}
