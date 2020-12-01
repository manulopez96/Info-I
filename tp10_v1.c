#include <stdio.h>
#include <time.h>
#include<unistd.h>
#define N 20

void imprime_lista (){
	
}

typedef struct {
	int record;
	char herramienta[N];
	int cantidad;
	double costo;
}ferreteria;

int main(void) {
	
	ferreteria herramientas={0,"",0,0.0};
	
	FILE *parchivo;
	
	if(fopen("hardware.dat","wb")==NULL){
		printf("  El archivo hardware.dat no pudo abrirse");
	}else{
		for(int i=0;i<100;i++){
			fwrite(&herramientas,sizeof(ferreteria),1,parchivo);
		}
		printf("  Seleccione la opcion que desea realizar:\n\n");
		printf("  1. Agregar productos.\n\n");
		printf("  2. Quitar productos.\n\n");
		printf("  3. Ver lista.\n\n");
	}
	
	return 0;
}

