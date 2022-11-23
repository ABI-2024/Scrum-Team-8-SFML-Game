#include "stdafx.h"
#include <random>
#define maxsongs 1

using namespace sf;
using namespace std;


int main() {
	Textausgabe txtausgabe;
	Datum date(1, 1, 1999, 1);
	bool g = true, f = true;
	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(30);
	int counter = 0;

	Ressource wasser("Wasser", 20); //initialisierung von Wasser - NICHT ÄNDERN!
	Ressource essen("Essen", 1); //initialisierung von Essen - NICHT ÄNDERN!


	Music hintergrundmusik;


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



		//Music checker
		if (hintergrundmusik.getStatus() != Music::Playing) {
			hintergrundmusik.stop();

			std::random_device rd; // obtain a random number from hardware
			std::mt19937 gen(rd()); // seed the generator
			std::uniform_int_distribution<> distr(1, maxsongs); // define the range


			if (!hintergrundmusik.openFromFile("ressources/audio/music" + to_string(distr(gen)) + ".wav")) {
				return -1;
			}
			hintergrundmusik.play();
		}
	}
}