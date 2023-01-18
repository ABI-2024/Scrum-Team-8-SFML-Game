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

void EndLose(RenderWindow* window, Audio* audio, Textausgabe* text) {

	window->clear();
	window->display();

	sleep(seconds(5));

	/*audio->changeSong();*/ //einsetzen "trauriger Musik"

	//hier kann noch ein besonderer screen eingesetzt werden

	text->setBackground("black.png", Color::White);
}

void End(RenderWindow* window, Audio* audio, Textausgabe* text) {


	window->clear();
	window->display();


	sleep(seconds(0));


	audio->changeSong("ressources/audio/amerika.wav"); //einsetzen von Musik, die den amerikanischen Sieg vermitte
	audio->update();

	text->setBackground("black.png", Color::White);
}