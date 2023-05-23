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

int rando(int a, int b);

void init();

void hintergrund(RenderWindow*);												//Hintergrund und Animationen

void Zufallsgenerator();														//Einsetzen der Warteschlange
bool EndCheck(Ressource* essen, Ressource* wasser);								//Überprüfung zum Gameover
void EndLose(RenderWindow*, Audio*, Textausgabe*, Datum*);										//Trigger vom Endscreen bei Niederlage
void End(RenderWindow*, Audio*, Textausgabe*);											//Trigger vom Normalem Endscreen

int main() {
	init();
	
	Datum date(11, 6, 1934, 1);

	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(30);

	Ressource wasser("Wasser", 20); //initialisierung von Wasser - NICHT ÄNDERN!
	Ressource essen("Essen", 100); //initialisierung von Essen - NICHT ÄNDERN!

	sf::Event ev;
		
	
	Textausgabe txt;
	Audio music;
	int counter = 0;
	Ereignis::setTxt(&txt);
	Ereignis::setRessources(&essen, &wasser);

	Zufallsgenerator();

	
	Ereignis::newevent();


	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.Closed) {
				window.close();
			}
		}

		if (EndCheck(&essen, &wasser)) {

			EndLose(&window, &music, &txt, &date);
		}

		date.update();
		window.clear();

		hintergrund(&window);

		date.display(&window);
		essen.darstellen(&window);
		wasser.darstellen(&window);

		txt.display(&window);

		window.display();
		music.update();



	}
}

void init() {

	CSVcontrol::loadConfig();
	SetEvents::loadFromFile();
}

