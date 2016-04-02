/*
 * RandomInstanceGenerator.h
 *
 *  Created on: 2/4/2016
 *      Author: agustin
 */

#ifndef RANDOMINSTANCEGENERATOR_H_
#define RANDOMINSTANCEGENERATOR_H_

#include <stdio.h>
#include <math.h>
#include <list>
#include <vector>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct ej1{

	int n;

};

struct ej2{

	int n;
	int t;
	std::vector<std::pair<int,int> > enemigos;

};

struct ej3{

	int n;
	std::vector<std::pair<int,int> > enemigos;

};

ej1 getEj1RandomInstance();
ej2 getEj2RandomInstance();
ej3 getEj3RandomInstance();




#endif /* RANDOMINSTANCEGENERATOR_H_ */
