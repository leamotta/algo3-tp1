#include "kaioKen.h"

void kaioKen (int cantGuerreros) {

	int divisor = cantGuerreros;
	int pelea = 1;

	cout << ceil(log2(cantGuerreros)) << endl;

	while (divisor!= 1){
		if(divisor % 2 == 1){
			divisor = (divisor / 2) + 1;
		}else{
			divisor = (divisor / 2);
		}

		int j = 1;
		int i = 1;

		while (i<= (cantGuerreros / 2)){
			if(i>j*divisor)
				j++;
			if(j%2 == 0){
				cout << "2 ";
			}else{
				cout << "1 ";
			}
			i++;
		}
        j = 1;
		while (i > (cantGuerreros / 2) && i <= cantGuerreros){
			if(i> j*divisor + cantGuerreros/2 )
				j++;
			if(j%2 == 0){
				cout << "1 ";
			}else{
				cout << "2 ";
			}
			i++;
		}

		pelea++;
		cout <<endl;
	}

}


