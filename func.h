#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <string>
#include "lab.h"

using namespace std;

int KolElFromFile(string nameFile);
void ReadFromFile(gun *C, string nameFile);
void WriteInFileGun(string nameF, gun *C, int w);
void WriteInFileInputGun( string nameF, gun *C,int w);
void WriteInFileInputGun1( int w,string nameF, gun *C);
void izmenenie1(gun *C, string nameFile);
void izmenenie2(gun *C, string nameFile);
void izmenenie3(gun *C, string nameFile);
#endif // FUNC_H

