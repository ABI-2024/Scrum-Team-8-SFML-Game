#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Audio.h"
#include "Datum.h"
#include "Ressource.h"
#include "Textausgabe.h"

string EndCheck(Ressource essen, Ressource wasser) {
	if (essen.getmenge() < 0) { //prüfen, ob Nahrung alle ist
		return "Nahrung";		 // ist dies der Fall wird Nahrung bzw. Wasser zurückgegeben
	}

	else if (wasser.getmenge() < 0) { //prüfen, ob Wasser alle ist
		return "Wasser";
	}

	else {						//falls alles in Ordnung ist
		return "ok";
	}
}

void EndLose(RenderWindow* window, Audio* audio) {

	int counter = 0;

	window->clear();
	window->display();



	while (counter < 90) { //3 sekündiger Blackscreen
		counter++;
	}

	//audio->changeSong("music1.wav"); //einsetzen "trauriger Musik"

	////hier kann noch ein besonderer screen eingesetzt werden
}

void End(RenderWindow* window, Audio* audio) {

	int counter = 0;

	window->clear();
	window->display();



	while (counter < 90) {	//3 sekündiger Blackscreen
		counter++;
	}

	/*audio->changeSong("amerika.wav");*/ //einsetzen von Musik, die den amerikanischen Sieg vermitteln

		//hier kann noch ein besonderer screen eingesetzt werden
}