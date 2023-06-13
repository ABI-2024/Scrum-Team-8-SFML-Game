#include "hintergrund.h"
#include "Ereignis.h"
#include "Audio.h"

hintergrund::hintergrund(string name, int id) { //Konstruktor und Destruktor
	this->name = name;

	bild.loadFromFile("ressources/grafics/" + name + ".png"); //laden des Bildes

	popup.setTexture(bild);

	popup.setPosition(Vector2f(0, 0)); //Positionierung und setzten

	current = 1;

	this->id = id;
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

	if (current == 41 && id == 2) {
		popup.move(0, -4);
	}

}

void hintergrund::update_hintergrund(Audio* music) {
	
	if (Ereignis::getcurrentevent() != current) {

		switch (Ereignis::getcurrentevent()) {

		case 16:

			if (current != 16) {

				current = 16;
				if (id == 1) {
					this->newimage("background2");
				}

				break;

			}


		case 41:

			if (current != 41) {

				current = 41;

				if (id == 2) {
					this->newimage("Bomber");
					popup.setPosition(0, 1700);
					music->changeSong("ressources/audio/bomb.ogg");

				}

				break;
			}
			

		}



	}

	
}