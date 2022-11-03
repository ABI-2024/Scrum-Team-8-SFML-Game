#include "Ressource.h"

Ressource::~Ressource() {

}

Ressource::Ressource(string name, float menge) {
	this->name = name;
	this->menge = menge;
}

float Ressource::getmenge(){
	return menge;
}

string Ressource::getname(){
	return name;
}

void Ressource::setname(string name) {
	this->name = name;
}

void Ressource::setmenge(float menge){
	this->menge = menge;
}

void Ressource::addmenge(float) {
	menge += menge;
}