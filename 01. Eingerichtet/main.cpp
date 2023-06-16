#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Datum.h"
#include "Textausgabe.h"
#include "Ereignis.h"
#include "Ressource.h"
#include "Grafik.h"
#include "Audio.h"
#include "Person.h"
#include "setEvents.h"
#include "CSVcontrol.h"
#include "hintergrund.h"
#include "End.h"

using namespace sf;
using namespace std;

int rando(int a, int b); //gibt eine zufällige zahl bon a bis b zurück

void init();			//initialisiert fremde Klassen


void Zufallsgenerator();														//Einsetzen der Warteschlange
bool EndCheck(Ressource* essen, Ressource* wasser);								//Überprüfung zum Gameover
void EndLose(RenderWindow*, Audio*, Textausgabe*, Datum*);						//Trigger vom Endscreen bei Niederlage
void End(RenderWindow*, Audio*, Textausgabe*);									//Trigger vom Normalem Endscreen
void dayTransmission(RenderWindow*, int* transmissionphase);					// Macht einen Übergang von tag zu tag

int main() {

	init();

	int transmissionphase = 1.f;
	bool paused = false;
	Datum* date = new Datum(13, 6, 1936, 1);
	std::cout << "should: " << CSVcontrol::getEventStart(1) << " with : " << CSVcontrol::getEventStart(1) + CSVcontrol::getEventAmount(1) - 1 << endl;

	Warteschlange::addQueue(0);


	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(60);
	hintergrund hintergrundbase("background", 1);
	hintergrund bomber("default", 2);
	hintergrund zelt("default", 3);
	hintergrund panzer("default", 4);
	hintergrund krater("default", 5);
	hintergrund flak("default", 6);


	Ressource wasser("Wasser", 99); //initialisierung von Wasser - NICHT ÄNDERN!

	Ressource essen("Essen", 99); //initialisierung von Essen - NICHT ÄNDERN!


	Person::loadChars();
	sf::Event ev;


	Textausgabe txt;
	Audio music;
	int counter = 0;
	Ereignis::setTxt(&txt);
	Ereignis::setRessources(&essen, &wasser);


	Zufallsgenerator();

	SetEvents::checkdate(date->getCalculatable());
	Ereignis::newevent();
	Datum::setWorldDate(date);
	End::init(&window, &music, &txt, date);
	while (window.isOpen()) {

		while (window.pollEvent(ev)) {
			if (ev.Closed or ev.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (EndCheck(&essen, &wasser)) {

			EndLose(&window, &music, &txt, date);
		}
		SetEvents::checkdate(date->getCalculatable());


		if (!paused) {
			if (date->getAdder() > 0) {				//Ein neuer Tag bricht an
				paused = true;
				wasser.addmenge(-1 * Person::getPresentCharactarAmount() + 1);
				essen.addmenge(-1 * Person::getPresentCharactarAmount() + 1);
			}


		}


		window.clear();


		hintergrundbase.darstellen(&window);
		zelt.darstellen(&window);
		panzer.darstellen(&window);
		krater.darstellen(&window);
		flak.darstellen(&window);
		bomber.darstellen(&window);

		date->display(&window);
		if (!paused) {
			essen.darstellen(&window);
			wasser.darstellen(&window);
			Person::displayFamily(&window);
			music.lsregler(&window);

			txt.display(&window);
		}
		else {
#
			dayTransmission(&window, &transmissionphase);
			if (transmissionphase > 270) {
				paused = false;
				transmissionphase = 1;

				hintergrundbase.update_hintergrund(&music, &window);
				bomber.update_hintergrund(&music, &window);
				zelt.update_hintergrund(&music, &window);
				panzer.update_hintergrund(&music, &window);
				krater.update_hintergrund(&music, &window);
				flak.update_hintergrund(&music, &window);
			}

		}
		

		window.display();
		music.update();



	}
	return 1;
}

void init() {

	CSVcontrol::loadConfig();
	SetEvents::loadFromFile();
}


void dayTransmission(RenderWindow* window, int* transmissionphase) { 

	Texture bgtxture;
	bgtxture.loadFromFile("ressources/grafics/black.png");
	Sprite cover(bgtxture);
	Datum* tmp = Datum::getDate();
	int multiplier = (*transmissionphase);
	if (*transmissionphase > 255) {
		multiplier = 255;
	}

	//Sprite cover;
	//cover.setColor(Color::Black);
	cover.setPosition(0, 0);
	cover.setColor(Color(255, 255, 255, 255 / (255 / (multiplier))));
	cover.setScale(10, 10);

	*transmissionphase += 1;

	window->draw(cover);

	if (*transmissionphase > 128) {
		Font font;
		font.loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");

		Text ausgabe(tmp->getWT() + ", den " + to_string(tmp->getTag()) + "." + to_string(tmp->getMonat()) + "." + to_string(tmp->getJahr()), font);
		ausgabe.setCharacterSize(40);
		ausgabe.setPosition(sf::Vector2f(425, 720 / 3.0f));

		ausgabe.setLetterSpacing(0.3f);
		ausgabe.setFillColor(Color::White);

		window->draw(ausgabe);
	}
	if (*transmissionphase == 200) {
		tmp->update();
	}


}

