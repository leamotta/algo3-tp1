#include <iostream>
#include "kamehameha.h"
#include <cstdio>

using namespace std;

int main(int n,char* args[] ) {

	  int x;
	    cin >> x;
	    vector<Enemigo> ene;
	    for(int i=1; i <= x; i++){
	        int x,y;
	        cin >> x >> y;
	        ene.push_back(Enemigo(x,y,i));
	    }
	    resolverKamehameha(ene);

	return 0;
}

