#include<cstdio>
#include<sys/time.h>

using namespace std;

timeval timeStart,timeEnd;

void init_time()
{
    gettimeofday(&timeStart,NULL);
}

double get_time()
{
    gettimeofday(&timeEnd,NULL);
    return (1000000*(timeEnd.tv_sec-timeStart.tv_sec)+(timeEnd.tv_usec-timeStart.tv_usec))/1000000.0;
}

int main()
{
	init_time();
	/**
	 * Estas lineas hacen cuentas dummy y no solo 
	 * algo simple para que el compilador no se de cuenta
	 * que puede optimizar y las saque del programa
	**/
	int t = 22;
	for(int i=0;i<1000000000;i++)
	if(t%2 == 0)
		t /= 2;
	else
		t = (3*t+1);
	if(t != 0)
		printf("%.10f\n",get_time());
}

/**
 * La funcion init_time() empieza a medir el tiempo, la funcion get_time devuelve un double con la cantidad 
 * de segundos que pasaron desde que se hizo init_time. Si se quiere medir los tiempos de mas de una cosa 
 * se pueden crear mas variables de tipo timeval y hacer funciones iguales a init_time y get_time con las otras
 * variables que se usen 
**/
