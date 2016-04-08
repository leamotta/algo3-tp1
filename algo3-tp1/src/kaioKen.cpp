#include "kaioKen.h"
#include <iostream>
int **matriz;
using namespace std;


int main(){
	int cantidad;
	cin>>cantidad;

	kaioKen(cantidad);
	
	return 0;
}

void resuelveKaioKen(int cantGuerreros,int fila, int columna){
	
	//CASO BASE #1
	if(cantGuerreros == 1){
		matriz[fila][columna] = 1;
		return;
	}
	//CASO BASE #2
	if(cantGuerreros == 2){
		matriz[fila][columna] = 1;
		matriz[fila][columna+1] = 2;
		return;
	}
	int mitad = ceil(cantGuerreros/2); //Utilizo la función techo para manejar los casos impares

	for(int i=0;i<cantGuerreros;i++){
		if(i<mitad){
			matriz[fila][columna+i] = 1; //Si pertenece a la primer mitad de guerreros lo asigno al primer bando, caso contrario al segundo
		}else{
			matriz[fila][columna+i] = 2;
		}
	}

	//Llamo a la recursion para ambos bandos, ya que entre ellos los guerreros todavia no lucharon.
	//Eso generará una nueva pelea por lo que incremento la fila en 1 para ambos casos.
	//Los guerreros del primer bando empiezan en la misma columna, los del segundo pasando la mitad (Es solo para poder tener una visualizacion correcta)
	resuelveKaioKen(mitad,fila+1,columna);
	resuelveKaioKen(cantGuerreros - mitad,fila+1,columna + mitad);
}

void kaioKen (int cantGuerreros) {

	//Dado la lógica del algoritmo, se puede anticipar de antemano cuantas peleas habrá. Ese valor se almacena en iteraciones
	int iteraciones = (int) ceil(log2(cantGuerreros));
	matriz = new int*[iteraciones]; //Inicializa una matriz con esa cantidad de filas que luego se irá completando en la recursión

	for(int i=0;i<iteraciones;i++){ //O(log n)
		matriz[i] = new int[cantGuerreros]; //O(n)
		for(int j=0; j< cantGuerreros; j++){ //O(n)
			matriz[i][j] = 1; //Por defecto, todos los guerreros están en el bando 1. Esto es arbitrario.
		}
	}//O(log n * 2n) = O(log n * n) = O(n log n)

	//Punto de entrada
	resuelveKaioKen(cantGuerreros,0,0);

	//Se realiza la impresión de la matriz en el formato esperado.
	printf("%d\n",iteraciones);
	for(int i=0; i < iteraciones; i++){
		for(int j=0;j<cantGuerreros;j++){
			if(matriz[i][j]){
				printf("%d ",matriz[i][j]);
			}else{
				printf("%d ",1);
			}
		}
		delete[] matriz[i]; //Libero memoria para evitar goteo
		printf("\n");
	}
	delete[] matriz;
}
