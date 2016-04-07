/*
 * RandomInstanceGenerator.cpp
 *
 *  Created on: 2/4/2016
 *      Author: agustin
 */

#include "RandomInstanceGenerator.h"
#include "Enemigo.h"

using namespace std;

int myRand(){
	return rand()%1000 + (rand()%1000)*1000 + (rand()%1000)*1000000;
}

void insertionSort(std::vector<int>& v){
	for(int i = 1; i< v.size(); i++){
		int j = i;
		int x = v[i];
		while(j>0 && v[j-1]>x){
			v[j]=v[j-1];
			j--;
		}
		v[j]=x;
	}
}

void invertedInsertionSort(std::vector<int>& v){
	for(int i = 1; i< v.size(); i++){
		int j = i;
		int x = v[i];
		while(j>0 && v[j-1]<x){
			v[j]=v[j-1];
			j--;
		}
		v[j]=x;
	}
}

bool contiene(const std::vector<int>& v, int x){
	for(int i = 1; i< v.size(); i++){
		if(v[i]==x){
			return true;
		}
	}
	return false;
}

ej1 getEj1RandomInstance(int n, int h){
	ej1 instance;
	instance.n=n;
	return instance;
}

ej2 getEj2RandomInstance(int n, int h){
	ej2 instance;
	std::srand(h);
	instance.n = n;
	int maxT;
	int x, y;

	std::vector<int> coordX;
	std::vector<int> coordY;

	for(int i = 0; i<instance.n; i++){
		do{
			x=myRand() % 1000000000;
		}while(contiene(coordX,x));
		coordX.push_back(x);

		do{
			y=myRand() % 1000000000;
		}while(contiene(coordY,y));
		coordY.push_back(y);


	}

	invertedInsertionSort(coordX);
	maxT=coordX.front();
	insertionSort(coordY);
	maxT = max(maxT,coordY.back());
	instance.t = std::rand() % maxT;

	for(int i=0;i<instance.n;i++){
		int x;
		int y;
		x=coordX[i];
		y=coordY[i];
		pair<int,int>ei(x,y);
		instance.enemies.push_back(ei);
	}

	return instance;
}

ej3 getEj3RandomInstance(int n, int h){
	ej3 instance;
	std::srand(h);
	int x, y;
	instance.n = n;
	std::vector<int> coordX;
	std::vector<int> coordY;

	for(int i = 0; i<instance.n; i++){

		x=myRand() % 1000000;
		coordX.push_back(x);

		y=myRand() % 1000000;
		coordY.push_back(y);

	}

	for(int i=0;i<instance.n;i++){
		int xi;
		int yi;
		xi=coordX[i];
		yi=coordY[i];
		Enemigo ei(xi,yi,i);
		instance.enemies.push_back(ei);
	}

	return instance;
}
