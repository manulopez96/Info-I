#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#define N 25
#define M 15


struct tm edad;//Estructura para funcion edad
typedef struct{//estructura que almacena los datos ingresados
	char nombre[M];
	char nombre2[M];
	char apellido [M];
	unsigned int dni;
	int sex;
	int d_n;
	int m_n;
	int a_n;
	float altura_m;
	float peso_kg;	
	char gr_sang[2];
	int edad;
}healthprofile;



void funcion_frec (healthprofile *paciente,int j);//prototipo de funcion
void funcion_IMC (healthprofile *paciente,int j);//prototipo de funcion
void funcion_edad (healthprofile *paciente,int j);//prototipo de funcion
void funcion_agregar (healthprofile *paciente,int j);//prototipo de funcion
void funcion_buscar (healthprofile *paciente);//prototipo de funcion

int main(void) {
	int menu=0,error;//variable de repeticion
	healthprofile paciente[N];//estructura con los datos de los pacientes
	for(int j=0;j<N;j++){//bucle de operacion
		
		do{
			printf("  ||| Trabajo practico n°9 |||\n\n\n");//Lopez David Emanuel 80300
			char rep[2]="no";//cadena de caracteres para solicitar repeticion al finalizar
			printf("                    -----------------------\n");
			printf("                   |                       |\n");
			printf("                   |   REGISTRO DE SALUD   |\n");         //titulo
			printf("                   |                       |\n");
			printf("                    -----------------------\n");
			
			error=0;//bucle desactivado
			
			printf ("\n\n  Ingrese la opcion que desee realizar");
		
			printf ("\n\n 1.  Agregar un nuevo usuario");
			
			printf ("\n\n 2.  Buscar un usuario exitente\n\n");
		
			printf(" >>  ");
					scanf(" %d",&menu);//eleccion de opcion en menu
			
			switch (menu){//selectora de menu
				case 1: funcion_agregar(paciente,j);break;//agrega usuario
				case 2: funcion_buscar(paciente);break;//busca y muestra informacion de usuarios
				default:printf("\n\n opcion invalida, es necesario reintentarlo");//opcion invalida
					error=1;//bucle activado
					getch();//pausa para que lean la ultima impresion
			}
			printf("  ||| Trabajo practico n°9 |||\n\n\n");//Lopez David Emanuel 80300
			if (error!=1){//si bucle permanece desactivado
				printf("\n\n  Si desea realizar otra operacion, ingrese 'si', caso contrario ingrese cualquier tecla:");
				scanf(" %s",rep);//pregunta si desea repetir operacion
				if(rep[0]=='s'&&rep[1]=='i'){ //compara respuesta
					error=1;//bucle activado si usuario ingreso 'si'
					j++;
				}else {j=N;}//si no fue asi, fin del for y del bucle while
			}
			
			system ("cls");	//limpia pantalla
		}while(error==1);//verifica activacion del bucle para reintentar o no
			
	}
	
	printf("\n\n  ¡Hasta la proxima!");//fin del programa
	
	
	return 0;
}


