/*
 * RandomInstanceGenerator.cpp
 *
 *  Created on: 2/4/2016
 *      Author: agustin
 */

#include "RandomInstanceGenerator.h"

using namespace std;

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

ej1 getEj1RandomInstance(){
	ej1 instance;
	instance.n = std::rand() % 10000;
	return instance;
}

ej2 getEj2RandomInstance(){
	ej2 instance;
	instance.n = (std::rand() % 100000) + 1;
	int maxT;
	int x, y;

	std::vector<int> coordX;
	std::vector<int> coordY;

	for(int i = 0; i<instance.n; i++){

		do{
			x=rand() % 1000000;
		}while(contiene(coordX,x));
		coordX.push_back(x);

		do{
			y=rand() % 1000000;
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
		instance.enemigos.push_back(ei);
	}

	return instance;
}

ej3 getEj3RandomInstance(){
	ej3 instance;
	int x, y;

	std::vector<int> coordX;
	std::vector<int> coordY;

	for(int i = 0; i<instance.n; i++){

		/*do{
			x=rand() % 1000000;
		}while(contiene(coordX,x));*/
		coordX.push_back(x);

		/*do{
			y=rand() % 1000000;
		}while(contiene(coordY,y));*/
		coordY.push_back(y);

	}

	for(int i=0;i<instance.n;i++){
		int x;
		int y;
		x=coordX[i];
		y=coordY[i];
		pair<int,int>ei(x,y);
		instance.enemigos.push_back(ei);
	}

	return instance;
}
