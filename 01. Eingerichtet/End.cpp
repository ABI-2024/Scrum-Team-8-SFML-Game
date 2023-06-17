#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Audio.h"
#include "Datum.h"
#include "Ressource.h"
#include "Textausgabe.h"
#include "Warteschlange.h"
#include "CSVcontrol.h"
#include "End.h"

RenderWindow* End::window;
Audio* End::audio;
Textausgabe* End::text;
Datum* End::datum;

void End::init(RenderWindow* iwindow, Audio* iaudio, Textausgabe* itext, Datum* idatum) {
	window = iwindow;
	audio = iaudio;
	text = itext;
	datum = idatum;
}

bool EndCheck(Ressource* essen, Ressource* wasser) { //schaut nach Hungertod
	if (essen->getmenge() < 0) { //prüfen, ob Nahrung alle ist
		return true;		 // ist dies der Fall wird Nahrung bzw. Wasser zurückgegeben
	}

	else if (wasser->getmenge() < 0) { //prüfen, ob Wasser alle ist
		return true;
	}

	else {						//falls alles in Ordnung ist
		return false;
	}
}

void EndLose(RenderWindow* window, Audio* audio, Textausgabe* text, Datum* datum) { //Fenster beim Hungertod

	window->clear();
	window->display();

	sleep(seconds(1)); // blackscreen 2 sek


	audio->changeSong("ressources/audio/amerika.ogg"); //einsetzen von Musik. Trauer
	sleep(seconds(1)); // blackscreen 5 sek

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
		monat = "März";
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

	default:
		monat = "Fehler";
		break;
	}

	string label = to_string(datum->getTag()) + ". " + monat + " " + to_string(datum->getJahr()); //ausgabe des Datum

	Text end(label, *font);
	end.setCharacterSize(30);

	FloatRect ftext = end.getLocalBounds();    //positionierung des Textes in der Mitte
	end.setOrigin(ftext.width / 2, ftext.height / 2);
	end.setPosition(sf::Vector2f(1280 / 2.0f, 720 / 3.0f));

	//hier event aufrufen für credits....
	//Warteschlange::forceNext(CSVcontrol::getEventStart(5) + CSVcontrol::getEventAmount(5));
	text->clear();
	Warteschlange::forceNext(2 +CSVcontrol::getEventStart(5)  + CSVcontrol::getEventAmount(5));
	sf::Event ev;
	Ereignis::newevent();
	while (window->isOpen() ) {
		while (window->pollEvent(ev)) {
			if (ev.Closed or ev.type == sf::Event::Closed) {
				window->close();
			}
		}
		audio->update();
		window->clear();
		window->draw(end);
		text->display(window);
		window->display();
	}

}


void End::endwin() {

	window->clear();
	window->display();

	

	sleep(seconds(1)); // blackscreen 5 sek
	Sprite background;
	Texture backgroundtexture;
	backgroundtexture.loadFromFile("ressources/grafics/japan.png");
	background.setTexture(backgroundtexture);
	background.setPosition(0, -110);
	background.setScale(2.5, 2);
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
		monat = "März";
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

	default:
		monat = "Fehler";
		break;
	}

	string label = to_string(datum->getTag()) + ". " + monat + " " + to_string(datum->getJahr()); //ausgabe des Datum

	Text end(label, *font);
	end.setCharacterSize(30);

	FloatRect ftext = end.getLocalBounds();    //positionierung des Textes in der Mitte
	end.setOrigin(ftext.width / 2, ftext.height / 2);
	end.setPosition(sf::Vector2f(1280 / 2.0f, 720 / 3.0f));

	//hier event aufrufen für credits....
	//Warteschlange::forceNext(CSVcontrol::getEventStart(5) + CSVcontrol::getEventAmount(5));
	text->clear();
	Warteschlange::forceNext(3 + CSVcontrol::getEventStart(5) + CSVcontrol::getEventAmount(5));
	sf::Event ev;
	Ereignis::newevent();
	while (window->isOpen() ) {
		while (window->pollEvent(ev)) {
			if (ev.Closed or ev.type == sf::Event::Closed) {
				window->close();
			}
		}

		audio->update();
		window->clear();
		window->draw(background);
		window->draw(end);
		text->display(window);
		window->display();
	}

}

void End::alliesWin() {

	window->clear();
	window->display();

	audio->changeSong("ressources/audio/amerika.ogg"); //einsetzen von Musik. Trauer


	sleep(seconds(1)); // blackscreen 5 sek
	Sprite background;
	Texture backgroundtexture;
	backgroundtexture.loadFromFile("ressources/grafics/america.png");
	background.setTexture(backgroundtexture);
	background.setPosition(0, -110);
	background.setScale(2.5, 2);
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
		monat = "März";
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

	default:
		monat = "Fehler";
		break;
	}

	string label = to_string(datum->getTag()) + ". " + monat + " " + to_string(datum->getJahr()); //ausgabe des Datum

	Text end(label, *font);
	end.setCharacterSize(30);

	FloatRect ftext = end.getLocalBounds();    //positionierung des Textes in der Mitte
	end.setOrigin(ftext.width / 2, ftext.height / 2);
	end.setPosition(sf::Vector2f(1280 / 2.0f, 720 / 2.5f));
	end.setFillColor(Color::Black);
	end.setOutlineColor(Color::White);
	//hier event aufrufen für credits....
	//Warteschlange::forceNext(CSVcontrol::getEventStart(5) + CSVcontrol::getEventAmount(5));
	text->clear();
	Warteschlange::forceNext(4 + CSVcontrol::getEventStart(5) + CSVcontrol::getEventAmount(5));
	sf::Event ev;
	Ereignis::newevent();
	while (window->isOpen()) {
		while (window->pollEvent(ev)) {
			if (ev.Closed or ev.type == sf::Event::Closed) {
				window->close();
			}
		}

		audio->update();
		window->clear();
		window->draw(background);
		window->draw(end);
		text->display(window);
		window->display();
	}

}

void End::close() {
	exit(1);
}