void funcion_frec (healthprofile *paciente,int j){//funcion que obtiene la frec. cardiaca maxima y la frec. cardiaca optima
	if (paciente[j].edad>12){//verifica edad para saber frec cardiaca normal
		printf("\n   Fecuencia cardiaca normal entre 80 y 100 compresiones por minuto");
	}else if (paciente[j].edad<12){//verifica edad para saber frec cardiaca normal
		printf("\n   Fecuencia cardiaca normal entre 100 y 120 compresiones por minuto");
	}
	printf("\n   Fecuencia cardiaca maxima: %d compresiones por minuto",220-paciente[j].edad);//Realiza un pequeño calculo para determinar frecuencia cardiaca maxima
}
void funcion_IMC (healthprofile *paciente,int j){//funcion para obtener IMC
	float imc;
	//es igual a tp2
	imc=paciente[j].peso_kg/(paciente[j].altura_m * paciente[j].altura_m);
	printf("%.2f",imc);
	
	if (imc<=18.5){
		printf("  Infrapeso, peso por debajo de los parametros");
	}else if(imc>18.5&&imc<25){
		printf("  Peso normal, dentro de los parametros");
	}else if(imc>=25&&imc<=29.9){
		printf("  Sobrepeso, peso por encima de los parametros");
	}else if(imc>29.9){
		printf("  Obesidad, peso demaciado por ensima de los parametros");
	}
}
void funcion_edad (healthprofile *paciente,int j){//funcion para calcular la edad
	time_t tiempoActual;// crear variable de tipo time_t
	time(&tiempoActual);
	struct tm *fecha_actual=localtime(&tiempoActual);//almaceno fecha actual en la estructura en cuestion
	
	edad.tm_mday=fecha_actual->tm_mday-paciente[j].d_n;//utilizo estructura para calcular las fechas
	edad.tm_mon=((fecha_actual->tm_mon+=1)-paciente[j].m_n);//utilizo estructura para calcular las fechas
	edad.tm_year=((fecha_actual->tm_year+=1900)-paciente[j].a_n);//utilizo estructura para calcular las fechas, sumo 1900 ya que cuentan desde 1900 en adelante
	
	if((paciente[j].m_n>fecha_actual->tm_mon)||(paciente[j].m_n=fecha_actual->tm_mon&&fecha_actual->tm_mday<paciente[j].d_n)){//verifico que no haya errores en la edad
		edad.tm_year-=1;//si en el año todavia no cumplio años se le resta 1 año a la diferencia
	}
	if (edad.tm_year<0){//si la fecha no coincide
		printf("\n   Edad : ¡Invalida! ¡¡Fecha de nacimiento adelantada o fecha del ordenador incorrecta!! ");
	}else	
		printf("\n   Edad : %d años",edad.tm_year);//imprime edad en el histograma
	paciente[j].edad=edad.tm_year;//guarda edad en la estructura del usuario
}
void funcion_agregar (healthprofile *paciente,int j){//agrega un nuevo usuario
	system ("cls");//limpia pantalla
	printf("  ||| Trabajo practico n°9 |||\n\n\n");//Lopez David Emanuel 80300
	
	printf("\n\n  Ingrese el primer nombre del paciente:");//datos
	scanf(" %[^\n]s",paciente[j].nombre);
	
	printf("\n\n  Ingrese el segundo nombre del paciente:");//datos
	scanf(" %s",paciente[j].nombre2);
	
	printf("\n\n  Ingrese el apellido del paciente:");//datos
	scanf(" %s",paciente[j].apellido);
	
	printf("\n\n  Ingrese el DNI del paciente:");//datos
	scanf("%u",&paciente[j].dni);
	
	do{
		printf("\n\n  Ingrese el sexo del paciente.\n\n  1-->  Masculino\n  2-->  femenino\n\n  >>");//datos
		scanf("%d",&paciente[j].sex);
		if(paciente[j].sex!=1&&paciente[j].sex!=2){printf("\n\n  Respuesta no valida");}//informa error
	}while(paciente[j].sex!=1&&paciente[j].sex!=2);//reinicia solo ese parametro en caso de error
	
	do{
		printf("\n\n  Ingrese fecha de nacimineto en formato DD MM AAAA:");//datos
		scanf("%d %d %d",&paciente[j].d_n,&paciente[j].m_n,&paciente[j].a_n);
		if(paciente[j].d_n>31){//verifica
			printf("\n\n El numero de dias no debe superar los 31 dias, deberas reingresarlos.");
		}else if (paciente[j].m_n>12){//verifica
			printf("\n\n El numero de meses no debe superar los 12 meses, deberas reingresarlos.");
		}else if (paciente[j].a_n<1900){//verifica
			printf("\n\n El año no puede ser menor a 1900, deberas reingresarlos.");
		}
	}while(paciente[j].d_n>31||paciente[j].m_n>12||paciente[j].a_n<1900);//si hay error, reinicia solo ese parametro
	
	printf("\n\n  Ingrese  la altura del paciente en metros:");//datos
	scanf("%f",&paciente[j].altura_m);
	
	printf("\n\n  Ingrese  el peso del paciente en kg:");//datos
	scanf("%f",&paciente[j].peso_kg);
	
	printf("\n\n  Ingrese grupo sanguineo del paciente:");//datos
	scanf(" %s",paciente[j].gr_sang);
	
	system("cls");
	printf("  ||| Trabajo practico n°9 |||\n\n\n");//Lopez David Emanuel 80300
	
	printf("\n   Paciente: %s",paciente[j].nombre);//imprime todos los datos ingresados
	printf(" %s",paciente[j].nombre2);
	printf(" %s",paciente[j].apellido);
	printf("\n   Dni: %d",paciente[j].dni);
	if(paciente[j].sex==1)
		printf("\n   Sexo: Masculino");
	else 
		printf("\n   Sexo:Femenino");
	printf("\n   Fecha de nacimiento: %d/%d/%d  ",paciente[j].d_n,paciente[j].m_n,paciente[j].a_n);
	funcion_edad (paciente,j);
	printf("\n   Altura: %.2f",paciente[j].altura_m);
	printf("\n   Peso: %.2f",paciente[j].peso_kg);
	printf("\n   Grupo sanguineo: %2s",paciente[j].gr_sang);
	printf("\n   Indice de masa corporal: ");
	funcion_IMC (paciente,j);//llamado a funcion imc
	funcion_frec (paciente,j);
	
	getch();
	system ("cls");
}
void funcion_buscar (healthprofile *paciente){
	int DNI=0;
	system ("cls");
	printf("  ||| Trabajo practico n°9 |||\n\n\n");//Lopez David Emanuel 80300
	
	printf("\n\n  Ingrese el DNI del paciente que busca:");
	scanf("%d",&DNI);
	
	for(int j=0;j<N;j++){
		if(DNI==paciente[j].dni){
			
			system("cls");
			printf("  ||| Trabajo practico n°9 |||\n\n\n");//Lopez David Emanuel 80300
			
			printf("\n   Paciente: %s",paciente[j].nombre);//imprime todos los datos ingresados
			printf(" %s",paciente[j].nombre);
			printf(" %s",paciente[j].nombre2);
			printf(" %s",paciente[j].apellido);
			printf("\n   Dni: %d",paciente[j].dni);
			if(paciente[j].sex==1)
				printf("\n   Sexo: Masculino");
			else 
				printf("\n   Sexo:Femenino");
			printf("\n   Fecha de nacimiento: %d/%d/%d  ",paciente[j].d_n,paciente[j].m_n,paciente[j].a_n);
			funcion_edad (paciente,j);
			printf("\n   Altura: %.2f",paciente[j].altura_m);
			printf("\n   Peso: %.2f",paciente[j].peso_kg);
			printf("\n   Grupo sanguineo: %2s",paciente[j].gr_sang);
			printf("\n   Indice de masa corporal: ");
			funcion_IMC (paciente,j);
			funcion_frec (paciente,j);
			
		}
		
		if(j==N-1){
			printf("\n\n  Busqueda finalizada.");
		}
		
	}
	getch();
	system ("cls");
	
}
