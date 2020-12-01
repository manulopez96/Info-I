#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include<unistd.h>
#define N 20


typedef struct {
	unsigned int record;
	char herramienta[N];
	int cantidad;
	double costo;
}ferreteria;

void funcion_inicio_cheto(void);//cosas inutiles 
void funcion_cierre_cheto(void);//cosas inutiles 
void imprime_lista (FILE *parchivo,ferreteria herramientas);
int main(void) {
	funcion_inicio_cheto();
	ferreteria herramientas={0,"",0,0.0};
	int menu,rep;
	FILE *parchivo;
	rep=1;
	do{
		system("color 0f");
	if((parchivo=fopen("hardware.dat","ab"))==NULL){//abro archivo y busco error
		printf("  El archivo hardware.dat no pudo abrirse");//encontro error al abrir el archivo
		sleep(2);
	}else{
		system("cls");
		menu=0;
		for(int i=0;i<100;i++){
			fwrite(&herramientas,sizeof(ferreteria),1,parchivo);//creo fichero en blanco si no existe
		}fclose(parchivo);//cierro archivo
		printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
		printf("  Seleccione la opcion que desea realizar:\n\n");//imprimo las opciones del menu
		printf("  1. Agregar productos.\n\n");
		printf("  2. Quitar productos.\n\n");
		printf("  3. Ver lista de productos.\n\n");
		printf("  4. Salir.\n\n");
		printf("  -> ");
		
		scanf("%d",&menu);
		printf("\n\n");
		
		switch(menu){//seleccion de menu
			case 1: //menu 1 -> agregar producto
					system("cls");
					system("color 2f");
					printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
					
					imprime_lista (parchivo,herramientas);//imprime lista
					
						printf("\n\n\n   Agregar producto\n ");
						printf(" ------------------\n\n ");
					
						do{
						printf("  Introduce el numero de identificacion del producto,\n   entre 1 y 100 o '0' para salir: ");
						scanf("%u",&herramientas.record);
						}while(herramientas.record<0||herramientas.record>100);
						while(herramientas.record!=0){
							printf("\n   Introduce el nombre del producto: ");
							scanf("%s",herramientas.herramienta);
							printf("\n   Introduce la cantidad del producto: ");
							scanf("%d",&herramientas.cantidad);
							printf("\n   Introduce el precio del producto: ");
							scanf("%lf",&herramientas.costo);						
						
							if((parchivo=fopen("hardware.dat","rb+"))==NULL){//abro archivo y busco error
								printf("  El archivo hardware.dat no pudo abrirse");//encontro error al abrir el archivo
							}else{
								
								fseek(parchivo,(herramientas.record-1)*sizeof(ferreteria),SEEK_SET);//pociciona puntero en ubicacion asignada del fichero
								fwrite(&herramientas,sizeof(ferreteria),1,parchivo);
						}fclose(parchivo);
							
							system("cls");
							printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
							
							imprime_lista (parchivo,herramientas);//imprime lista
							
							printf("\n\n\n   Agregar producto\n ");
							printf(" ------------------\n\n ");
							
							printf("\n   Introduce el numero de identificacion del producto: ");
							scanf("%u",&herramientas.record);
							fclose(parchivo);
						}
					
					break;
			case 2: //menu 2 -> quitar producto
					system("cls");
					system("color 4f");
					printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
					imprime_lista (parchivo,herramientas);//imprime lista
					
					printf("\n\n\n   quitar producto\n ");
					printf(" -----------------\n\n ");
					
					do{
						printf("  Introduce el ID del producto que desea eliminar, 0 para salir: ");
						scanf("%u",&herramientas.record);
					}while(herramientas.record<0);
					while(herramientas.record!=0){
							
						if((parchivo=fopen("hardware.dat","rb+"))==NULL){//abro archivo y busco error
							printf("  El archivo hardware.dat no pudo abrirse");//encontro error al abrir el archivo
						}else{
							
							fseek(parchivo,(herramientas.record-1)*sizeof(ferreteria),SEEK_SET);//pociciona puntero en ubicacion asignada del fichero
							herramientas.record=0;
							fwrite(&herramientas,sizeof(ferreteria),1,parchivo);
						}fclose(parchivo);
						
						system("cls");
						printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
						
						imprime_lista (parchivo,herramientas);//imprime lista
						
						printf("\n\n\n   quitar producto\n ");
						printf(" -----------------\n\n ");
						
						printf("  Introduce el ID del producto que desea eliminar, 0 para salir: ");
						scanf("%u",&herramientas.record);
						fclose(parchivo);
					}
					break;
			case 3: //menu 3-> ver productos
					system("cls");
					printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
					imprime_lista (parchivo,herramientas);//imprime lista
					printf("\n\n");
					system("pause");
					break;
			case 4: //menu 4-> salir, fin del programa
					funcion_cierre_cheto();
					rep=0;
					break;
		default: printf("   La opcion ingresada es incorrecta\n\n");
				sleep(2);
				system("pause");
		}
	}
	
	}while(rep==1);
	
	return 0;
}

void imprime_lista (FILE *parchivo,ferreteria herramientas){
	if((parchivo=fopen("hardware.dat","rb"))==NULL){//abro archivo y busco error
		printf("  El archivo hardware.dat no pudo abrirse");//encontro error al abrir el archivo
	}else{
		
		printf("    %-6s%-25s%-10s%-15s\n","ID","Producto","Cantidad","Costo");
		printf("   ------------------------------------------------\n");
		while(!feof(parchivo)){
			fread(&herramientas,sizeof(ferreteria),1,parchivo);
			if((herramientas.record!=0)&&(herramientas.herramienta!=NULL)){
				printf("    %-6u%-25s%-10d%-15.2lf\n",herramientas.record,herramientas.herramienta,herramientas.cantidad,herramientas.costo);
			}                                                                  
		}
	}fclose(parchivo);
}
void funcion_inicio_cheto(void){
	system("cls");
	printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
	
	printf("     Iniciando");
	
	for(int i =0;i<9;i++){
		Sleep(200);
		printf(".");
		if(i%3==0){Sleep(100);
		system("cls");
		printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
		
		printf("     Iniciando");
		}
	}
	Sleep(300);
}

void funcion_cierre_cheto(void){
	system("cls");
	printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
	
	printf("     Cerrando");
	
	for(int i =0;i<9;i++){
		Sleep(200);
		printf(".");
		if(i%3==0){Sleep(100);
		system("cls");
		printf("  ||| Trabajo practico n°10 |||\n\n\n");//Lopez David Emanuel 80300
		
		printf("     Cerrando");
		}
	}
	Sleep(300);
}
