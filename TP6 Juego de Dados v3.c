#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 6

int main(void) {
	
	char rep='n';
	do{
	int matriz [11][2]={0};
	int dado_1 =0;int dado_2=0;int dados=0;
	srand(time(NULL));//Inicializacion del random number
	
	printf("  -------------------------------------\n");
	printf("  Trabajo practico N°6 - Juego de dados\n");
	printf("  -------------------------------------\n\n\n");
	
	printf("   Bienvenido! Esta por iniciar la simulacion!  ");
	system("pause");
	printf("\n\n\n");
	
	for(int i=0;i<11;i++){
		for(int j=0;j<2;j++){
			if (j==0){
				matriz[i][j]=i+2;
			}else {
				matriz[i][j]=0;
			}
		}
	}
	for(int i=0;i<36000;i++){
		
		dado_1=(1+rand()%N);//Numero random asignado a dado_1
		dado_2=(1+rand()%N);//Numero random asignado a dado_2
		dados=dado_1+dado_2;
		
		matriz[dados-2][1]++;
	}
	for(int i=0;i<11;i++){
		for(int j=0;j<2;j++){
			if (j==0){
				printf("La cantidad de %.2d ",matriz[i][j]);
			}else{
			printf("aparecidos es de: %d",matriz[i][j]);
			}
		}
		printf("\n");
	}	
	printf("\n\nSi desea reintentar ingrese elcaracter Y :");
	scanf("%c",&rep);
	fflush(stdin);
	system("cls");
	}while(rep=='y'||rep=='Y');
	
	return 0;
}

