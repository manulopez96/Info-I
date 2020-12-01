#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#define N 25
#define M 15

enum {Masculino=1,Femenino=2};

typedef struct{
	char nombre[M];
	char nombre2[M];
	char apellido [M];
	int dni;
	int sex;
	int d_n;
	int m_n;
	int a_n;
	float altura_m;
	float peso_kg;	
	char gr_sang[2];
}healthprofile;

void funcion_frec (healthprofile *paciente,int j){
	
}
void funcion_IMC (healthprofile *paciente,int j){
	float imc;
	
	imc=paciente[j].peso_kg/(paciente[j].altura_m * paciente[j].altura_m);
	printf("%.2f",imc);
}
void funcion_edad (healthprofile *paciente,int j){
	long int edad=0;
	edad=(paciente[j].d_n*86400)+(paciente[j].m_n*2592000)+(paciente[j].a_n*31104000);
	edad=time(NULL)-edad;
}
void funcion_agregar (healthprofile *paciente,int j){
	system ("cls");
	printf("  ||| Trabajo practico n°9 |||\n\n\n");//Lopez David Emanuel 80300
	
	printf("\n\n  Ingrese el primer nombre del paciente:");
	scanf(" %s",&paciente[j].nombre);
	
	printf("\n\n  Ingrese el segundo nombre del paciente:");
	scanf(" %s",&paciente[j].nombre2);
	
	printf("\n\n  Ingrese el apellido del paciente:");
	scanf(" %s",&paciente[j].apellido);
	
	printf("\n\n  Ingrese el DNI del paciente:");
	scanf("%u",&paciente[j].dni);
	
	do{
		printf("\n\n  Ingrese el sexo del paciente.\n\n  1-->  Masculino\n  2-->  femenino\n\n  >>");
		scanf("%d",&paciente[j].sex);
		if(paciente[j].sex!=1&&paciente[j].sex!=2){printf("\n\n  Respuesta no valida");}
	}while(paciente[j].sex!=1&&paciente[j].sex!=2);
	
	do{
		printf("\n\n  Ingrese fecha de nacimineto en formato DD MM AAAA:");
		scanf("%d %d %d",&paciente[j].d_n,&paciente[j].m_n,&paciente[j].a_n);
		if(paciente[j].d_n>31){
			printf("\n\n El numero de dias no debe superar los 31 dias, deberas reingresarlos.");
		}else if (paciente[j].m_n>12){
			printf("\n\n El numero de meses no debe superar los 12 meses, deberas reingresarlos.");
		}else if (paciente[j].a_n<1900){
			printf("\n\n El año no puede ser menor a 1900, deberas reingresarlos.");
		}
	}while(paciente[j].d_n>31||paciente[j].m_n>12||paciente[j].a_n<1900);
	
	printf("\n\n  Ingrese  la altura del paciente en metros:");
	scanf("%f",&paciente[j].altura_m);
	
	printf("\n\n  Ingrese  el peso del paciente en kg:");
	scanf("%f",&paciente[j].peso_kg);
	
	printf("\n\n  Ingrese grupo sanguineo del paciente:");
	scanf(" %s",&paciente[j].gr_sang);
		
	
	
	
		printf("\n\n  Paciente: %s",paciente[j].nombre);//test de grabado
		printf(" %s",paciente[j].nombre2);
		printf(" %s",paciente[j].apellido);
		printf("\n  Dni: %d",paciente[j].dni);
		if(paciente[j].sex==1)
		printf("\n  Sexo: Masculino");
		else 
			printf("\n  Sexo:Femenino");
		printf("\n  Fecha de nacimiento: %d/%d/%d  ",paciente[j].d_n,paciente[j].m_n,paciente[j].a_n);
		printf("\n  Altura: %.2f",paciente[j].altura_m);
		printf("\n  Peso: %.2f",paciente[j].peso_kg);
		printf("\n  Grupo sanguineo: %2s",paciente[j].gr_sang);
		printf("\nIndice de masa corporal: ");
		funcion_IMC (paciente,j);
	
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
			
			printf("\n\n  Paciente: %s",paciente[j].nombre);//test de grabado
			printf(" %s",paciente[j].nombre2);
			printf(" %s",paciente[j].apellido);
			printf("\n  Dni: %d",paciente[j].dni);
			if(paciente[j].sex==1)
				printf("\n  Sexo: Masculino");
			else 
				printf("\n  Sexo:Femenino");
			printf("\n  Fecha de nacimiento: %d/%d/%d  ",paciente[j].d_n,paciente[j].m_n,paciente[j].a_n);
			printf("\n  Altura: %.2f",paciente[j].altura_m);
			printf("\n  Peso: %.2f",paciente[j].peso_kg);
			printf("\n  Grupo sanguineo: %2s",paciente[j].gr_sang);
			printf("\nIndice de masa corporal: ");
			funcion_IMC (paciente,j);
		}
		
		if(j==N-1){
			printf("\n\n  Busqueda finalizada.");
		}
		
	}
	getch();
	system ("cls");
	
}
int main(void) {
	int menu=0,error;
	healthprofile paciente[N];
	char rep[2];
	for(int j=0;j<N;j++){
		
		do{
			printf("  ||| Trabajo practico n°9 |||\n\n\n");//Lopez David Emanuel 80300
			
			printf("                    -----------------------\n");
			printf("                   |                       |\n");
			printf("                   |   REGISTRO DE SALUD   |\n");
			printf("                   |                       |\n");
			printf("                    -----------------------\n");
			
			char rep[2]="no";
			error=0;
			printf ("\n\n  Ingrese la opcion que desee realizar");
		
			printf ("\n\n 1.  Agregar un nuevo usuario");
			
			printf ("\n\n 2.  Buscar un usuario exitente\n\n");
		
			printf(" >>  ");
					scanf(" %d",&menu);
			
			switch (menu){
				case 1: funcion_agregar(paciente,j);break;
				case 2: funcion_buscar(paciente);break;
				default:printf("\n\n opcion invalida, es necesario reintentarlo");
					error=1;
					getch();
			}
			printf("  ||| Trabajo practico n°9 |||\n\n\n");//Lopez David Emanuel 80300
			if (error!=1){
				printf("\n\n  Si desea realizar otra operacion, ingrese 'si', caso contrario ingrese cualquier tecla:");
				scanf(" %s",&rep);
				if(rep[0]=='s'&&rep[1]=='i'){ 
					error=1;
				}else {j=N;}
			}
			
			system ("cls");	
		}while(error==1);
			
	}
	
	printf("\n\n  ¡Hasta la proxima!");
	
	
	return 0;
}

