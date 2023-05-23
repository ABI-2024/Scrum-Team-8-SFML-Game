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

using namespace sf;
using namespace std;


void init();

bool EndCheck(Ressource* essen, Ressource* wasser);								//Überprüfung zum Gameover
void EndLose(RenderWindow*, Audio*, Textausgabe*, Datum*);										//Trigger vom Endscreen bei Niederlage
void End(RenderWindow*, Audio*, Textausgabe*);											//Trigger vom Normalem Endscreen
void dayTransmission(RenderWindow*, int* transmissionphase);

int main() {
	init();
	int transmissionphase = 1.f;
	bool paused = false;
	Texture bgtxture;
	bgtxture.loadFromFile("ressources/grafics/background.png");
	Sprite background(bgtxture);
	Datum* date = new Datum(13, 6, 1936, 1);


	Warteschlange::addQueue(0);

	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(160);

	Ressource wasser("Wasser", 20); //initialisierung von Wasser - NICHT ÄNDERN!
	Ressource essen("Essen", 10); //initialisierung von Essen - NICHT ÄNDERN!

	Person::loadChars();
	sf::Event ev;

	Textausgabe txt;
	Audio music;
	int counter = 0;
	Ereignis::setTxt(&txt);
	Ereignis::setRessources(&essen, &wasser);
	Ereignis::newevent();
	Datum::setWorldDate(date);
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.Closed) {
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
				wasser.addmenge(-1 * date->getAdder());
				essen.addmenge(-1 * date->getAdder());
			}

			
		}
		window.clear();
		window.draw(background);
		date->display(&window);
		if (!paused) {
			essen.darstellen(&window);
			wasser.darstellen(&window);
			Person::displayFamily(&window);

			txt.display(&window);
		}
		else {
#
			dayTransmission(&window, &transmissionphase);
			if (transmissionphase > 600) {
				paused = false;
				transmissionphase = 1;
			}

		}
		window.display();
		music.update();



	}
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

	if(*transmissionphase > 255) {
		Font font;
		font.loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");

		Text ausgabe(tmp->getWT() + ", den " + to_string(tmp->getTag()) + "." + to_string(tmp->getMonat()) + "." + to_string(tmp->getJahr()), font);
		ausgabe.setCharacterSize(20);
		ausgabe.setLetterSpacing(0.3f);
		ausgabe.setFillColor(Color::White);
		ausgabe.setPosition(500, 15);

		window->draw(ausgabe);
	}
	if (*transmissionphase == 360) {
		tmp->update();
	}

}