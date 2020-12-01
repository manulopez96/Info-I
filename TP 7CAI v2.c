#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void multip(int *p,char* name);
void bien(char *name);
void mal(char *name);
void fest (char *name);


int main(void){
	
	int lv=0;
	char nombre[20]={0};
	char rep[2];
	system("color 70");
	
	do{
			
		printf("  |||Trabajo practico n°7|||\n\n");//Lopez David Emanuel 80300
		
		//printf("---LV-%d----",lv);//test
		
		printf("\n  Nombre: ");
		scanf("%s",&nombre[0]);
		system("cls");
		
		printf("  |||Trabajo practico n°7|||\n\n");
		printf("\n\n  Bienvenido mi pequeño compañero/a %s!   \n\n",nombre);
		printf("  Es hora de empezar con este aprendizaje!!\n\n");
		
		multip(&lv, nombre);
		
		printf("\n  Si queres salir ingresa 'si' :");
		scanf(" %s", &rep[0]);
		printf("\a");
	
	} while(rep[0]!='s'&&rep[1]!='i');
	
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
		case 0: printf("\n  Sos la decepcion de la familia!\n");
			break;
		case 1: printf("\n  Vos podes %s!\n",name);
			break;
		case 2: printf("\n  Esta mal, pero se que puedes!\n");
			break;
		case 3: printf("\n  Presta mas atencion, reintentalo!\n");
			break;
		case 4: printf("\n  Hacelo bien %s!\n",name);
			break;
		case 5: printf("\n  Reintentalo %s!\n",name);
			break;
	default:printf("\n  !!\n");
	}
}

void multip(int *p,char *name){
	srand(time(NULL));
	int var1;
	int var2;
	int result;
	int lv=*p+3;

	printf("  Vamos a practicar multiplicacion!\n\n  Te dare 2 numeros, tu los multiplicaras y me diras el resultado!\n\n  Si estas listo %s presiona enter! ",name);
	
	getch();
	printf("\a\a");
	system("cls");
	printf("  |||Trabajo practico n°7|||\n\n");
	
	do{		
		var1=1+rand()%(lv+4); var2=1+rand()%lv;
		do{
			printf("\n\n   CUANTO ES:  %dx%d ? \n\n   RESPUESTA: ",var1,var2);
			scanf(" %d",&result);
			
			//printf("\n----LV%d-------*P%d-------",lv,*p);//test
			
			if(result==var1*var2){
				
				bien(name);
				*p=*p+1;
			}else
				mal(name);
			getch();
		} while(result!=var1*var2);
		system("cls");
		printf("  |||Trabajo practico n°7|||\n\n");
	} while(lv!=*p);
	
	printf("\n   Genial!! Haz pasado esta prueba!!");
	fest(name);
	
}

void fest (char *name){
	
	
	system("color 00");
	getch();		bien(name);	
	system("color 1f");
	getch();	
	system("color 2e");
	getch();		bien(name);
	system("color 3d");
	getch();	
	system("color 4c");
	getch();	
	system("color 5b");
	getch();	
	system("color 6a");
	getch();
	system("color 79");
	getch();	
	system("color 88");
	getch();	
	system("color 97");
	getch();	
	system("color a6");
	getch();		
	system("color 70");
	getch();	
	
}


