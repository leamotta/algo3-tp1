#include <iostream>
#include "kaioKen.h"
#include "genkidama.h"
#include "kamehameha.h"

using namespace std;

int main(int n,char* args[] ) {
	/*int cantidad;
	cin>>cantidad;

	kaioKen(cantidad);
*/
	int N;
	int T;
	cin>>N>>T;
	vector<pair<int,int> > enemigos;

	for(int i=0;i<N;i++){
		int x;
		int y;
		cin>>x>>y;
		pair<int,int>ei(x,y);
		enemigos.push_back(ei);
	}

	/*std::pair<int,int>e1(100,0);
	std::pair<int,int>e2(75,25);
	std::pair<int,int>e3(50,50);
	std::pair<int,int>e4(25,75);
	std::pair<int,int>e5(0,100);
	std::vector<std::pair<int,int> > enemigos;
	enemigos.push_back(e1);
	enemigos.push_back(e2);
	enemigos.push_back(e3);
	enemigos.push_back(e4);
	enemigos.push_back(e5);*/
	genkidama(N,T,enemigos);
	return 0;
}
