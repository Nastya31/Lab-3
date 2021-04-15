#include <iostream>
#include "lab.h"
#include "func.h"
using namespace std;

int stateM;
void MainMenu() {
    cout <<"  MENU\n";
           cout<<"Добро пожаловать в базу данных по стрелковому оружию"<<endl;
           cout<<"Выберите нужный вам пункт меню"<<endl;
           cout<<"1. Посмотреть оружия"<<endl;
           cout<<"2. Поиск по критериям"<<endl;
           cout<<"3. Редактирование информации"<<endl;
           cout<<"4. Добавление своего оружия"<<endl;
           cout<<"5. Удаление информации об определенном оружии"<<endl;
           cout<<"6. Выход из базы данных"<<endl;

           cout<<"Введите выбранный вами пункт меню с клавиатуры"<<endl;
           cin>>stateM;
}
int main(int argc, char* argv[]){
    setlocale(LC_ALL,"Russian");

    string test={argv[1]};

    int kolGun = KolElFromFile(test);
    gun *C=new gun[kolGun];
    ReadFromFile(C, test);
    MainMenu();

    while (stateM !=6){
        if (stateM ==1){
            kolGun=KolElFromFile(test);
            gun *C=new gun[kolGun];
            ReadFromFile(C, test);
            for (int i=0; i<kolGun; i++){
                C[i].Print();
            }
            cout<<"------------------";
            MainMenu();
        }
        if (stateM ==2){
            cout<<("Выберите нужный поиск:\n");
                    cout<<("1-поиск по названию\n 2- поиск по калибру\n 3- поиск по массе\n");
                    int x;
                    cin>>x;
                    if(x==1) {
                        ifstream fin(test);

                        int kol;
                        string S;
                        cout<<"Введите название для поиска: ";
                        cin>>S;
                        if(fin.is_open()){
                            fin>>kol;
                            for(int i=0; i<kol; i++){
                                if(S==C[i].GetName()){
                                    C[i].Print();
                                }
                            }
                        }
                        else
                        {
                            cout<<"Ошибка открытия файла\n";
                        }
                        fin.close();
                    }
                    if(x==2) {
                        ifstream fin(test);

                    int kol;
                    int kalib;
                    cout<<"Введите калибр для поиска: ";
                    cin>>kalib;
                    if(fin.is_open()){
                        fin>>kol;
                        for(int i=0; i<kol; i++){
                            if(kalib==C[i].GetKalib()){
                                C[i].Print();
                            }
                        }
                    }
                    else
                    {
                        cout<<"Ошибка открытия файла\n";
                    }
                    fin.close();
                         }

                    if(x==3){
                        ifstream fin(test);

                    int kol;
                    int mass;
                    cout<<"Введите массу для поиска: ";
                    cin>>mass;
                    if(fin.is_open()){
                        fin>>kol;
                        for(int i=0; i<kol; i++){
                            if(mass==C[i].GetMass()){
                                C[i].Print();
                            }
                        }
                    }
                    else
                    {
                        cout<<"Ошибка открытия файла\n";
                    }
                    fin.close();
                         }
                    }
                break;
        }

        if (stateM==3){
            ifstream fin(test);
            int kol;
            fin>>kol;
                cout<<"Выберите пункт, который хотите изменить ";
                cout<<" 1- Название \n 2- Калибр\n 3- Масса \n";
                int punkt;
                cin>>punkt;
                if (punkt==1) izmenenie1(C,test);
                if (punkt==2) izmenenie2(C,test);
                if (punkt==3) izmenenie3(C,test);

            fin.close();
            cout<<"------------------";
            MainMenu();
        }
        if (stateM==4){
            string S;
            int kalib, mass;
            int newKolGun=kolGun+1;
            gun *C1=new gun[newKolGun];
            ReadFromFile(C1, test);
            cout<<"Введите название: ";
            cin>>S;
            cout<<"Введите калибр: ";
            cin>>kalib;
            cout<<"Введите массу: ";
            cin>>mass;

            C1[newKolGun -1].SetParametrs(S,kalib,mass);
            WriteInFileInputGun1(newKolGun, test, C1);

            cout<<"------------------";
            MainMenu();
}
        if (stateM==5){
            fstream fin(test);
            int kol;
            fin>>kol;
            fin.close();

            kolGun=KolElFromFile(test);
            gun *C=new gun[kolGun];
            ReadFromFile(C, test);

            string S="";
            int kalib=0;
            int mass=0;

            int indexDel;
            cout<<"Выберите номер оружия, которое нужно удалить\n";
            cin>>indexDel;


            C[indexDel -1].SetParametrs(S,kalib,mass);
            WriteInFileGun(test, C, kolGun);


            kolGun=KolElFromFile(test);
            C=new gun[kolGun];
            ReadFromFile(C, test);

            cout<<"------------------";
            MainMenu();
        }
    return 0;
}
