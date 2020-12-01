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
	
	for(int i=0;i<11;i++){
		for(int j=0;j<2;j++){
			if (j==0){
				matriz[i][j]=i+2;
				printf(" %d  ",matriz[i][j]);
			}else {
				matriz[i][j]=0;
				printf(" %d  ",matriz[i][j]);
			}
		}
		printf("\n\n");
	}
	for(int i=0;i<36000;i++){
	
		//printf("\n\nLanzamiento Nº: %d",i+1);
	
		dado_1=(1+rand()%N);//Numero random asignado a dado_1
		//printf("\n\n DADO Nº1: %d",dado_1);
	
		dado_2=(1+rand()%N);//Numero random asignado a dado_2
		//printf("\n\n DADO Nº2: %d",dado_2);
	
		//printf("\n\n");
	
		dados=dado_1+dado_2;
		//printf("Su \"Suerte\" tiene forma de : %d",dados);
	
			switch (dados){
				case 2:
					matriz[0][1]++;
					break;
				case 3:matriz[1][1]++;
					break;
				case 4:matriz[2][1]++;
					break;
				case 5:matriz[3][1]++;
					break;
				case 6:matriz[4][1]++;
					break;
				case 7:matriz[5][1]++;
					break;
				case 8:matriz[6][1]++;
					break;
				case 9:matriz[7][1]++;
					break;
				case 10:matriz[8][1]++;
					break;
				case 11:matriz[9][1]++;
					break;
				case 12:matriz[10][1]++;
					break;
		}
	}
	
	for(int i=0;i<11;i++){
		for(int j=0;j<2;j++){
			if (j==0){
				printf("la cantidad de %d ",matriz[i][j]);
			}else{
			printf("aparecidos es de: %d",matriz[i][j]);
			}
		}
		printf("\n\n");
	}	
	printf("\n\nSi desea reintentar ingrese elcaracter Y :");
	fflush(stdin);
	scanf("%c",&rep);
	}while(rep=='y'||rep=='Y');
	system("cls");
	return 0;
}

