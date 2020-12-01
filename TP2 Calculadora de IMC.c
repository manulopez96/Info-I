#include <stdio.h>

int main(void)
{
	float peso,altura,imc ;//variables de altura, peso y resultado.
	
	 imc = 0;
	 altura = 0;
	 peso = 0;
	 
	float a ;//variable auxiliar
	
	printf (" Estimado, si lo que desea es saber su imc presione -1- y luego -enter-\n\n Si desea salir presione cualquier tecla y luego -enter- para cerrar el programa\n");
			
	scanf ("%f", &a);
		
	
	if (a==1){
		
		printf("     Ingrese su altura en metros:");
		scanf("%f",&altura);
		
		printf("     Ingrese su peso en kilogramos:");
		scanf("%f",&peso);
		
		imc =(peso)/(altura*altura);
	    printf ("\n\n     su imc es el siguiente:\n\n        %2.2f\n", imc);
		
		
		
		if (imc<=18.5){
			
			printf ("\n\n     Tu estado es Bajo peso, esta por debajo de los parametros \n");
			
		}
		if(imc>18.5&&imc<25){
			
			printf ("\n\n     Tu estado es Normal, esta dentro de los parametros \n");
		}
		if(25<=imc&&imc<=29.9){
			
			printf ("\n\n     Tu estado es Sobrepeso, esta por encima de los parametros \n");
		}
		if(imc>29.9){
			
			printf ("\n\n     Tu estado es Obesidad, esta por ensima de los parametros \n");
		}
		
		}
	else{ printf (" okay, hasta luego! ");
	}
	return 0;
}
