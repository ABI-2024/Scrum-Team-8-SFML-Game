#include "Grafik.h"

Grafik::Grafik(string name) { //Konstruktor und Destruktor
	this->name = name;

	bild.loadFromFile("ressources/grafics/" + name + ".png"); //laden des Bildes

	popup.setTexture(bild);

	popup.setPosition(Vector2f(0, 15)); //Positionierung und setzten
}

Grafik::~Grafik() {

}

void Grafik::newimage(string name) { //get und set Methoden
	this->name = name;

	bild.loadFromFile("ressources/grafics/" + name + ".png"); //laden des Bildes

	popup.setTexture(bild);

	popup.setPosition(Vector2f(0, 15)); //Positionierung und setzten
}

string Grafik::getname() {
	return name;
}

void Grafik::darstellen(RenderWindow* window) { //anzeigen des Popups

	window->draw(popup);
	
}