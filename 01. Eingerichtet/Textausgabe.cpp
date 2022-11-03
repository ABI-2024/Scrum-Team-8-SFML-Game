#include "Textausgabe.h"
#include "stdafx.h"
using namespace std;
using namespace sf;

Textausgabe::Textausgabe() {
	text = 0;
	ausgeg = 0;
	strings = 0;
	tics = 0;
}


void Textausgabe::einlesen(std::string* insert, int amount) {
	text = insert;
	strings = amount;
	/*
	text = new string[amount];
	for (int i = 0; i < amount; i++) {
		text[i] = insert[i];
	}
	*/
}

void Textausgabe::darstellen(RenderWindow* window) {		//Ausgabe des Textfeldes samt Texthintergrund
	if (text == 0) {
		return;
	}


	
}


Textausgabe::~Textausgabe() {
	return;
}