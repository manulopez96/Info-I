#include <stdio.h>
#include "EasyPIO.h"
#include <time.h>
#include <stdlib.h>
#define N 8      //cantidad de opciones en el menu
#define M 25     //secuencia de apagado

/*
	- Trabajo practico Nº 11 -
*/

//Prototipos de funciones//
void Inicializar_Pines();
void Menu_Opciones();
void seleccionadordemenu(int,int*);
void mymenu(int*,int*,int*);
void deMam(int*);
void demaM(int*);
void todo_on(int*);
void todo_off(int*);
void aleatorio(int*);
void idayvuelta(int *Pleds);
void vueltaeida(int *Pleds);
void  cerrando(int *Pleds);
	
int main(void) {
	
	pioInit();
	
	srand(time(NULL));//semilla para numeros aleatorios.
	int menu=1,leds[8]={18,23,24,25,8,7,12,16};//variable de seleccion de menu , Matriz de los pines de leds y su puntero.
	Inicializar_Pines(); //inicia pines de entradas y salidas digitales.
	int j=0;//variable para salir del programa
    todo_off(leds);//apaga todos los leds
    Menu_Opciones();//abre el menu principal
    seleccionadordemenu(menu,leds);// imprime el menu en que vas a selecionar y muestra seleccion en el numero de led.
    
    
    
	do{	//bucle del menu principal
			
		mymenu(&menu,leds,&j);	//menu principal
    		 
    }while(j==0);	//condicion para cerrar programa ( opcion del menu )
    
	todo_off(leds);// apaga todos los leds
		
	system("clear");//limpia pantalla
	
	printf("\n\n---->  Cerrando TP11..\n\n");//imprime situacion de cerrado
	
	cerrando(leds);
		
	todo_off(leds);

	return 0;
}
void Inicializar_Pines(){
	
	//declacion de entradas digitales - Botones
	pinMode(10,INPUT);	//Boton izquierdo 
    pinMode(9,INPUT);   // Boton derecho
	
	//declaracion de salidas digitalles - Leds 
	pinMode(18,OUTPUT);
	pinMode(23,OUTPUT);
	pinMode(24,OUTPUT);
	pinMode(25,OUTPUT);
	pinMode(8,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(16,OUTPUT);
}
void Menu_Opciones(){
	system("clear"); //limpia pantalla
	
	//imprime opciones del menu
	printf("\n\n -Cambie el menu con el boton izquierdo.\n -Seleccione opcion con el boton derecho\n\n");
	printf("   1------------Prender todos los leds\n");
	printf("   2------------Apagar todos los leds\n");
	printf("   3------------Prender leds de mayor a menor\n");
	printf("   4------------Prender leds de menor a mayor\n");
	printf("   5------------Prender y apagar leds de manera aleatoria\n");
	printf("   6------------Auto fantastico 1\n");
	printf("   7------------Auto fantastico 2\n");
	printf("   8------------Salir del programa\n");
}
void seleccionadordemenu(int menu,int*Pleds){//muestra en que menu estamos.
	
	todo_off(Pleds);//apaga todos los leds.
	digitalWrite((*(Pleds+menu-1)),1);//prende led correspondiente a la opcion de menu en la que estamos.
	printf("\n   -->     Tiene seleccionada la opcion %d\n",menu);//imprime menu seleccionado
	
}
void mymenu(int *menu,int *leds,int *pj){
	
	if(digitalRead(10)==1){    
	    (*menu)+=1;
	    if(*menu>N){*menu=1;}
	    delayMillis(1000);
	    Menu_Opciones();
	    seleccionadordemenu(*menu,leds);
	    }
	
	    if(digitalRead(9)==1){	//entrar al menu elegido por el otro boton.
		
		    switch(*menu){//switch de seleccion de menu
				
			    case 1: todo_on(leds); 
						Menu_Opciones();
						seleccionadordemenu(*menu, leds);
						break;//menu 0 -> prende todos los leds 
						
			    case 2: do{
					
							todo_off(leds); 
							
						}while(digitalRead(10)==0);
						
						delayMillis(1000);
						Menu_Opciones();
						seleccionadordemenu(*menu, leds);
						break;//menu 1 -> apaga todos los leds
						
		    	case 3: todo_off(leds);
						deMam(leds);
						Menu_Opciones();
						seleccionadordemenu(*menu, leds);
						break;//llamado a funcion de mayor a menor
		    	
		    	case 4: todo_off(leds);
						demaM(leds);
						Menu_Opciones();
						seleccionadordemenu(*menu, leds);
						break;//llamado a funcion de menor a mayor
		    	
		    	case 5: aleatorio(leds);
						Menu_Opciones();
						seleccionadordemenu(*menu, leds);
						break;//genera la iluminacion aleatoria de un led
		    	
		    	case 6: todo_off(leds);
						idayvuelta(leds);
						Menu_Opciones();
						seleccionadordemenu(*menu, leds);
						break;
		    	
		    	case 7: todo_off(leds);
						vueltaeida(leds);
						Menu_Opciones();seleccionadordemenu(*menu, leds);;break;
		        
		        default:*pj=1;
						break;//salir
		    }
	    }
}
void deMam(int *Pleds){	
	delayMillis(500);
	do{
	for(int i=7;i>=0;i--){
		
			digitalWrite(*(Pleds+i),1);
			delayMillis(80);
			digitalWrite(*(Pleds+i),0);
			if(digitalRead(10)==1){
				i=0;
				}
		
	}	
	}while(digitalRead(10)==0);	
	delayMillis(1000);

}
void demaM(int *Pleds){	
	delayMillis(500);
	do{
	for(int i=0;i<=7;i++){
		
			digitalWrite(*(Pleds+i),1);
			delayMillis(80);
			digitalWrite(*(Pleds+i),0);
			if(digitalRead(10)==1){
				i=7;
				}
	}	
		
		}while(digitalRead(10)==0);
		delayMillis(1000);
						
}
void todo_on(int *Pleds){	
	int i;
	
	do{
	for(i=0;i<8;i++){
			digitalWrite(*(Pleds+i),1);
	}	
		
		}while(digitalRead(10)==0);
		delayMillis(1000);
		
	
}
void todo_off(int *Pleds){	
	int i;
        for(i=0;i<8;i++){
		digitalWrite(*(Pleds+i),0);
	}		
}
void aleatorio(int *Pleds){	
	int i;
	
    do{
		for(i=0;i<8;i++){
		digitalWrite(*(Pleds+i),rand()%2);
	    }
	    delayMillis(100);
		
		if(digitalRead(9)==1){
		
		delayMillis(3000);
		
		}
		
	}while(digitalRead(10)==0);
	    delayMillis(1000);
	   
}
void idayvuelta(int *Pleds){	
	
	do{
	for(int i=1;i<=7;i++){//de menor a mayor
		
			digitalWrite(*(Pleds+i),1);
			delayMillis(60);
			digitalWrite(*(Pleds+i),0);
			if(digitalRead(10)==1){
				i=7;
				}
	}	
	for(int i=6;i>=0;i--){
		
			digitalWrite(*(Pleds+i),1);
			delayMillis(60);
			digitalWrite(*(Pleds+i),0);
			if(digitalRead(10)==1){
				i=0;
				}
		
		}			
		}while(digitalRead(10)==0);
		delayMillis(1000);
						
}
void vueltaeida(int *Pleds){	
	
	do{
	for(int i=1;i<=7;i++){
		
			digitalWrite(*(Pleds+i),0);
			delayMillis(60);
			digitalWrite(*(Pleds+i),1);
			if(digitalRead(10)==1){
				i=7;
				}
	}	
	for(int i=6;i>=0;i--){
		
			digitalWrite(*(Pleds+i),0);
			delayMillis(60);
			digitalWrite(*(Pleds+i),1);
			if(digitalRead(10)==1){
				i=0;
				}
		
		}			
		}while(digitalRead(10)==0);
		delayMillis(1000);
							
}
void cerrando(int *Pleds){
	
	int cont=0;
	
	do{

	int j=0;

	for(int i=7;i>=0;i--){
		
	
		
			digitalWrite(*(Pleds+i),1);
		
			digitalWrite(*(Pleds+j),1);
	
			delayMillis(50-((50/M)*cont));
			digitalWrite(*(Pleds+i),0);
			digitalWrite(*(Pleds+j),0);
		j++;
		
	}
	cont++;
}while(cont<M);
	}
