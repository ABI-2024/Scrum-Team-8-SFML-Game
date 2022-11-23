#include "stdafx.h"

using namespace sf;
using namespace std;


int main() {
	Textausgabe txtausgabe;
	Datum date(1, 1, 1999, 1);
	bool g = true, f = true;
	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(30);
	int counter = 0;
	Ressource essen("Essen", 1); //initialisierung von Essen - NICHT ÄNDERN!
	Ressource wasser("Wasser", 20); //initialisierung von Wasser - NICHT ÄNDERN!
	txtausgabe.setResult(100, 200, 300);
	while (window.isOpen()) {

		if (essen.getmenge() == 99) {
			g = false;
		}
		else if (essen.getmenge() == 1) {
			g = true;
		}
		if (wasser.getmenge() == 99) {
			f = true;
		}
		else if (wasser.getmenge() == 1) {
			f = false;
		}
		if (f) {
			wasser.addmenge(-1);
		}
		else {
			wasser.addmenge(1);
		}
		if (g) {
			essen.addmenge(1);
		}
		else {
			essen.addmenge(-1);
		}
		if (counter >= 20) {
			date.add(1);
			date.update();
			counter = 0;
		}
		counter++;
		window.clear();

		date.display(&window);
		essen.darstellen(&window);
		wasser.darstellen(&window);
		if (!txtausgabe.display(&window)) {
			txtausgabe.einlesen(newevent());
			
		}

		window.display();


	}
}