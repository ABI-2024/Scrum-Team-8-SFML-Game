#include "hintergrund.h"
#include "Ereignis.h"
#include "Audio.h"

void zeitung(RenderWindow* window, string name);

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

void hintergrund::update_hintergrund(Audio* music, RenderWindow* window) {
	
	if (Ereignis::getcurrentevent() != current) {

		switch (Ereignis::getcurrentevent()) { // triggern eines Special Effects nach der zurzeitigen Event ID

		case 16:

			current = 16;
			if (id == 1) {

				zeitung(window, "baumnews");

				this->newimage("background2"); //jeweilige Bildänderung

				buffer.loadFromFile("ressources/audio/baum.ogg"); //jeweilger Soundeffekt

				sound.setBuffer(buffer);
				sound.setVolume(100);

				sound.play();

			}

				break;

			


		case 39:


			current = 39;

			if (id == 2) {

				zeitung(window, "bombernews");

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

				zeitung(window, "zeltnews");

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

				zeitung(window, "panzernews");

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

				zeitung(window, "flaknews");

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


void zeitung(RenderWindow* window, string name) {
	Sprite news;
	Texture article;

	article.loadFromFile("ressources/grafics/" + name + ".png");
	news.setTexture(article);

	news.setPosition(Vector2f(370, 100));
	window->clear();
	window->draw(news);
	window->display();

	while (true) {
		if (Keyboard::isKeyPressed(Keyboard::Enter)) {
			break;
		}
	}
}