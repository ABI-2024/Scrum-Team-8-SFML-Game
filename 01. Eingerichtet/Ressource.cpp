#include "stdafx.h"

using namespace std;
using namespace sf;

int Ressource::typc = 0;

Ressource::~Ressource() {											//Destruktor

}

Ressource::Ressource(string name, int menge) {					//Konstruktor
	this->name = name;
	this->menge = menge;
	typ = typc;
	typc++;
}

int Ressource::getmenge(){										//get und set Methoden
	return menge;
}

string Ressource::getname(){
	return name;
}

void Ressource::setname(string name) {
	this->name = name;
}

void Ressource::setmenge(int menge){
	this->menge = menge;
}

void Ressource::addmenge(int menge) {								//Änderung der Werte
	this->menge += menge;
}

void Ressource::darstellen(RenderWindow* window){
	Texture textur;													//Laden von Texturen und Font

	Font font;
	font.loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");

	Text text("", font);
	
	textur.loadFromFile("ressources/grafics/" + name + ".png"); //Laden der jeweiligen Textur
	Sprite sprite;
	sprite.setTexture(textur);

	int anzahl = menge;



	sprite.setPosition(Vector2f(10 + 170 * typ, 10));
	sprite.scale(Vector2f(0.1f, 0.1f));								//Laden der Sprite und scaierung, Position abhängig von dem Index (typ)

	text.setPosition(70.f + 170.f * typ, 7.f);


	text.setCharacterSize(40);										//Anzeigen der konkreten Menge mit einem X und der richtigen Schriftgröße
	text.setFillColor(Color(0, 0, 0, 255));
	text.setString(to_string(anzahl) + "X");
	
	window->draw(sprite);											//finale ausgabe
	window->draw(text);

}