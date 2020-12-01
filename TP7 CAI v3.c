#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define N 4

void multip(int *p,char* name,int* calificacion);
void suma(int *p,char* name,int* calificacion);
void resta(int *p,char* name,int* calificacion);
void aleatorio(int *p,char* name,int* calificacion);
void bien(char *name);
void mal(char *name);
void fest (char *name);


int main(void){
	
	int lv=1;
	int op=0;
	int calificacion=0;
	char nombre[20]={0};
	char rep[2];
	system("color 70");
	
	do{
		calificacion=0;	
		printf("  |||Trabajo practico n°7|||\n\n");//Lopez David Emanuel 80300
		
		printf("\n  Nombre: ");
		scanf("%s",&nombre[0]);
		system("cls");
		
		printf("  |||Trabajo practico n°7|||\n\n");
		printf("\n\n  Bienvenido mi pequeño compañero/a %s!   \n\n",nombre);
		printf("  Es hora de empezar con este aprendizaje!!\n\n");
		
		printf("  Ingrese un nivel de dificultad: ");
		scanf("%d",&lv);
		
		printf("\n ¿Que operacion te gustaria practicar?\n\n  1)  Suma.\n  2)  Resta.\n  3)  Multiplicacion\n  4)  Aleatorio\n\n");
		scanf("%d",&op);
		
		switch (op){
		case 1: suma(&lv, nombre,&calificacion);
			break;
		case 2: resta(&lv, nombre,&calificacion);
			break;
		case 3: multip(&lv, nombre,&calificacion);
			break;
		case 4: aleatorio(&lv, nombre,&calificacion);
			break;
		}
		//suma(&lv, nombre,&calificacion);
		//resta(&lv, nombre,&calificacion);
		//multip(&lv, nombre,&calificacion);
		//aleatorio(&lv, nombre,&calificacion);
		
		printf("  Respondiste correctamente %d de 10 preguntas!\n  Lo cual quiere decir que tuviste un %d por ciento de aciertos!",calificacion,(calificacion*100/N));
		
		
		if (((calificacion*100)/N)>=75){
			fest(nombre);
			printf("\n  Si queres reintentar ingresa 'si' :");
			scanf(" %s", &rep[0]);
			printf("\a");
		}else{
			printf("\n\n   Necesitas practicar mas..\n   ¡Puedes pedirle ayuda a tu profesor! ¡Nos vemos %s!",nombre);
		}
		
	
	} while(rep[0]=='s'&&rep[1]=='i');
	system("cls");
	
	return 0;
}

