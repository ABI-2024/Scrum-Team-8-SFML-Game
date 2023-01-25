#include "stdafx.h"
#include "Warteschlange.h"

using namespace sf;
using namespace std;


int main() {
	Warteschlange::addQueue(0);
	Texture bgtxture;
	bgtxture.loadFromFile("ressources/grafics/background.png");
	Sprite background(bgtxture);

	Datum date(11, 9, 2001, 1);

	bool g = true, f = true;

	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(30);




	Ressource wasser("Wasser", 20); //initialisierung von Wasser - NICHT ÄNDERN!
	Ressource essen("Essen", 1); //initialisierung von Essen - NICHT ÄNDERN!
	Textausgabe txt;
	Audio music;
	int counter = 0;
	Ereignis::setTxt(&txt);
	Ereignis::setRessources(&essen, &wasser);
	sf::Event ev;
	Ereignis::newevent();
	//txtausgabe.setResult(100, 200, 300);
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.Closed) {
				window.close();
			}
		}

		date.update();

		counter++;
		window.clear();
		window.draw(background);
		date.display(&window);
		essen.darstellen(&window);
		wasser.darstellen(&window);


		if (!txt.display(&window)) {
			date.add(1);
		}



		window.display();
		music.update();

	}
}