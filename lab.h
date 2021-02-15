#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gun {
	char a[30];
	int b;
	int c;
}gun;

void printAll(int a, gun* array);
void push(int * a, gun* array);
void del(int * a, gun* array);
gun* poiskNazvanie(int a, gun* array);
gun* poiskKalibr(int a, gun* array);
gun* poiskMassa(int a, gun* array);
void izmenenie(int *a, gun* array);
