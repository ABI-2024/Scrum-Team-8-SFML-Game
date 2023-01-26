#include "stdafx.h"


using namespace sf;
using namespace std;

string EndCheck(Ressource essen, Ressource wasser);								//Überprüfung zum Gameover
void EndLose(RenderWindow*, Audio*, Textausgabe*, Datum*);										//Trigger vom Endscreen bei Niederlage
void End(RenderWindow*, Audio*, Textausgabe*);											//Trigger vom Normalem Endscreen

int main() {
	
	Texture bgtxture;
	bgtxture.loadFromFile("ressources/grafics/background.png");
	Sprite background(bgtxture);
	
	Datum date(1, 1, 1999, 1);

	bool g = true, f = true;

	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(30);

	int counter = 0;


	Ressource wasser("Wasser", 20); //initialisierung von Wasser - NICHT ÄNDERN!
	Ressource essen("Essen", 1); //initialisierung von Essen - NICHT ÄNDERN!
	Textausgabe txt;
	Grafik popup("ses");
	Audio music;


	//txtausgabe.setResult(100, 200, 300);
	while (window.isOpen()) {
		

		date.update();

		counter++;
		window.clear();
		window.draw(background);
		date.display(&window);
		essen.darstellen(&window);
		wasser.darstellen(&window);


		if (!txt.display(&window)) {
			txt.einlesen(Ereignis::newevent(0));
			date.add(1);
		}
		//if (Textausgabe::display(&window)) {	//temporäre aufruf der neuen events
		//	date.add(1);

		//	
		//	Ereignis::newevent(0);

		//}

		//popup.darstellen(&window);

		window.display();


		music.update();

	}
}