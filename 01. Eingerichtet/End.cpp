#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Audio.h"
#include "Datum.h"
#include "Ressource.h"

string EndCheck(Ressource essen, Ressource wasser) {
	if (essen.getmenge() <= 0) { //pr�fen, ob Nahrung alle ist
		return "Nahrung";		 // ist dies der Fall wird Nahrung bzw. Wasser zur�ckgegeben
	}

	else if (wasser.getmenge() <= 0) { //pr�fen, ob Wasser alle ist
		return "Wasser";
	}

	else {
		return "ok";
	}
}

void EndLose(RenderWindow* window, Audio* audio) {

	int counter = 0;

	window->clear();
	window->display();



	while (counter < 300) {
		counter++;
	}

}

void End(RenderWindow* window, Audio* audio) {

}