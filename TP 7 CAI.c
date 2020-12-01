#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void multip(int *p,char* name);
void bien(char *name);
void mal(char *name);



int main(void) {
	int lv=0;
	char nombre[20]={0};
	char rep[2];
	do{
			
	printf("  |||Trabajo practico n°7|||\n\n");//Lopez David Emanuel 80300

	printf("---LV-%d----",lv);//test
	
	printf("\n  Nombre: ");
	scanf("%s",&nombre[0]);
	system("cls");
	printf("\n\n  Bienvenido mi pequeño compañero/a %s!   \n\n",nombre);
	printf("  Es hora de empezar con este aprendizaje!!\n\n");
	
	multip(&lv, nombre);
	
	printf("\n  Si queres salir ingresa 'no' :");
	scanf(" %s", &rep[0]);
	
	} while(rep[0]!='n'&&rep[1]!='o');
	
	return 0;
}

void bien(char *name){
	srand(time(NULL));
	int n;
	n=rand()%6;
	
	switch(n){
	case 0: printf("\n  Muy bien %s!!!\n",name);
	break;
	case 1: printf("\n  Exelente %s!!!\n",name);
	break;
	case 2: printf("\n  Bien hecho %s!!!\n",name);
	break;
	case 3: printf("\n  Te felicito %s!!!\n",name);
	break;
	case 4: printf("\n  Perfecto!!!\n");
	break;
	case 5: printf("\n  Bien, muy bien %s!!!\n",name);
	break;
	default:printf("\n  Perfectirigillo!!\n");
	}
}

void mal(char *name){
	srand(time(NULL));
	int n;
	n=rand()%6;
	
	switch(n){
	case 0: printf("\n  Sos la decepcion de la familia!!!\n");
	break;
	case 1: printf("\n  Horrible %s!!!\n",name);
	break;
	case 2: printf("\n  Inutil!!\n");
	break;
	case 3: printf("\n  Pedaso de infeliz!!\n");
	break;
	case 4: printf("\n  Hacelo bien %s!!!\n",name);
	break;
	case 5: printf("\n  Reintentalo %s!!!\n",name);
	break;
	default:printf("\n  !!\n");
	}
}

void multip(int *p,char *name){
	srand(time(NULL));
	int var1;
	int var2;
	int result;
	int lv=*p+5;
	printf("  Vamos a practicar multiplicacion!\n\n  Te dire 2 numeros, tu los multiplicaras y me diras el resultado!\n\n  Si estas listo %s presiona enter! ",name);
	
	getch();
	system("cls");
	
	do{		
		var1=1+rand()%10; var2=1+rand()%5;
		do{
			printf("\n\n   CUANTO ES:  %dx%d ? \n\n   RESPUESTA: ",var1,var2);
			scanf(" %d",&result);
			
			printf("\n----LV%d-------*P%d-------",lv,*p);//test
			
			if(result==var1*var2){
				
				bien(name);
				*p=*p+1;
			}else
				mal(name);
			getch();
		} while(result!=var1*var2);
		system("cls");
	} while(lv!=*p);
	
	printf("\n   Genial!! Haz pasado esta prueba!!");
	
	
}



