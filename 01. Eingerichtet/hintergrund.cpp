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

	if (current == 38 && id == 2) {
		popup.move(0, -4);
		if (false) window->setPosition(sf::Vector2i(100 + rand() % 25, 100 + rand() % 25));
	}

}

void hintergrund::update_hintergrund(Audio* music) {
	
	if (Ereignis::getcurrentevent() != current) {

		switch (Ereignis::getcurrentevent()) { // triggern eines Special Effects nach der zurzeitigen Event ID

		case 16:

			current = 16;
			if (id == 1) {
				this->newimage("background2");

				buffer.loadFromFile("ressources/audio/baum.ogg");

				sound.setBuffer(buffer);
				sound.setVolume(100);

				sound.play();

			}

				break;

			


		case 38:


			current = 38;

			if (id == 2) {
				this->newimage("Bomber");
				popup.setPosition(0, 1600);
				music->changeSong("ressources/audio/bomb.ogg");

			}

			if (id == 5) {
				this->newimage("Krater");
			}

			break;
			
			
		case 20:

			current = 20;

			if (id == 3) {

				this->newimage("Zelte");

				buffer.loadFromFile("ressources/audio/zelte.ogg");

				sound.setBuffer(buffer);
				sound.setVolume(100);

				sound.play();

			}

			break;

		case 21:

			current = 21;

			if (id == 4) {

				this->newimage("Panzer");

				buffer.loadFromFile("ressources/audio/panzer.ogg");

				sound.setBuffer(buffer);
				sound.setVolume(100);

				sound.play();
			}

			break;

		case 33:

			current = 33;

			if (id == 6) {

				this->newimage("Flak");

				buffer.loadFromFile("ressources/audio/flak.ogg");

				sound.setBuffer(buffer);
				sound.setVolume(100);

				sound.play();
			}

			break;

		}



	}

	
}