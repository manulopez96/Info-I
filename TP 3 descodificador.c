#include <stdio.h>

int main(void) {
	
	int num1=0;
	
	int vara=0;int varb=0;int varc=0;int vard=0;//descompocicion del entero
	
	int varA=0;int varB=0;int varC=0;int varD=0;//auxiliar de operaciones
	
	char rep='y';//variable repeticion error
	
	while (rep=='y'){
		
		rep='n';//salida del bucle
		num1=0;
		
	printf("ingrese el numero de 4 cifras que quiere descodificar: ");
	scanf("%d", &num1);
	
	if ((num1>=0)&&(num1<=9999)){
	
	vard=num1%10;//separacion de unidades
	num1/=10;
	varc=num1%10;//separacion de unidades
	num1/=10;
	varb=num1%10;//separacion de unidades
	num1/=10;
	vara=num1;//separacion de unidades
	
	vara+=3;//recompocion de divicion y de suma de codificación
	varb+=3;//recompocion de divicion y de suma de codificación
	varc+=3;//recompocion de divicion y de suma de codificación
	vard+=3;//recompocion de divicion y de suma de codificación
	
	varA=vara%10;//separacion de ultimo digito mediante resto
	varB=varb%10;//separacion de ultimo digito mediante resto
	varC=varc%10;//separacion de ultimo digito mediante resto
	varD=vard%10;//separacion de ultimo digito mediante resto
	
	vara=varC;//cambio de posiciones
	varb=varD;//cambio de posiciones
	varc=varA;//cambio de posiciones
	vard=varB;//cambio de posiciones
	
	num1=((vara*1000)+(varb*100)+(varc*10+vard));//armado en un solo entero
	
	printf(" \n variables descodficadas: %d%d%d%d", vara, varb, varc, vard);
	
	}	
	else {
		
		printf("\n   El numero que ingreso posee mas de 4 cifras\n\n    Si desea intentarlo nuevamente ingrese 'y': ") ;
		scanf("%s", &rep);
		printf("\n");
		
	}
	}
	return 0;
}
