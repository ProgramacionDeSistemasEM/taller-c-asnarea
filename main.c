#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char **argv){
	
	int elementos = 0;
	char c = 0;
	
	
	//Aqui manejamos las opciones.
	//El argumento -p tiene un argumento, que es 
	//el numero de elementos a pedir (por eso el :)
	while ((c = getopt (argc, argv, "p:")) != -1){
		switch(c){
			case 'p':
				elementos = atoi(optarg);
				break;
			default:
				printf("Argumento invalido\n");
				exit(1);
		}
	}

	//Los resultados de sus calculos van en estas variables.
	//Puede declarar más variables si lo necesita.
	float sum = 0.0f;
        float sum2 = 0.0f; 
	float max_imc = 0.0f;   

        float peso[elementos];
        float altura[elementos];
        float arreglo[elementos];
        for(int i=0 ; i<elementos ; i++ ){
            printf("Peso:");  
            scanf("%f", &peso[i]);
            while(peso[i]<0){
                 printf("Número inválido");
                 scanf("%f", &peso[i]);
            }
            printf("Altura:");
            scanf("%f", &altura[i]);
            while(altura[i]<0){
                  printf("Numero Invalido");
                  scanf("%f", &altura[i]);
            }
           
        } 
        for(int j=0 ; j<elementos ; j++){
            sum = peso[j] + sum;
        }
        for(int h=0; h<elementos ; h++){
            sum2 = altura[h]+ sum2 ;
 
        }
       
       for(int i=0 ; i<elementos ; i++){
           float calculo = peso[i]/(altura[i]*altura[i]);
           arreglo[i]= calculo ;

       }
        float imc = sum/(sum2*sum2);
        float max = arreglo[0];
        
	for(int i=1; i<elementos ;i++ ){
            if(max<arreglo[i]){ 
               max=arreglo[i];
            }
        }
        max_imc=max;
	
	//No modifique estas lineas
	//Guarde los resultados en las 
	printf("\npromedio IMC: %.1f\n", imc);
	printf("maximo IMC: %.1f\n", max_imc);
}
