#ifndef KAMEHAMEHA_H_
#define KAMEHAMEHA_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <stdio.h>
#include "Enemigo.h"

using namespace std;

int KAMEHAMEHAS_OPTIMOS = numeric_limits<int>::max();
int KAMEHAMEHA_NUMERO = 0;
int ENEMIGOS_VIVOS;
vector<Enemigo> enemigos;
vector<Enemigo> enemigosSolucion;

void resolverKamehameha();
int matar(Enemigo* a, Enemigo* b);
int matar(Enemigo* a);
int revivir(Enemigo* a, Enemigo* b);
int revivir(Enemigo* a);
double pendiente(Enemigo a, Enemigo b);

//auxiliar
template <typename T>
string NumberToString ( T Number )
{
 ostringstream ss;
 ss << Number;
 return ss.str();
}

#endif /* KAMEHAMEHA_H_ */
