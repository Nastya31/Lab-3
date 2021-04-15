#include "func.h"

int KolElFromFile(string nameFile){
    ifstream fin(nameFile);
    int k;

    if (fin.is_open()){
        fin>>k;
    }
    else
        cout <<"Ошибка открытия файла\n";
    fin.close();
    return k;
}

void ReadFromFile(gun *C, string nameFile){
    ifstream fin(nameFile);

    int kol;
    string S;
    int kalib;
    int mass;

    if(fin.is_open()){
        fin>>kol;
        for(int i=0; i<kol; i++){
            fin>>S;
            fin>>kalib;
            fin>>mass;

            C[i].SetParametrs(S, kalib, mass);
        }
    }
    else
    {
        cout<<"Ошибка открытия файла\n";
    }
    fin.close();
}

void WriteInFileGun(string nameF, gun *C, int w){
    ofstream fout(nameF, std::ios::out);
    if (fout.is_open()){
        for (int i=0; i<w; i++){
            C[i].AddToFile(nameF);
        }
    }
    else
        cout<<"Ошибка открытия файла\n";
    fout.close();
}
void WriteInFileInputGun(string nameF, gun *C, int w){//ф-ция для удаления
    ofstream fout(nameF, std::ios::out);//создали объект, который открывает файл для записи и перезаписывает информацию
    if (fout.is_open()){
        fout<< w-1<<endl;//уменьшаем кол-во
        for (int i=0;i<w;i++){
            C[i].AddToFile1(nameF);
        }
    }
    else
        cout<<"Ошибка открытия файла\n";
    fout.close();
}

void WriteInFileInputGun1(int w, string nameF, gun*C){//ф-ция для дополнения
    ofstream fout(nameF, std::ios::out);
    if (fout.is_open()){
        fout<< w<<endl;
        for (int i=0;i<w;i++){
            C[i].AddToFile1(nameF);
        }
    }
    else
        cout<<"Ошибка открытия файла\n";
    fout.close();
}
void izmenenie1(gun *C, string nameFile){
    cout<<"Введите число строки, в которой вы хотите изменить элемент ";
        int e;
        cin>>e;
                    cout<<"Введите новое название ";
                    string nnew;
                    cin>>nnew;
                    C[e].GetName()= nnew;

            for(int i = 0; i < 3; i++){
                    C[i].Print();
            }
}
void izmenenie2(gun *C, string nameFile){
    cout<<"Введите число строки, в которой вы хотите изменить элемент ";
        int e;
        cin>>e;
                    cout<<"Введите новый калибр ";
                    int nnewKl;
                    cin>>nnewKl;
                    //C[e].GetKalib()= nnewKl;

                    for(int i = 0; i < 3; i++){
                    C[i].Print();
            }
}
void izmenenie3(gun *C, string nameFile){
    cout<<"Введите число строки, в которой вы хотите изменить элемент ";
        int e;
        cin>>e;
                    cout<<"Введите новую массу ";
                     int nnewMs;
                     cin>>nnewMs;
                     //C[e].GetMass()= nnewMs;

                    for(int i = 0; i < 3; i++){
                    C[i].Print();
            }
}
