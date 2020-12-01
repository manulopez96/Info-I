#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 6

int main(void) {
	
	int matriz [12][2]={0};
	int dado_1 =0;int dado_2=0;int dados=0;
	srand(time(NULL));//Inicializacion del random number
	
	for(int j=0;j<12;j++){
		for(int i=0;i<2;i++){
			if (j==0){
				matriz[i][j]=i+2;
				printf(" %d  ",matriz[i][j]);
			}else{
			matriz[i][j]=0;
			printf(" %d  ",matriz[i][j]);
			}
		}
		printf("\n\n");
	}
	/*for(int i=0;i<36000;i++){
	
		printf("\n\nLanzamiento Nº: %d",i+1);
	
		dado_1=(1+rand()%N);//Numero random asignado a dado_1
		printf("\n\n DADO Nº1: %d",dado_1);
	
		dado_2=(1+rand()%N);//Numero random asignado a dado_2
		printf("\n\n DADO Nº2: %d",dado_2);
	
		printf("\n\n");
	
		dados=dado_1+dado_2;
		printf("Su \"Suerte\" tiene forma de : %d",dados);
	
		switch (dados){
			case 2:matriz[0][1]++;
				break;
			case 3:matriz[1][1]++;
				break;
		}
	}*/
	return 0;
}

