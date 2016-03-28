#include "kaioKen.h"
int **matriz;
using namespace std;

void resuelveKaioKen(int cantGuerreros,int fila, int columna){
	if(cantGuerreros == 1){
		matriz[fila][columna] = 1;
		return;
	}
	if(cantGuerreros == 2){
		matriz[fila][columna] = 1;
		matriz[fila][columna+1] = 2;
		return;
	}
	int mitad = ceil(cantGuerreros/2);
	for(int i=0;i<cantGuerreros;i++){
		if(i<mitad){
			matriz[fila][columna+i] = 1;
		}else{
			matriz[fila][columna+i] = 2;
		}
	}
	resuelveKaioKen(mitad,fila+1,columna);
	resuelveKaioKen(cantGuerreros - mitad,fila+1,columna + mitad);
}

void kaioKen (int cantGuerreros) {

	matriz = new int*[(int) ceil(log2(cantGuerreros))];

	for(int i=0;i<(int) ceil(log2(cantGuerreros));i++){
		matriz[i] = new int[cantGuerreros];
	}

	resuelveKaioKen(cantGuerreros,0,0);
	printf("%d\n",(int) ceil(log2(cantGuerreros)));
	for(int i=0;i<ceil(log2(cantGuerreros));i++){
		for(int j=0;j<cantGuerreros;j++){
			if(matriz[i][j]){
				printf("%d ",matriz[i][j]);
			}else{
				printf("%d ",1);
			}
		}
		printf("\n");
	}
}
