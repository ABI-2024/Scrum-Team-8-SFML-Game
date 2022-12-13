#include "stdafx.h"


using namespace sf;
using namespace std;


int main() {

	Texture testtxture;
	testtxture.loadFromFile("ressources/grafics/background.png");

	Textausgabe txtausgabe;
	Datum date(1, 1, 1999, 1);

	bool g = true, f = true;

	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(30);

	int counter = 0;


	Ressource wasser("Wasser", 20); //initialisierung von Wasser - NICHT ÄNDERN!
	Ressource essen("Essen", 1); //initialisierung von Essen - NICHT ÄNDERN!

	Audio music;

	//txtausgabe.setResult(100, 200, 300);
	while (window.isOpen()) {


		date.update();

		counter++;
		window.clear();

		date.display(&window);
		essen.darstellen(&window);
		wasser.darstellen(&window);



		if (!txtausgabe.display(&window)) {	//temporäre aufruf der neuen events
			date.add(1);

			txtausgabe.einlesen(newevent());
			essen.addmenge(42);

		}
		else {
			propaganda.darstellen(&window);
		}

		window.display();


		music.update();

	}
}