#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Audio.h"
#include "Datum.h"
#include "Ressource.h"

string EndCheck(Ressource essen, Ressource wasser) {
	if (essen.getmenge() <= 0) { //prüfen, ob Nahrung alle ist
		return "Nahrung";		 // ist dies der Fall wird Nahrung bzw. Wasser zurückgegeben
	}

	else if (wasser.getmenge() <= 0) { //prüfen, ob Wasser alle ist
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