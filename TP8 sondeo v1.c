#include <stdio.h>
#include<stdlib.h>
#define N 10
#include <conio.h>

void encuesta (char* temas[], int respuestas[5][N],int j){
	int rep=0;
	for(int i=0;i<N;i++){
		//do{
			printf(" Del 1 al 10, que importancia tiene:\n\n %s ->   ",temas[i]);
			scanf("%d",respuestas[i][j]);
			/*if(respuestas[i][j]<1||respuestas[i][j]>10){
				printf("  La respuesta no esta dentro de los parametros 1--10");
				rep=1;
			}
		}while(rep=1);*/
	}
}
int main(void) {
	for(int j=1;j<=N;j++){
	printf("  |||Trabajo practico n°8|||\n\n");//Lopez David Emanuel 80300
	
	printf("\n\n      ¡Bienvenido, te haremos una breve encuesta! ");
	printf("\n     La idea principal es saber cuales son los puntos mas relevantes para ti. ");
	
	char* temas[5];
	int respuestas[5][N];
	
	char tema1[]="El patriarcado";
	char tema2[]="El macho opresor";
	char tema3[]="El aborto legal";
	char tema4[]="Les gallines violades";
	char tema5[]="La oprecion causada por usar corpiño";
		
	temas[0]=tema1;temas[1]=tema2;temas[2]=tema3;temas[3]=tema4;temas[4]=tema5;
		
	printf("\n\n   Los temas en cuestion son los siguientes:\n\n  1. %s\n  2. %s\n  3. %s\n  4. %s\n  5. %s",temas[0],temas[1],temas[2],temas[3],temas[4]);
		
		getch();
		system("cls");
		
		encuesta (temas,respuestas,j);
		
			
		/*for(int i=0;i<5;i++){
			for(int k=0;k<10;k++){
				respuestas[i][k]=k;
			}printf(" \n");
		}
		
		for(int i=0;i<5;i++){
			for(int k=0;k<N;k++){
				printf(" \t%d", respuestas[i][k]);
			}printf(" \n");
		}
		getch();*/
	}
	
	return 0;
}

