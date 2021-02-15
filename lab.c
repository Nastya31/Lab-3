#include "lab.h"

void printAll(int a, gun* array){
	for(int i = 0; i < a; i++){
		printf("Название- %s Калибр- %d Масса в гр- %d\n",array[i].a, array[i].b, array[i].c);
	}
}

gun * poiskNazvanie(int a, gun* array){
	char nazv[30];
	printf("Введите название оружия \n");
	scanf("%s", nazv);
	printf("Вам подходят:\n");
	for(int i = 0; i < a; i++){
		if(strcmp(nazv, array[i].a) == 0){
			printf("Название- %s Калибр- %d Масса в гр- %d\n",array[i].a, array[i].b, array[i].c);
		}
	}
}

gun * poiskKalibr(int a, gun* array){
        int nkl;
        printf("Введите калибр \n");
        scanf("%d", &nkl);
	printf("Вам подходят:\n");
        for(int i = 0; i < a; i++){
                if(nkl>=array[i].b){
                        printf("Название- %s Калибр- %d Масса в гр- %d\n",array[i].a, array[i].b, array[i].c);
                }
        }
}

gun * poiskMassa(int a, gun* array){
        int pmas;
        printf("Введите массу \n");
        scanf("%d", &pmas);
	printf("Вам подходят:\n");
        for(int j = 0; j < a; j++){
                if(pmas>=array[j].c){
                        printf("Название- %s Калибр- %d Масса в гр- %d\n",array[j].a, array[j].b, array[j].c);
                }
        }
}

void push(int * a, gun* array){
	gun* new_array = (gun*)malloc(sizeof(gun)*(*a+1));
	for(int j = 0; j < *a; j++){
		new_array[j] = array[j];
	}
	printf("Введите название оружия ");
	char nn[30];
	scanf("%s", nn);
	strcpy(new_array[*a].a, nn);
	printf("Введите калибр оружия ");
	int kl;
	scanf("%d", &kl);
	new_array[*a].b = kl;
	printf("Введите массу оружия в граммах ");
	int mm;
	scanf("%d", &mm);
	new_array[*a].c = mm;
	*a = *a+1;
	free(array);
	array = new_array;
	 for(int i = 0; i < *a; i++){
                printf("Название- %s Калибр- %d Масса в гр- %d\n",array[i].a,array[i].b,array[i].c);
        }

}

void del(int *a, gun* array){
	printf("Введите номер строки оружия, которое нужно удалить ");
	int index;
	scanf("%d", &index);
	for(int i = index-1; i < (*a-1); i++){
		array[i] = array[i+1];
	}
	*a = *a-1;
	 for(int i = 0; i < *a; i++){
                printf("Название- %s Калибр- %d Масса в гр- %d\n",array[i].a,array[i].b,array[i].c);
        }

}

void izmenenie(int *a, gun* array){
	printf("Введите число строки, в которой вы хотите изменить элемент ");
	int e;
	scanf("%d", &e);
	printf("Выберите пункт, который хотите изменить ");
	printf(" 1- Название \n 2- Калибр\n 3- Масса \n");
	int punkt;
	scanf("%d", &punkt);
		if (punkt==1){
				printf("Введите новое название ");
				char nnew[20];
				scanf("%s",nnew);
				strcpy(array[e-1].a, nnew);
			}
		if (punkt==2){
                                printf("Введите новый калибр ");
                                int nnewKl;
                                scanf("%d",&nnewKl);
                                array[e-1].b= nnewKl;
                        }
		if (punkt==3){
                                printf("Введите новую массу ");
                                int nnewMs;
                                scanf("%d",&nnewMs);
                                array[e-1].c=nnewMs;
                        }
	for(int i = 0; i < *a; i++){
                printf("Название- %s Калибр- %d Масса в гр- %d\n",array[i].a,array[i].b,array[i].c);
        }

}
