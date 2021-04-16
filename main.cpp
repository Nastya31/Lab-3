#include <iostream>
#include "lab.h"
#include "func.h"
using namespace std;


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

}

int main(int argc, char* argv[]){
    setlocale(LC_ALL,"Russian");

    string test = {argv[1]};

    Menu m;
    int kolGun = m.KolElFromFile(test);
    gun *C = new gun[kolGun];
    m.ReadFromFile(C,test);
    int stateM;

    while (stateM !=6){
        MainMenu();
        cin >> stateM;

        if (stateM == 1){
            kolGun=m.KolElFromFile(test);
            gun *C = new gun[kolGun];
            m.ReadFromFile(C, test);
            for (int i=0; i<kolGun; i++){
                cout << i << endl;
                C[i].Print();
                cout << endl;
            }
            cout<<"------------------";
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

        if (stateM==3){
            ifstream fin(test);
            int kol;
            fin>>kol;
                cout<<"Выберите пункт, который хотите изменить ";
                cout<<"\n 1- Название \n 2- Калибр\n 3- Масса \n";
                int punkt;
                cin>>punkt;
                if (punkt == 1){
                    fstream fin(test);
                    int kol;
                    fin>>kol;
                    fin.close();
                    m.izmenenie1(C, test);
                    m.WriteInFileInputGun1(kol, test, C);
                }
                if (punkt == 2){
                    fstream fin(test);
                    int kol;
                    fin>>kol;
                    fin.close();
                    m.izmenenie2(C, test);
                    m.WriteInFileInputGun1(kol, test, C);
                }
                if (punkt == 3){
                    fstream fin(test);
                    int kol;
                    fin>>kol;
                    fin.close();
                    m.izmenenie3(C, test);
                    m.WriteInFileInputGun1(kol, test, C);
                }

            fin.close();
            cout<<"------------------";

        }

        if (stateM==4){
            string S;
            int kalib, mass;
            int newKolGun=kolGun+1;
            gun *C1=new gun[newKolGun];
            m.ReadFromFile(C1, test);
            cout<<"Введите название: ";
            cin>>S;
            cout<<"Введите калибр: ";
            cin>>kalib;
            cout<<"Введите массу: ";
            cin>>mass;

            C1[newKolGun -1].SetParametrs(S,kalib,mass);
            m.WriteInFileInputGun1(newKolGun, test, C1);

            cout<<"------------------";

        }

        if (stateM==5){ //Пишу для себя чтобы было понятно что происходит
            fstream fin(test);
            int kol;
            fin >> kol;
            fin.close(); //считали количество элементов

            kolGun = m.KolElFromFile(test); // считали количество элементов еще раз, окей
            gun *C = new gun[kolGun]; // создали новый массив
            m.ReadFromFile(C, test); //Считали массив

            string S="";
            int kalib=0;
            int mass=0; // пока не важно

            int indexDel;
            cout<<"Выберите номер оружия, которое нужно удалить\n";
            cin>>indexDel; // это понятно


            //C[indexDel -1].SetParametrs(S, kalib, mass); //пока оставим
            //m.WriteInFileGun(test, C, kolGun); // тоже пока оставим


            for (int i=indexDel; i<kol-1; i++){ //это понял
             C[i] = C[i+1];
            }// Сдвиг массива с точки удаленного объекта

            //Вообщем что я предлогаю, погнали
            m.WriteInFileInputGun1(kol-1, test, C); //перезапишим, но без последнего



            kolGun=m.KolElFromFile(test);

            gun *new_C = new gun[kolGun];//сделаем копию перезаписи
            m.ReadFromFile(new_C, test); // считаем ее

            // Удалим старый массив и передадим в него новый
            delete[] C;
            C = new_C;

            cout<<"------------------" << endl;
            }

        if (stateM == 6){
            // Незабудем освободить динамичускую память
            delete[] C;
            return 0;
        }
    }
}
