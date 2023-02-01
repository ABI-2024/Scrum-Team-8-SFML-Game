#include "stdafx.h"
#include "Warteschlange.h"
#include "CSVcontrol.h"

using namespace sf;
using namespace std;

void init();

int main() {
	Texture bgtxture;
	bgtxture.loadFromFile("ressources/grafics/background.png");
	Sprite background(bgtxture);
	init();
	Datum date(11, 9, 2001, 1);

	
	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(30);

	Ressource wasser("Wasser", 20); //initialisierung von Wasser - NICHT ÄNDERN!
	Ressource essen("Essen", 1); //initialisierung von Essen - NICHT ÄNDERN!
	Audio music;
	sf::Event ev;
	//txtausgabe.setResult(100, 200, 300);
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.Closed) {
				window.close();
			}
		}

		date.update();
		window.clear();
		window.draw(background);
		date.display(&window);
		essen.darstellen(&window);
		wasser.darstellen(&window);


		Textausgabe::display(&window);



		window.display();
		music.update();

	}
}

void init() {
	CSVcontrol::loadConfig();
	Textausgabe::init();
	Ereignis::newevent();
}