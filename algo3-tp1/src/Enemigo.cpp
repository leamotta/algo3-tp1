#include "Enemigo.h"

using namespace std;

Enemigo::Enemigo(int posX, int posY, int numeroEnemigo) {
	this->x = posX;
	this->y = posY;
	this->numero = numeroEnemigo;
	this->kamehameha = 0;
	this->muerto = false;
}

Enemigo::~Enemigo() {}

int Enemigo::X() {
	return this->x;
}

int Enemigo::Y() {
	return this->y;
}

int Enemigo::Kamehameha() {
	return this->kamehameha;
}

int Enemigo::Numero() {
	return this->numero;
}

bool Enemigo::Muerto(){
	return this->muerto;
}

void Enemigo::Matar(){
	this->muerto = true;
}

void Enemigo::Revivir(){
	this->muerto = false;
}

void Enemigo::AsignarKamehameha(int kamehameha){
	this->kamehameha = kamehameha;
}

bool Enemigo::operator=(const Enemigo& otro) const{
	return x == otro.x && y == otro.y;
}

bool Enemigo::operator==(const Enemigo& otro) const {
	return x == otro.x && y == otro.y;
}


