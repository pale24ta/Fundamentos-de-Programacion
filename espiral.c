#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 50


void espiral(int map[MAX][MAX],int filas, int columnas);
void imprimirMatriz(int map[MAX][MAX],int filas, int columnas);

int main(){
    int matriz[MAX][MAX];
    int filas = 0,columnas = 0;
    int i = 0,j = 0;
    char sig;

    while(scanf("%i",&matriz[i][j]) != EOF){
        j++;
        if(j > columnas){
            columnas = j;
        }
        sig = getchar();
        if(sig == '\n' || sig == EOF){
            i++;
            j = 0;
            if(i > filas){
                filas = i;
            }
        }
    }
    printf("%i %i\n",filas,columnas);
    imprimirMatriz(matriz,filas,columnas);
    espiral(matriz,filas,columnas);
    return 0;
}

void imprimirMatriz(int map[MAX][MAX],int filas, int columnas){
    for(int i = 0; i < filas; i++){
        printf("[");
        for(int j = 0; j < columnas; j++){
            printf("%i",map[i][j]);
            if(j + 1 < columnas){
                printf(",");
            }
        }
        printf("]\n");
    }
}

void espiral(int map[MAX][MAX],int filas, int columnas){
    
    // definimos los limites
    int superior  = 0;
    int inferior = filas;
    int izquierdo = 0;
    int derecho = columnas;

    while(superior <= inferior && izquierdo <= derecho){

        // izquierda
        for(int j = izquierdo; j < derecho; j++){
            printf("%i ",map[superior][j]);
        }

        // escluimos la fila superior
        superior++;

        // abajo
        for(int i = superior; i < inferior; i++){
            printf("%i ",map[i][derecho-1]);
        }
        
        //excluimos la columna derecha
        derecho--;

        //izquierda

        for(int j = derecho-1; j >= izquierdo; j--){
            printf("%i ",map[inferior-1][j]);
        }

        // excluimos el inferior
        inferior--;

        // arriba

        for(int i = inferior-1; i >= superior; i--){
            printf("%i ",map[i][izquierdo]);
        }

        // excluimos el izquierdo
        izquierdo++;

        // repetimos el ciclo
    }
}