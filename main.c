#include <stdio.h>
#include "lab.h"

int main(int argc, char * argv[]){

	FILE * fin;
	if((fin=fopen("test.txt", "r")) == NULL){
		return 0;
	}
	int n;
	fscanf(fin, "%d", &n);
	gun * array = (gun*)malloc(sizeof(gun)*n);
	for(int i = 0; i < n; i++){
		fscanf(fin, "%s", array[i].a);
		fscanf(fin, "%d", &array[i].b);
		fscanf(fin, "%d", &array[i].c);
	}
	fclose(fin);

int p;
printf("Добро пожаловать в базу данных по стрелковому оружию\n");
printf("Выберите нужный вам пункт меню\n");
printf("1. Посмотреть оружия\n");
printf("2. Поиск по критериям\n");
printf("3. Редактирование информации\n");
printf("4. Добавление своего оружия\n");
printf("5. Удаление информации об определенном оружии\n");
printf("6. Выход из базы данных\n");

printf("Введите выбранный вами пункт меню с клавиатуры\n");
scanf("%d", &p);
switch(p){
	case 1:
		printAll(n, array);
       		printf("-----------------------------\n");
	break;

	case 2:
		printf("Выберите нужный поиск:\n");
		printf("1-поиск по названию\n 2- поиск по калибру\n 3- поиск по массе\n");
		int x;
		scanf("%d",&x);
		if(x==1) poiskNazvanie(n, array);
		if(x==2) poiskKalibr(n, array);
		if(x==3) poiskMassa(n, array);
	break;

	case 3:
		izmenenie(&n,array);
	break;

	case 4:
		push(&n,array);
	break;

	case 5:
		del(&n, array);
	break;

	case 6:
	break;
	}
	 FILE * F;
        if((F=fopen("end.txt", "w")) == NULL){
                return 0;
        }
        for(int i = 0; i < n; i++){
                fprintf(F, "%s", array[i].a);
                fprintf(F, "%d", array[i].b);
                fprintf(F, "%d", array[i].c);
        }
        fclose(F);

	free(array);
return 0;
}
