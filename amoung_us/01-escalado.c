#include<stdio.h>
#include<stdio.h>

typedef struct{
    int r,g,b;
}Pixel;


const int LIMIT_MAX = 60;

/**
 * Para este ejercicio necesitamos desarrollar un programa que seea capaz de escalar un archivo .ppm (una imagen) sin perder calidad
 * 
 * SOLUCION: el truco esta en ver la secuencia del escalado de cada pixel, cuando se repite ese pixel m-columnas y n-filas del archivo
 * , esto hace pensar que necesitariamos una matriz para resolver el problema, pero en esta solucion no se vio necesaria, aqui lo importante,
 * seria imprimir esa n y m veces de cada pixel en la salida.
 * 
 * nuestra variable escalado seria e, asi que escribiriamos e-veces en filas y e-veces en columnas.
 * 
 * lo otro sera almacenar o enlistar a la fila para imprimir, o escribir en el archivo las e-veces en una fila, para luego iterar desde el principio
 * de la lista y repetir los anteriores pasos de las columnas, e-veces (dados por las e-veces de la fila)
 * 
 * 
 * IMPORTANTE: Para cargar los archivos debemos compilar y desde bash, utilizar el comando ./run <(nombre_archivo).ppm >(nombre_salida).ppm y tener el archivo escalado.conf
 * 
 * */


int main(){
    FILE *file = fopen("escalado.conf","r");    // Abrimos el archivo donde guardamos la variable e

    if(file != NULL){
        char format[2];
        int alto,ancho;
        int prof;

        int scale;
        Pixel pixeles[LIMIT_MAX];   // Lista de pixeles
        int size_pixeles = 0;

        // leemos el archivo .conf
        fscanf(file,"%i",&scale);

        if(scale == 0){
            scale = 1;
        }
        // leemos el archivo

        scanf("%s",format);

        scanf("%i %i",&ancho,&alto);

        scanf("%i",&prof);

        // int index_i = 0,index_j = 0;
        // los pixeles, a la par de procesarlo

        printf("%s\n",format);
        printf("%i %i\n",ancho * scale, alto * scale);
        printf("%i\n",prof);



        for(int i = 0; i < alto; i = i + 1){

            size_pixeles = 0;   // iniciamos la lista vacia
            for(int j = 0 ; j < ancho; j = j + 1){
                Pixel aux;
                scanf("%i %i %i",&aux.r,&aux.g,&aux.b);

                // enlistamos los pixeles
                pixeles[size_pixeles] = aux;
                size_pixeles += 1;

                // index_j = index_j + scale;
            }

            // una ves enlistados, imprimimos los pixeles

            for(int row = 0 ; row < scale ; row++){

                // iteramos la lista
                for(int color = 0; color < size_pixeles; color++){

                    // imprimimos e-veces ese pixel
                    for(int column = 0; column < scale; column++){
                        printf("%i %i %i",pixeles[color].r,pixeles[color].g,pixeles[color].b);
                        
                        // hacer un espacio
                        if(column + 1 < scale){
                            printf(" ");
                        }
                    }
                    if(color + 1 < size_pixeles){
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    
    }

    fclose(file);
    return 0;
}


