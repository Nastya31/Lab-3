#ifndef LAB_H
#define LAB_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class gun{
private:
    string name;//название оружия
    int kalibr;
    int massa;

public:
    gun();//конструктор
    gun(string N, int k, int m);
    ~gun();//диструктор

    void Print();
    void SetParametrs(string S, int kalib, int mass);

    string GetName() {return name;};
    int GetKalib() {return kalibr;};
    int GetMass() {return massa;};
    void AddToFile(string NameF);//добавление в файл
    void AddToFile1(string NameF);
};


#endif // LAB_H
