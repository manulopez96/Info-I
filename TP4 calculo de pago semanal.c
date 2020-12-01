#include <stdio.h>
#include <stdlib.h>
int main(void) {
	
	int puesto=0;//seleccion de empleado
	char rep='y';//bucle, reinicio
	int tiempo=0;//tiempo trabajado
	float valor=0;//valor del trabajo
	float sueldo;//monto a pagar
	system ("color F");
	printf("\n       --------------------------");
	printf("\n      | CALCULO DE PAGO SEMANAL  |");
	printf("\n       --------------------------\n\n");
	
	while(rep=='y'){
		
		rep='n';//salida del bucle
		tiempo=0;//reset semanas
		valor=0;//reset valor
		
		printf("\n    Ingrese el codigo de empleado ");
		printf("\n    ----------------------------- \n");
		printf("\n    1-Gerente");
		printf("\n    2-Trabajador por hora");
		printf("\n    3-Trabajadores de comision");
		printf("\n    4-Trabajadores a destajo\n\n");
		printf("    Puesto:");
		scanf("%d",&puesto);//seleciona puesto detrabajo
		
		switch(puesto){
			
		case 1 :
			printf("\n           ---------"); 
			printf("\n            GERENTE"); //Puesto 1
			printf("\n           ---------\n\n"); 
			printf("  Ingrese la cantidad de semanas trabajadas:");
			scanf("%d",&tiempo);
			printf("\n  Ingrese el valor semanal del trabajo:");
			scanf("%f",&valor);
			sueldo=tiempo*valor;
			printf("\n El monto a pagar es de $%.2f ", sueldo);
			printf("\n\n El monto a pagar es de $%.2f por cada semana trabajada ", valor);
			break;
		case 2 :
			printf("\n           ---------------------");
			printf("\n            TRABAJADOR POR HORA"); //Puesto 2
			printf("\n           ---------------------\n\n");
			printf("  Ingrese cantidad de horas trabajadas en la semana:");
			scanf("%d", &tiempo);
			printf("\n  Ingrese el valor del trabajo, por hora:");
			scanf("%f", &valor);
			if (tiempo>=0&&tiempo<72){
				if (tiempo>40){//si trabajo mas de 40 horas
					sueldo=((valor*40.0)+((valor*1.5)*(tiempo-40)));
					printf("\nEl monto a pagar es de $%.2f ", sueldo);
				}else{//si trabajo menos de 40 horas
					sueldo=tiempo*valor;
					printf("\nEl monto a pagar es de $%.2f ", sueldo);
				}
			}else 
				printf ("\n\n   Las horas que ingreso supera la cantidad de horas legales de trabajo semanal");
			//En realidad lo maximo es 48hs pero le puse mas horas para tener mas variacion
			
			
			break;
		case 3 :
			printf("\n           -------------------------");
			printf("\n            TRABAJADOR POR COMISION");  //Puesto 3
			printf("\n           -------------------------\n\n");
			printf("  Ingrese la cantidad de ventas realizadas:");
			scanf("%d", &tiempo);
			printf("\n  Ingrese el valor de sus ventas brutas:");
			scanf("%f",&valor);
			sueldo=((tiempo)*(valor*0.057)+250);//operaciones 
			printf("\nEl monto a pagar es de $%.2f ", sueldo);
			break;
		case 4 :
			printf("\n           ----------------------");
			printf("\n            TRABAJADOR A DESTAJO"); //Puesto 4
			printf("\n           ----------------------\n\n");
			printf("  Ingrese la cantidad de articulos fabricados:");
			scanf("%d",&tiempo);
			printf("\n  Ingrese el valor de cada articulo:");
			scanf("%f", &valor);
			sueldo=(tiempo*valor);//operaciones
			printf("\nEl monto a pagar es de $%.2f ", sueldo);
			break;
		default:
			printf("\n            **************************************"); 
			printf("\n            *                                    *");
			printf("\n            *  El puesto ingresado no es valido  *");
			printf("\n            *                                    *");
			printf("\n            **************************************\n"); 
			break;
		}
		printf("\n\n    Si desea relizar un nuevo calculo ingrese 'y':");
		scanf("%s", &rep);
		system("cls");
	}
	return 0;
}

