//описание методов gun
#include "lab.h"

gun::gun(){
    //пустой объект
    name="";
    kalibr=0;
    massa=0;
}

gun::gun(string S, int kalib, int mass){
    //создаем объект
    name=S;
    kalibr=kalib;
    massa=mass;
}

gun::~gun(){
    //удаляет объект
}

void gun::Print(){
    if (name != ""){
        cout<<"Название: "<<name<<endl;
        cout<<"Калибр: "<<kalibr<<endl;
        cout<<"Масса: "<<massa<<endl;
    }
}

void gun::SetParametrs(string S, int kalib, int mass){
    name = S;
    kalibr = kalib;
    massa = mass;
}

void gun::AddToFile(string NameF){
    ofstream fout(NameF, std::ios::app);

    if (fout.is_open()){
        fout << "Название: "<<name<<endl;
        fout<<"Калибр: "<<kalibr<<endl;
        fout<<"Масса: "<<massa<<endl;
    }
    else
        cout<<"Ошибка открытия файла\n";

   fout.close();
}
void gun::AddToFile1(string NameF){
    ofstream fout(NameF, std::ios::app);

    if (fout.is_open()){
        fout<<name<<endl;
        fout<<kalibr<<endl;
        fout<<massa<<endl;
    }
    else
        cout<<"Ошибка открытия файла\n";

   fout.close();
}

void gun::SetName(string S){
    if (S != ""){
        name = S;
    }
    else{
        cout<<"Ошибка"<<endl;
    }
}

int gun::SetKalib(int kalib){
    if (kalib != 0){
        kalibr = kalib;
    }

    else{
        cout<<"Ошибка"<<endl;
    }
   return kalib;
}

int gun::SetMass(int mass){
    if (mass != 0){
        massa = mass;
    }
    else{
        cout<<"Ошибка"<<endl;
    }
    return mass;
}
