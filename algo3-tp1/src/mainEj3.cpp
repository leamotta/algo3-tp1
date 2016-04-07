/*
 * main.cpp
 *
 *  Created on: 6/4/2016
 *      Author: agustin
 */

#include <iostream>
#include "kamehameha.h"
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

