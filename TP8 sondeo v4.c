#include <stdio.h>
#include<stdlib.h>
#define N 10
#include <conio.h>

struct resultados {
	char *tema;
	float variable;
};

void encuesta (char* temas[], int respuestas[5][N],int j);//prototipos
void mas_votado (char* temas[], int respuestas[5][N]);
void menos_votado(char* temas[], int respuestas[5][N]);
int main(void) {
	char* temas[5]; //puntero apuntado a temas elegidos
	int respuestas[5][N];  //guarda respuestas de los usuarios
	float promedio=0;  //guarda promedio
	
	char tema1[]="La contaminacion ambiental";  //temas elegidos
	char tema2[]="La pobreza mundial";  //temas elegidos
	char tema3[]="La falta de Educacion";  //temas elegidos
	char tema4[]="El aumento de violencia";  //temas elegidos
	char tema5[]="La drogadiccion";  //temas elegidos
	
	temas[0]=tema1;temas[1]=tema2;temas[2]=tema3;temas[3]=tema4;temas[4]=tema5;  //asignacion de direcciones en puntero temas
	
	for(int j=0;j<N;j++){                                                         //inicio del programa
	printf("  |||Trabajo practico n°8|||                           Encuestado %d  de  %d.\n\n",j+1,N);//Lopez David Emanuel 80300
	
	printf("\n\n   ¡Bienvenido, te haremos una breve encuesta!\n ");   //inicio del programa, impresion de pautas
	printf("\n   La idea principal es saber cuales son los puntos mas relevantes para ti. ");	
		
	printf("\n\n   Los temas en cuestion son los siguientes:\n\n  1. %s\n  2. %s\n  3. %s\n  4. %s\n  5. %s",temas[0],temas[1],temas[2],temas[3],temas[4]);
		
	printf("\n\n\n     ¡Tu solo debes valuar del 1 al 10 lo que concideres mas importante! ");	
	
		getch();  //leve pausa
		system("cls");//limpia pantalla
		
		encuesta (temas,respuestas,j);  // llamado a funcion para iniciar encuesta
		
		if (j<N-1){   //fin de encuesta a un usuario, no del total de usuarios
			printf("   Tu encuesta ya a terminado.\n\n   Los resultados se veran al final del ultimo encuestado.\n\n   Muchas gracias por tu tiempo.\n\n   ¡Exitos!\n\n");
			getch();
			system ("cls");
			printf("\n\n  Para continuar con la encuesta precione enter");
			system("cls");
		}		
	}
	printf("  ¡La encuesta ya a terminado! \n\n"); // fin de encuesta al total de usuarios
	printf("  Preciona enter para ver los resultados. \n\n");
	getch();
	system("cls");
	
	printf("  |||Trabajo practico n°8|||\n\n");//Lopez David Emanuel 80300
	printf("\n\n"); 	                                            // resultados
	printf("        --------------------------------\n"); 	
	printf("       |  ¡ Resultados de la encuesta!  |\n"); 	
	printf("        --------------------------------\n\n\n"); 
	
	printf("----------Encuestado nº-------");
	for(int j=0;j<N;j++){ 	//bucle para crear barra superior e identificar respuestas				
		printf("-%d-",j+1); 			
	} 	
	printf("---Promedio-\n\n");//fin de barra superior
	
	for(int i=0;i<5;i++){ 	
		printf("   %26s:", temas[i]); // tema impreso a la izquierda de los resultados
		
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
	
	printf("\n\n   Preciona enter para mas informacion.");
	getch();
	system("cls");
	printf("  |||Trabajo practico n°8|||\n\n");//Lopez David Emanuel 80300
	
	float prom[5]={0,0,0,0,0};
	for(int i=0;i<5;i++){//obtencion de suma de cada tema
		for(int j=0;j<N;j++){
			prom[i]+=respuestas[i][j];
		}
	}
	if (prom[0]==prom[1]&&prom[1]==prom[2]&&prom[2]==prom[3]&&prom[3]==prom[4]){
		printf("\n\n  Todos los temas obtuvieron el mismo valor, ese valor fue %.3f\n",prom[0]);//si todos son iguales, no entra a las funciones minimos y maximos
	}
	else {	
	
	mas_votado (temas,respuestas);//llamado a funcion para obtener el mas votado
	menos_votado (temas,respuestas);//llamado a funcion para obtener el menos  votado
	
	}
	printf("\n\n   ¡Muchas gracias por participar!\n\n    Hasta la proxima.\n\n\n");//despedida, fin del programa
	
	return 0;
}

void encuesta (char* temas[], int respuestas[5][N],int j){ // funcion que recolecta el puntaje
	
	int rep=0;
	for(int i=0;i<5;i++){ //bucle de asignacion en matriz respuestas
		do{ 
			system("cls");//limpia pantalla
			rep=0;
			printf("  |||Trabajo practico n°8|||                           Encuestado %d  de  %d.\n\n",j+1,N);//Lopez David Emanuel 80300
			printf("\n\n Del 1 al 10, que importancia tiene %s:\n\n  ->   ",temas[i]);
			scanf("%d",&respuestas[i][j]);
			if(respuestas[i][j]<1||respuestas[i][j]>10){ // si el usuario ingresa puntaje invalido
				printf("\n  La respuesta no esta dentro del intervalo [1;10]");
				rep=1;
				getch();
			}
		}while(rep==1);//repeticion de misma consigna por error de usuario
		
	}
	printf("\n   ¡Perfecto! \n\n");//fin de la funcion
}
void mas_votado (char* temas[], int respuestas[5][N]){     //funcion para obtener maximos
	struct resultados maximo;
	float prom[5];
	
	for(int i=0;i<5;i++){//inicializacion
		prom[i]=0;
	}
	
	for(int i=0;i<5;i++){//obtencion de suma de cada tema
		for(int j=0;j<N;j++){
			prom[i]+=respuestas[i][j];
		}
	}
	
	maximo.variable=prom[0]; // variable tipo resultado, maximo igualado a primer tema
	maximo.tema=temas[0];    // char tipo resultado, tema igualado a tema1
	
	for(int i=1;i<5;i++){
		if(prom[i]>maximo.variable){//si variable es menos a promedio[i] se asigna valor de prom en variable
			maximo.variable=prom[i];
			maximo.tema=temas[i];
		}
	}
	printf("\n\n  El puntaje mas alto fue de %.3f y lo obtuvo %s",maximo.variable,maximo.tema);//impresion del maximo
	
	for(int i=0;i<5;i++){//si maximo es igual a otros temas se agregan
		if(prom[i]==maximo.variable&&maximo.tema!=temas[i]){
			printf(", %s",temas[i]);
		}
		
	}
	printf(".\n\n");
}
void menos_votado(char* temas[], int respuestas[5][N]){    //funcion para obtener minimos
	struct resultados minimo;
	float prom[5];
	
	for(int i=0;i<5;i++){//inicializacion
		prom[i]=0;
	}
	
	for(int i=0;i<5;i++){//obtencion de suma de cada tema
		for(int j=0;j<N;j++){
			prom[i]+=respuestas[i][j];
		}
	}
	
	minimo.variable=prom[0]; // variable tipo resultado, minimo igualado a primer tema
	minimo.tema=temas[0];    // char tipo resultado, tema igualado a tema1
	
	for(int i=1;i<5;i++){// busca del minimo
		if(prom[i]<minimo.variable){
			minimo.variable=prom[i];
			minimo.tema=temas[i];
		}
	}
	printf("\n\n  El puntaje mas bajo fue de %.3f y lo obtuvo %s",minimo.variable,minimo.tema);//impresion de resultado
	
	for(int i=0;i<5;i++){// suma condiciones
		if(prom[i]==minimo.variable&&minimo.tema!=temas[i]){
			printf(", %s",temas[i]);
		}
		
	}
	printf(".\n\n");
}

