#include "stdafx.h"

using namespace std;
using namespace sf;

int Ressource::typc = 1;

Ressource::~Ressource() {

}

Ressource::Ressource(string name, float menge) {
	this->name = name;
	this->menge = menge;
	typ = typc;
	typc++;
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

void Ressource::addmenge(float menge) {
	this->menge += menge;
}

void Ressource::darstellen(RenderWindow* window){
	Texture textur;

	Font font;
	font.loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");

	Text text("", font);

	if (typ == 1) {
		textur.loadFromFile("ressources/grafics/apfel.png");
	}
	else if (typ == 2) {
		textur.loadFromFile("ressources/grafics/wasser.png");
	}

	Sprite sprite;
	sprite.setTexture(textur);

	int anzahl = menge;

	if (typ == 1) {

		sprite.setPosition(Vector2f(10, 10));
		sprite.scale(Vector2f(0.05, 0.05));

		text.setPosition(55, 7);
	}

	else if (typ == 2) {

		sprite.setPosition(Vector2f(140, 5));
		sprite.scale(Vector2f(0.125, 0.125));

		text.setPosition(185, 7);
	}

	text.setCharacterSize(40);
	text.setString(to_string(anzahl) + "X");
	
	window->draw(sprite);
	window->draw(text);

}