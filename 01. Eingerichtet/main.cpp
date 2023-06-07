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

using namespace sf;
using namespace std;

int rando(int a, int b);

void init();


void Zufallsgenerator();														//Einsetzen der Warteschlange
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
	std::cout << "should: " << CSVcontrol::getEventStart(1) << " with : " << CSVcontrol::getEventStart(1) + CSVcontrol::getEventAmount(1) - 1 << endl;

	Warteschlange::addQueue(0);


	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(160);

	hintergrund hintergrundbase("background", 1);
	hintergrund specialeffect("default", 2);

	Ressource wasser("Wasser", 20); //initialisierung von Wasser - NICHT ÄNDERN!

	Ressource essen("Essen", 10); //initialisierung von Essen - NICHT ÄNDERN!

	Person::loadChars();
	sf::Event ev;


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
				wasser.addmenge(-1 * Person::getPresentCharactarAmount());
				essen.addmenge(-1 * Person::getPresentCharactarAmount());
			}

			
		}


		window.clear();

		hintergrundbase.update_hintergrund(&music);
		specialeffect.update_hintergrund(&music);
		hintergrundbase.darstellen(&window);
		specialeffect.darstellen(&window);

		window.draw(background);
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

	if(*transmissionphase > 128) {
		Font font;
		font.loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");

		Text ausgabe(tmp->getWT() + ", den " + to_string(tmp->getTag()) + "." + to_string(tmp->getMonat()) + "." + to_string(tmp->getJahr()), font);
		ausgabe.setCharacterSize(40);
		ausgabe.setPosition(sf::Vector2f(425, 720 / 3.0f));

		ausgabe.setLetterSpacing(0.3f);
		ausgabe.setFillColor(Color::White);

		window->draw(ausgabe);
	}
	if (*transmissionphase == 360) {
		tmp->update();
	}

}

