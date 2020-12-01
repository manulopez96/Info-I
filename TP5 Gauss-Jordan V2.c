#include <stdio.h>
#include <stdlib.h>
#define N 12  //Cantidad de numeros en el arreglo

int main(void) {

	float aux=0;
	int i;
	char rep='y';
	float m[N];
	printf("Trabajo practico nº5 - resolucion de sistema de ecuaciones");
	
	while(rep=='y'){
	rep=5 ;
	
	for(i=0;i<N;i++){
		m[i]=0;
	}
	printf("\n\n\t --------------------------");
	printf("\n\t|Gauss-Jordan de matriz 3x3|");
	printf("\n\t --------------------------");
		
	printf("\n\nIngrese los 3 digitos del primer sistema separados con espacios:");//3 digitos 
	scanf("%f %f %f", &m[0],&m[1],&m[2]);
	printf("\n\nIngrese el resultado del primer sistema:");//1 digito
	scanf("%f",&m[3]);
	system("cls");
	printf("\n\n\t --------------------------");
	printf("\n\t|Gauss-Jordan de matriz 3x3|");
	printf("\n\t --------------------------");
	printf("\n\nIngrese los 3 digitos del segundo sistema separados con espacios:");//3 digitos
	scanf("%f %f %f", &m[4],&m[5],&m[6]);
	printf("\n\nIngrese el resultado del segundo sistema:");//1 digito
	scanf("%f",&m[7]);
	system("cls");
	printf("\n\n\t --------------------------");
	printf("\n\t|Gauss-Jordan de matriz 3x3|");
	printf("\n\t --------------------------");
	printf("\n\nIngrese los 3 digitos del tercer sistema separados con espacios:");//3 digitos
	scanf("%f %f %f", &m[8],&m[9],&m[10]);
	printf("\n\nIngrese el resultado del tercer sistema:");//1 digito
	scanf("%f",&m[11]);
	system("cls");
	printf("\n\n\t --------------------------");
	printf("\n\t|Gauss-Jordan de matriz 3x3|");
	printf("\n\t --------------------------\n\n");
	
	//float m[12]={-3,3,2,1,4,1,-1,2,1,-2,1,3};//--borrar al terminar-- este el sistema que la consigna usa de prueba
	
	/*for(i=0;i<N;i++){//armado de sistema en forrma matricial
		printf("\t m[%i] %.1f  ",i,m[i]);
		if(i==2||i==6||i==10)
			printf("\t  =  ");
		if(i==3||i==7)                              esta impresion la use para identificar mas facilmente el lugar que ocupa cada valor en el arreglo
			printf("\n");
	}
	aux=m[0];
	for(i=0;i<=3;i++){m[i]/=aux;}*/
	
	printf("\n\n");	for(i=0;i<N;i++){printf("\t%.1f  ",m[i]);if(i==2||i==6||i==10)printf("\t  =  ");if(i==3||i==7)printf("\n");}
	//armado del sistema en forma matricial - es igual a la primera, pero ocupa menos espacio
	
	m[5]=((m[0]*m[5])-(m[4]*m[1]));
	m[6]=((m[0]*m[6])-(m[4]*m[2]));
	m[7]=((m[0]*m[7])-(m[4]*m[3]));
	m[9]=((m[0]*m[9])-(m[8]*m[1]));
	m[10]=((m[0]*m[10])-(m[8]*m[2]));
	m[11]=((m[0]*m[11])-(m[8]*m[3]));
	m[4]=m[8]=0;
	
	printf("\n\n");	for(i=0;i<N;i++){printf("\t%.1f  ",m[i]);if(i==2||i==6||i==10)printf("\t  =  ");if(i==3||i==7)printf("\n");}
	//armado del sistema en forma matricial
	
	aux=m[5];
	for(i=4;i<=7;i++){m[i]/=aux;}
	
	printf("\n\n");	for(i=0;i<N;i++){printf("\t%.1f  ",m[i]);if(i==2||i==6||i==10)printf("\t  =  ");if(i==3||i==7)printf("\n");}
	//armado del sistema en forma matricial
	
	m[10]=((m[5]*m[10])-(m[9]*m[6]));
	m[11]=((m[5]*m[11])-(m[9]*m[7]));
	m[2]=((m[5]*m[2])-(m[6]*m[1]));
	m[3]=((m[5]*m[3])-(m[7]*m[1]));
	m[1]=m[9]=0;
	
	aux=m[10];
	for(i=8;i<=11;i++){m[i]/=aux;}
	
	printf("\n\n");	for(i=0;i<N;i++){printf("\t%.1f  ",m[i]);if(i==2||i==6||i==10)printf("\t  =  ");if(i==3||i==7)printf("\n");}
	//armado del sistema en forma matricial
	
	m[7]=((m[10]*m[7])-(m[11]*m[6]));
	m[3]=((m[10]*m[3])-(m[11]*m[2]));
	m[2]=m[6]=0;
	
	printf("\n\n");	for(i=0;i<N;i++){printf("\t%.1f  ",m[i]);if(i==2||i==6||i==10)printf("\t  =  ");if(i==3||i==7)printf("\n");}
	//armado del sistema en forma matricial
	
	printf("\n\n\t La Solucion del sistema es :\n");
	printf("\n\n\t X = %.1f",m[3]);
	printf("\n\n\t Y = %.1f",m[7]);
	printf("\n\n\t Z = %.1f",m[11]);
	
	printf("\n\n\nSi desea resolver otro sistema ingrese 'y':");
	scanf ("%s",&rep);
	system("cls");
}
	
	return 0;
}

