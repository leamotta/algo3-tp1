#include "kaioKen.h"
int **matriz;
using namespace std;


int main(){
	int cantidad;
	cin>>cantidad;

	kaioKen(cantidad);
	
	return 0;
}

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

	int iteraciones = (int) ceil(log2(cantGuerreros));
	matriz = new int*[iteraciones];

	for(int i=0;i<iteraciones;i++){ //O(log n)
		matriz[i] = new int[cantGuerreros]; //O(n)
		for(int j=0; j< cantGuerreros; j++){ //O(n)
			matriz[i][j] = 1;
		}
	}//O(log n * 2n) = O(log n * n) = O(n log n)

	resuelveKaioKen(cantGuerreros,0,0);
	printf("%d\n",iteraciones);
	for(int i=0; i < iteraciones; i++){
		for(int j=0;j<cantGuerreros;j++){
			if(matriz[i][j]){
				printf("%d ",matriz[i][j]);
			}else{
				printf("%d ",1);
			}
		}
		delete[] matriz[i];
		printf("\n");
	}
	delete[] matriz;
}
