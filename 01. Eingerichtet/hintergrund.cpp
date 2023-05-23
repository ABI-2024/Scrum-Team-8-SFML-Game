#include "hintergrund.h"
#include "Ereignis.h"

hintergrund::hintergrund(string name) { //Konstruktor und Destruktor
	this->name = name;

	bild.loadFromFile("ressources/grafics/" + name + ".png"); //laden des Bildes

	popup.setTexture(bild);

	popup.setPosition(Vector2f(0, 0)); //Positionierung und setzten

	current = 1;
}

hintergrund::~hintergrund() {

}

void hintergrund::newimage(string name) { //get und set Methoden
	this->name = name;

	bild.loadFromFile("ressources/grafics/" + name + ".png"); //laden des Bildes

	popup.setTexture(bild);

	popup.setPosition(Vector2f(0, 0)); //Positionierung und setzten
}

string hintergrund::getname() {
	return name;
}

void hintergrund::darstellen(RenderWindow* window) { //anzeigen des Popups

	window->draw(popup);

}

void hintergrund::update_hintergrund() {
	
	if (Ereignis::getcurrentevent() != current) {

		switch (Ereignis::getcurrentevent()) {

		case 16:
			current = 16;
			this->newimage("background2");
			
		}



	}
	
}