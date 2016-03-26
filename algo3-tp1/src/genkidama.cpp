#include "genkidama.h"

void genkidama(int N,int T,vector<pair<int,int> > enemigos){
	int genkidamas=0;
	int i=0;
	list<int> disparados;
	while (i<N) {
		int disparado=masLejanoQueMeMata(i,N,T,enemigos);
	    i = masLejanoQueMato(disparado,N,T,enemigos) + 1;

	    disparados.push_back(disparado+1); //el 0 de la lista es el enemigo 1 y asi sucesivamente
	    genkidamas++;
	}

	printf("%d\n",genkidamas);
	for(int i=0; i<genkidamas; i++){
	  	printf("%d ",disparados.front());
		disparados.pop_front();
	}
}

int masLejanoQueMeMata(int aMatar,int N, int T,vector<pair<int,int> > enemigos){
    int j=aMatar+1;
    while(loMata(j,aMatar,N,T,enemigos)){//me mata el siguiente?
      j++;
    }
    return j-1;//devuelvo ultimo que me mata
}

int masLejanoQueMato(int disparado, int N,int T, vector<pair<int,int> > enemigos){
  int j=disparado+1;
  while(loMata(disparado,j,N,T,enemigos)){//mato al siguiente?
    j++;
  }
  return j-1;//devuelvo ultimo que mato
}

bool loMata(int i,int j,int N,int T,vector<pair<int,int> > enemigos){//mata i al j?
  return enemigos[i].first + T >= enemigos[j].first && enemigos[i].second + T >= enemigos[j].second;
}

