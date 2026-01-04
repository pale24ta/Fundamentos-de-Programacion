#include<stdio.h>
#include<stdlib.h>

const int MAX_L = 50;


void printMatrix(int matrix[][MAX_L], int n, int m);

void expandMatrix(int matrix[][MAX_L], int destiny[][MAX_L], int n, int m, int scale);

int main(){
	int n = 0, m = 0;
	int i = 0, j = 0;
	int matriz[MAX_L][MAX_L];
	int destiny[MAX_L][MAX_L];

	int scale = 2;

	while(scanf("%i",&matriz[i][j]) != EOF){
		j++;
		if(j > m){
			m = j;
		}
		if(getchar() == '\n' || feof(stdin)){
			i++;
			j = 0;
			if(i > n){
				n = i;
			}
		}
	}

	printf("%i %i\n",n,m);

	printMatrix(matriz,n,m);

	// desarrollo

	expandMatrix(matriz,destiny,n,m,scale);

	int nDestiny = n *scale;
	int mDestiny = m *scale;
	// 

	printMatrix(destiny,nDestiny,mDestiny);
	return 0;
}


void expandMatrix(int matrix[][MAX_L], int destiny[][MAX_L], int n, int m, int scale){
	int a = 0, b = 0;	// Puntos iniciales para la matriz destiny

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m ; j++){

			// tomamos una parte de destiny que seria una matriz scale x scale
			// para ello debemos buscar desde que punto hasta que punto pintaremos la matriz

			// limites
			int limit_n = a + scale;
			int limit_m = b + scale;

			// pintamos

			for(int fila = a; fila < limit_n && fila < n * scale; fila++){
				for(int column = b; column < limit_m && column < m *scale; column++){
					destiny[fila][column] = matrix[i][j];
				}
			}

			// movemos la columna de origen
			b = b + scale;
		}

		// movemos la fila de origen y reiniciamos columna
		a = a + scale;
		b = 0;
	}
}

void printMatrix(int matrix[][MAX_L], int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%i",matrix[i][j]);

			if(j + 1 < m){
				printf(" ");
			}
		}
		printf("\n");
	}
}