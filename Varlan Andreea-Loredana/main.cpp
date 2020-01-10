#include <iostream>

using namespace std;

int nr_inregistrare_glob=100;

class DosarIF{
    protected:
int nr_inregistrare;
    public:
DosarIF(){
nr_inregistrare=nr_inregistrare_glob;
nr_inregistrare_glob++;
}
void nr(){
cout<<nr_inregistrare<<endl;
}
};

class DosarID{
    protected:
int nr_inregistrare;
float nota_mate;
    public:
DosarID(){
nr_inregistrare=nr_inregistrare_glob;
nr_inregistrare_glob++;
}
void Mate(){
cin>>nota_mate;
}
void nr(){
cout<<nr_inregistrare<<endl;
}
};

class DosarID2{
    protected:
int nr_inregistrare;
string studii_absolvite;
    public:
DosarID2(){
nr_inregistrare=nr_inregistrare_glob;
nr_inregistrare_glob++;
}
void Studii(){
cin>>studii_absolvite;
}
void nr(){
cout<<nr_inregistrare<<endl;
}
};

class DosarIF2{
    protected:
int nr_inregistrare;
string studii_absolvite;
    public:
DosarIF2(){
nr_inregistrare=nr_inregistrare_glob;
nr_inregistrare_glob++;
}
void Studii(){
cin>>studii_absolvite;
}
void nr(){
cout<<nr_inregistrare<<endl;
}
};


class Candidat:public DosarID, public DosarID2, public DosarIF,public  DosarIF2{
string nume;
float medie_bac;
DosarID *did;
DosarID2 *did2;
DosarIF *dif;
DosarIF2 *dif2;
public:
void put(){
int tip;
cout<<"Nume:";
cin>>nume;
cout<<"Medie bac:";
cin>>medie_bac;
cout<<"Numar dosare:";
int nr_dosare;
cin>>nr_dosare;
int contor=0;
bool id=false;
bool id2=false;
bool if1=false;
bool if2=false;
while(contor!=nr_dosare){
cout<<"Tip dosar:"<<endl<<"ID-1"<<endl<<"ID facultate 2-2"<<endl<<"IF-3"<<endl<<"IF facultate 2-4"<<endl;
cin>>tip;
if(tip==1){
    if(id==false){
    did=new DosarID;
    cout<<"Nota Matematica Bac:";
    did->Mate();
    did->nr();
    contor++;
    id=true;}
    else{
        cout<<"Nu poti avea doua dosare de acelasi tip!"<<endl;
    }
}
else if(tip==2){
    if(id2==false){
    did2=new DosarID2;
    did2->Studii();
    contor++;
    id2=true;}
    else{
        cout<<"Nu poti avea doua dosare de acelasi tip!"<<endl;
    }
}
else if(tip==3){
    if(if1==false){
    dif=new DosarIF;
    contor++;
    if1=true;}
    else{
        cout<<"Nu poti avea doua dosare de acelasi tip!"<<endl;
    }
}
else if(tip==4){
        if(if2==false){
    dif2=new DosarIF2;
    dif2->Studii();
    contor++;
    if2=true;}
    else{
        cout<<"Nu poti avea doua dosare de acelasi tip!"<<endl;
    }
}
else{
    cout<<"Comanda introdusa este gresita!";
}
}

}
void get(){
cout<<"Nume:"<<nume<<endl;
cout<<"Medie bac:"<<medie_bac<<endl;
cout<<"Dosare:";
//did->nr;
//did2->nr;
//dif->nr;
//dif2->nr;
}
};


int main()
{
   /*Varlan Andreea-Loredana
   Grupa 253
   CodeBlocks */

    Candidat *c;
    c=new Candidat;
    c->put();
    c=new Candidat;
    c->put();


    return 0;
}
