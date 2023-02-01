#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Audio.h"
#include "Datum.h"
#include "Ressource.h"
#include "Textausgabe.h"


string EndCheck(Ressource essen, Ressource wasser) {
	if (essen.getmenge() < 0) { //pr�fen, ob Nahrung alle ist
		return "Nahrung";		 // ist dies der Fall wird Nahrung bzw. Wasser zur�ckgegeben
	}

	else if (wasser.getmenge() < 0) { //pr�fen, ob Wasser alle ist
		return "Wasser";
	}

	else {						//falls alles in Ordnung ist
		return "ok";
	}
}

void EndLose(RenderWindow* window, Audio* audio, Textausgabe* text, Datum* datum) {

	window->clear();
	window->display();

	sleep(seconds(5)); // blackscreen 5 sek


	audio->changeSong("ressources/audio/amerika.wav"); //einsetzen von Musik. Trauer

	text->setBackground("black.png", Color::White); //Hintergrund Schwarz setzen

	Font* font = new Font; // laden der Schriftart
	font->loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");

	string monat; //bestimmen des Datums und konvertierung in ausgebbaren Format

	switch (datum->getMonat())
	{
	case 1:
		monat = "Januar";
		break;
	case 2:
		monat = "Februar";
		break;
	case 3:
		monat = "Maerz";
		break;
	case 4:
		monat = "April";
		break;
	case 5:
		monat = "Mai";
		break;
	case 6:
		monat = "Juni";
		break;
	case 7:
		monat = "July";
		break;
	case 8:
		monat = "August";
		break;
	case 9:
		monat = "September";
		break;
	case 10:
		monat = "Oktober";
		break;
	case 11:
		monat = "November";
		break;
	case 12:
		monat = "Dezember";
		break;

	}

	string label = to_string(datum->getTag()) + ". " + monat + " " + to_string(datum->getJahr()); //ausgabe des Datum

	Text end(label, *font);
	end.setCharacterSize(30);

	FloatRect ftext = end.getLocalBounds();    //positionierung des Textes in der Mitte
	end.setOrigin(ftext.width / 2, ftext.height / 2);
	end.setPosition(sf::Vector2f(1280 / 2.0f, 720 / 3.0f));

	//hier event aufrufen f�r credits....


	while (window->isOpen()) {
		audio->update();
		window->draw(end);
		window->display();
	}

}


void End(RenderWindow* window, Audio* audio, Textausgabe* text) {


	window->clear();
	window->display();


	sleep(seconds(5)); //blackscreen 5 sek


	audio->changeSong("ressources/audio/amerika.wav"); //einsetzen von Musik, die den amerikanischen Sieg vermitte
	audio->update();

	text->setBackground("black.png", Color::White); //Hintergrund Schwarz setzen

	Font* font = new Font;
	font->loadFromFile("ressources/fonts/Silkscreen-Regular.ttf"); //laden der Schrift

	Text end("2. September 1945, Pr�fektur Tokyo", *font);
	end.setCharacterSize(30);

	FloatRect ftext = end.getLocalBounds();          // positionierung des Textes in der Mitte
	end.setOrigin(ftext.width / 2, ftext.height / 2);
	end.setPosition(sf::Vector2f(1280 / 2.0f, 720 / 3.0f));


	//hier event aufrufen f�r credits....

	while (window->isOpen()) {
		audio->update();
		window->draw(end);
		window->display();
	}


}