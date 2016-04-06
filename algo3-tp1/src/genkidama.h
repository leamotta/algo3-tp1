#ifndef GENKIDAMA_H_
#define GENKIDAMA_H_
#include <stdio.h>
#include <math.h>
#include <list>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

void genkidama(int N,int T,vector<pair<int,int> > enemigos);
int masLejanoQueMato(int disparado,int N,int T,vector<pair<int,int> > &enemigos);
int masLejanoQueMeMata(int aMatar,int N,int T, vector<pair<int,int> > &enemigos);
bool loMata(int i,int j,int N,int T,vector<pair<int,int> > &enemigos);

#endif /* GENKIDAMA_H_ */
