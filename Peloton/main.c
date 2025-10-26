#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct{
    char nombre[MAX];
    int noches;
    int fila,columnas;
    int mapa[MAX][MAX];
    float promedioEfectividad;
    int nocheMasIntensa;
}Peloton;

void promedioCadaNoche(Peloton pelotonActual, float noches[]);

int main(){
    Peloton pelotonLeido;

    FILE *in = fopen("misiones.txt","r");
    FILE *reporte = fopen("reporte.txt","w");

    if(in == NULL){
        perror("no existe");
    }else{
        int casos;

        fscanf(in,"%i",&casos);

        // vamos imprimiendo el reporte final

        fprintf(reporte,"=== REPORTE DE INTELIGENCIA ALIADA ===\nFecha: Julio de 1944 - Cuartel General Aliado\nAnalista: Brigido Noguera");


        char pelotonMayorEfectividad[MAX];
        float mayorEfectividad = -999;
        
        while(casos > 0){

            // leemos el nombre
            fscanf(in,"%s",pelotonLeido.nombre);
            // leemos la noches de i caso
            fscanf(in,"%i",&pelotonLeido.noches);

            // lectura de filas y columnas
            fscanf(in,"%i %i",&pelotonLeido.fila,&pelotonLeido.columnas);

            // inicializamos el promedio de efecitvidad 
            // leemos los mapas

            for(int i = 0; i < pelotonLeido.fila * pelotonLeido.noches; i++){
                for(int j = 0; j < pelotonLeido.columnas; j++){
                    fscanf(in,"%i",&pelotonLeido.mapa[i][j]);
                }
            }

            // incializamos el promedio y la noche mas intensa
            pelotonLeido.nocheMasIntensa = 0;
            pelotonLeido.promedioEfectividad = 0;

            // declaramos un arreglo de promedio de noches para el peloton actual
            float noches[MAX];
            // procesamos los mapas
            promedioCadaNoche(pelotonLeido,noches);

            // procesamos el vector de noches
            float mayorPromedioIntensidad = -999;
            float promedioFinal = 0;
            for(int i =0; i < pelotonLeido.noches; i++){

                // printf("%.2f ",noches[i]);
                if(noches[i] > mayorPromedioIntensidad){
                    mayorPromedioIntensidad = noches[i];
                    pelotonLeido.nocheMasIntensa = i+1;
                }
                promedioFinal += noches[i];
            }
            
            pelotonLeido.promedioEfectividad = promedioFinal/pelotonLeido.noches;

            // Imprimimos sus datos

                /*
            Escuadron: Halifax 
            Dimensiones del mapa: 4x6 
            Noches operadas: 2 
            Efectividad media: 50.00 
            Noche más intensa: 2 */

            fprintf(reporte,"\n\nEscuadron : %s",pelotonLeido.nombre);
            fprintf(reporte,"\nDimension Del mapa: %ix%i",pelotonLeido.fila,pelotonLeido.columnas);
            fprintf(reporte,"\nNoches Operadas: %i",pelotonLeido.noches);
            fprintf(reporte,"\nEfectividad media: %.2f",pelotonLeido.promedioEfectividad);
            fprintf(reporte,"\nNoche mas Intensa: %i",pelotonLeido.nocheMasIntensa);
            
            // verificamos si el peloton actual tiene la mejor efectividad
            if(pelotonLeido.promedioEfectividad > mayorEfectividad){
                strcpy(pelotonMayorEfectividad,pelotonLeido.nombre);
                mayorEfectividad = pelotonLeido.promedioEfectividad;
            }
            
            casos--;
        }

        fprintf(reporte,"\n\n*** ESCUADRON MAS EFECTIVO ***\n%s (Efectividad Media: %.2f)\nOrden del Comando Supremo: Condecorar al comandante de %s.\nFin del reporte.",pelotonMayorEfectividad,mayorEfectividad,pelotonMayorEfectividad);
    }
    fclose(reporte);
    fclose(in);
}

void promedioCadaNoche(Peloton pelotonActual, float noches[]){
    float promedio = 0;
    int nocheActual = 0;
    int countFilas = 1; // variable que cuenta el numero de filas contadas
    // debido a que estamos tomando una matriz que contiene sub matrices de separadas por noche, pero que conservan el mismo numero de columnas
    for(int i =0; i < pelotonActual.fila * pelotonActual.noches; i++){
        for(int j = 0; j < pelotonActual.columnas; j++){
            promedio += pelotonActual.mapa[i][j];
        }

        if(countFilas == pelotonActual.fila && nocheActual < MAX){
            noches[nocheActual] = promedio / (pelotonActual.fila * pelotonActual.columnas);
            promedio = 0;
            nocheActual++;

            // reinicia el contador
            countFilas = 1;
        }else{
            countFilas++;
        }

    }
}