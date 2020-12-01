#include <stdio.h>
#include<stdlib.h>
#define N 2
#include <conio.h>

struct resultados {
	char *tema;
	float variable;
};

void encuesta (char* temas[], int respuestas[5][N],int j){ // funcion que recolecta el puntaje
	
	int rep=0;
	for(int i=0;i<5;i++){ //bucle de asignacion en matriz respuestas
		do{ 
			system("cls");//limpia pantalla
			rep=0;
			printf(" Del 1 al 10, que importancia tiene %s:\n\n  ->   ",temas[i]);
			scanf("%d",&respuestas[i][j]);
			if(respuestas[i][j]<1||respuestas[i][j]>10){ // si el usuario ingresa puntaje invalido
				printf("  La respuesta no esta dentro de los parametros 1--10");
				rep=1;
				getch();
			}
		}while(rep==1);//repeticion de misma consigna por error de usuario
		
	}
	printf("\n  ¡Perfecto! \n\n");//fin de la funcion
}

void mas_votado (char* temas[], int respuestas[5][N]){
	struct resultados maximo;
	float prom[5];
	
	for(int i=0;i<5;i++){//inicializacion
		prom[i]=0;
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<N;j++){
			prom[i]+=respuestas[i][j];
			printf("\n %s    %f",temas[i],prom[i]);//test
		}
	}
		
	maximo.variable=prom[0];
	maximo.tema=temas[0];
	
	for(int i=1;i<5;i++){
		if(prom[i]>maximo.variable){
		maximo.variable=prom[i];
		maximo.tema=temas[i];
		}
	}
	printf("\n\n El puntaje mas alto fue de %.3f y lo obtuvo %s.\n\n",maximo.variable,maximo.tema);
}

void menos_votado(char* temas[], int respuestas[5][N]){
	struct resultados minimo;
	float prom[5];
	
	for(int i=0;i<5;i++){//inicializacion
		prom[i]=0;
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<N;j++){
			prom[i]+=respuestas[i][j];
			printf("\n %s    %f",temas[i],prom[i]);//test
		}
	}
	
	minimo.variable=prom[0];
	minimo.tema=temas[0];
	
	for(int i=1;i<5;i++){
		if(prom[i]<minimo.variable){
			minimo.variable=prom[i];
			minimo.tema=temas[i];
		}
	}
	printf("\n\n El puntaje mas bajo fue de %.3f y lo obtuvo %s",minimo.variable,minimo.tema);
	
	for(int i=0;i<5;i++){
		if(prom[i]==minimo.variable&&minimo.tema!=temas[i]){
			printf(" y %s",temas[i]);
		}
		
	}
	printf(".\n\n");
}

int main(void) {
	char* temas[5]; //puntero apuntado a temas elegidos
	int respuestas[5][N];  //guarda respuestas de los usuarios
	float promedio=0;  //guarda promedio
	
	char tema1[]="La contaminacion ambiental";  //temas elegidos
	char tema2[]="La pobreza mundial        ";  //temas elegidos
	char tema3[]="La falta de Educacion     ";  //temas elegidos
	char tema4[]="El aumento de violencia   ";  //temas elegidos
	char tema5[]="La drogadiccion           ";  //temas elegidos
	
	temas[0]=tema1;temas[1]=tema2;temas[2]=tema3;temas[3]=tema4;temas[4]=tema5;  //asignacion de direcciones en puntero temas
	
	for(int j=0;j<N;j++){                                                         //inicio del programa
	printf("  |||Trabajo practico n°8|||\n\n");//Lopez David Emanuel 80300
	
	printf("\n\n      ¡Bienvenido, te haremos una breve encuesta! ");
	printf("\n      La idea principal es saber cuales son los puntos mas relevantes para ti. ");	
		
	printf("\n\n   Los temas en cuestion son los siguientes:\n\n  1. %s\n  2. %s\n  3. %s\n  4. %s\n  5. %s",temas[0],temas[1],temas[2],temas[3],temas[4]);
		
	printf("\n\n\n     ¡Tu solo debes valuar del 1 al 10 lo que concideres mas importante! ");	
	
		getch();  //leve pausa
		system("cls");//limpia pantalla
		
		encuesta (temas,respuestas,j);  // llamado a funcion
		
		if (j<N){   //fin de encuesta a un usuario, no del total de usuarios
			printf("   Tu encuesta ya a terminado.\n   Los resultados se veran al final del ultimo encuestado.\n   Muchas gracias por tu tiempo.\n\n  ¡Exitos!\n\n");
			getch();
			system ("cls");
			printf("\n\n  Para continuar con la encuesta precione enter");
			system("cls");
		}		
	}
	printf("  ¡La encuesta ya a terminado! \n\n"); // fin de encuesta al total de usuarios
	
	printf("\n\n"); 	                                            // resultados
	printf("        --------------------------------\n"); 	
	printf("       |  ¡ Resultados de la encuesta!  |\n"); 	
	printf("        --------------------------------\n\n\n"); 
	
	printf("------------------------------");
	for(int j=0;j<N;j++){ 	//bucle para crear barra superior e identificar respuestas				
		printf("-%d-",j+1); 			
	} 	
	printf("----Promedio-\n\n");//fin de barra superior
	
	for(int i=0;i<5;i++){ 	
		printf("   %s:", temas[i]); // tema impreso a la izquierda de los resultados
		
		for(int j=0;j<N;j++){ 					
			printf(" %.2d",respuestas[i][j]); 	//llenado de filas con resultados		
		} 
		promedio=0;
		for(int j=0;j<N;j++){		   //bucle para obtencion de promedio		
			promedio+=respuestas[i][j]; 			
		}
		promedio/=N;
		
		printf("    %.2f", promedio);  //impresion de promedio al final de cada fila
		printf("\n\n");  //  cambio de fila
	}
 	
	mas_votado (temas,respuestas);
	menos_votado (temas,respuestas);
	
	return 0;
}