void bien(char *name){                                                          //respuesta correcta
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

void mal(char *name){                                                           //respuesta erronea
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

void suma(int *plv,char *name, int *c){                                         //suma
	srand(time(NULL));
	int var1;
	int var2;
	int result;
	int lv=*plv*5;
	int cont=0;
	
	printf("  Vamos a practicar suma!\n\n  Te dare 2 numeros, tu los sumaras y me diras el resultado!\n\n  Si estas listo %s presiona enter! ",name);
	
	getch();
	printf("\a\a");
	system("cls");
	printf("  |||Trabajo practico n°7|||\n\n");
	
	do{		
		var1=1+rand()%(lv+4); var2=1+rand()%lv;
		do{
			printf("\n\n   CUANTO ES:  %d+%d ? \n\n   RESPUESTA: ",var1,var2);
			scanf(" %d",&result);
			
			if(result==var1+var2){
				bien(name);
				*c=*c+1;
			}else
			   mal(name);
			cont++;
			printf("-----cal %d de cont %d----",*c,cont);
			getch();
		} while(result!=var1+var2&&cont<N);
		system("cls");
		printf("  |||Trabajo practico n°7|||\n\n");
	} while(cont<N);
	
	printf("\n   Genial %s!! Ha terminado esta prueba!!\n",name);		
}
void resta(int *plv,char *name, int *c){                                       //resta
	srand(time(NULL));
	int var1;
	int var2;
	int result;
	int lv=*plv*5;
	int cont=0;
	
	printf("  Vamos a practicar resta!\n\n  Te dare 2 numeros, tu los restaras y me diras el resultado!\n\n  Si estas listo %s presiona enter! ",name);
	
	getch();
	printf("\a\a");
	system("cls");
	printf("  |||Trabajo practico n°7|||\n\n");
	
	do{		
		var1=1+rand()%(lv+4); var2=1+rand()%lv;
		do{
			printf("\n\n   CUANTO ES:  %d-%d ? \n\n   RESPUESTA: ",var1,var2);
			scanf(" %d",&result);
			
			if(result==var1-var2){
				bien(name);
				*c=*c+1;
			}else
			   mal(name);
			cont++;
			printf("-----cal %d de cont %d----",*c,cont);
			getch();
		} while(result!=var1-var2&&cont<N);
		system("cls");
		printf("  |||Trabajo practico n°7|||\n\n");
	} while(cont<N);
	
	printf("\n   Genial %s!! Ha terminado esta prueba!!\n",name);		
}
void multip(int *plv,char *name, int *c){                                       //multiplicacion
	srand(time(NULL));
	int var1;
	int var2;
	int result;
	int lv=*plv*5;
	int cont=0;
	
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
			
			if(result==var1*var2){
				bien(name);
				*c=*c+1;
			}else
			   mal(name);
			cont++;
			printf("-----cal %d de cont %d----",*c,cont);
			getch();
		} while(result!=var1*var2&&cont<N);
		system("cls");
		printf("  |||Trabajo practico n°7|||\n\n");
	} while(cont<N);
	
	printf("\n   Genial %s!! Ha terminado esta prueba!!\n",name);		
}
void aleatorio(int *plv,char *name, int *c){                                       //Random
	srand(time(NULL));
	int var1;
	int var2;
	int result;
	int lv=*plv*5;
	int cont=0;
	int n=0;
	
	printf("  Vamos a practicar todas las operaciones!\n\n  Te dare 2 numeros, tu los calcularas y me diras el resultado!\n\n  Si estas listo %s presiona enter! ",name);
	
	getch();
	printf("\a\a");
	system("cls");
	printf("  |||Trabajo practico n°7|||\n\n");
	
	do{	
		n=1+rand()%3;
		var1=1+rand()%(lv+4); var2=1+rand()%lv;
		switch(n){
		case 1:                                                                 //caso 1 multiplicacion
			do{
			printf("\n\n   CUANTO ES:  %dx%d ? \n\n   RESPUESTA: ",var1,var2);
			scanf(" %d",&result);
			
			if(result==var1*var2){
				bien(name);
				*c=*c+1;
			}else
			   mal(name);
			cont++;
			printf("-----cal %d de cont %d----",*c,cont);
			getch();
		} while(result!=var1*var2&&cont<N);
		system("cls");
		printf("  |||Trabajo practico n°7|||\n\n");
		break;
		case 2:                                                                 //caso 2 resta
			do{
				printf("\n\n   CUANTO ES:  %d-%d ? \n\n   RESPUESTA: ",var1,var2);
				scanf(" %d",&result);
				
				if(result==var1-var2){
					bien(name);
					*c=*c+1;
				}else
				   mal(name);
				cont++;
				printf("-----cal %d de cont %d----",*c,cont);
				getch();
			} while(result!=var1-var2&&cont<N);
			system("cls");
			printf("  |||Trabajo practico n°7|||\n\n");
			break;
		case 3:                                                                 //caso 3 suma
			do{
				printf("\n\n   CUANTO ES:  %d+%d ? \n\n   RESPUESTA: ",var1,var2);
				scanf(" %d",&result);
				
				if(result==var1+var2){
					bien(name);
					*c=*c+1;
				}else
				   mal(name);
				cont++;
				printf("-----cal %d de cont %d----",*c,cont);
				getch();
			} while(result!=var1+var2&&cont<N);
			system("cls");
			printf("  |||Trabajo practico n°7|||\n\n");
			break;
	}
	}while(cont<N);
	
	printf("\n   Genial %s!! Ha terminado esta prueba!!\n",name);		
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




