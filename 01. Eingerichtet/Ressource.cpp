#include "stdafx.h"

using namespace std;
using namespace sf;

int Ressource::typc = 1;

Ressource::~Ressource() {											//Destruktor

}

Ressource::Ressource(string name, float menge) {					//Konstruktor
	this->name = name;
	this->menge = menge;
	typ = typc;
	typc++;
}

float Ressource::getmenge(){										//get und set Methoden
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

void Ressource::addmenge(float menge) {								//Änderung der Werte
	this->menge += menge;
}

void Ressource::darstellen(RenderWindow* window){
	Texture textur;													//Laden von Texturen und Font

	Font font;
	font.loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");

	Text text("", font);

	if (typ == 1) {													//Textur für Essen
		textur.loadFromFile("ressources/grafics/apfel.png");
	}
	else if (typ == 2) {											//Textur für Wasser
		textur.loadFromFile("ressources/grafics/wasser.png");
	}

	Sprite sprite; 
	sprite.setTexture(textur);

	int anzahl = menge;

	if (typ == 1) {													//Laden der Sprites und deren größe für Essen

		sprite.setPosition(Vector2f(10, 10));
		sprite.scale(Vector2f(0.05, 0.05));

		text.setPosition(55, 7);
	}

	else if (typ == 2) {											//Sprites für Wasser

		sprite.setPosition(Vector2f(140, 5));
		sprite.scale(Vector2f(0.125, 0.125));

		text.setPosition(185, 7);
	}

	text.setCharacterSize(40);										//Anzeigen der konkreten Menge mit einem X und der richtigen Schriftgröße
	text.setString(to_string(anzahl) + "X");
	
	window->draw(sprite);											//finale ausgabe
	window->draw(text);

}