#include "Audio.h"
#include <random>

using namespace sf;

#define maxsongs 3		//maximale Anzahl an Liedern

Audio::Audio() {		//Standardkonstruktor
	music = new Music();
	inChange = false;
	last = 0;
	//intensity = 1;
	vlmwum = 25.f;
	vlm = 1;
	changeFile = "leer";
}

Audio::~Audio() {
	delete music;
}

Music* Audio::getMusicObject() {		//eine r�ckgabe des music-pointers, die in der Regel nicht ben�tigt werden sollte
	return music;
}
void Audio::update() {
	if (!inChange) {		//schaut ob eine Song�nderung aktuell stattfindet, wenn nicht wird das Radio laufen gelassen
		this->songRadio();
	}
	else {					//verringert die Lautst�rke um einen flie�enderes Gef�hl bei dem �bergang zu gew�hrleisten
		if (vlm < 12) {
			vlmwum = music->getVolume() * vlm / (vlm + 0.15f);		//wird jedes mal um 15% verringert, d.h. erst 15%, dann 30% etc von der ausgangslautst�rke
			vlm += 0.15f;

		}
		else {				//wenn es bei 1200% Reduktion angekommen ist, wird die Lautst�rke zur�ckgesetzt und der neue Song gestartet
			if (!music->openFromFile(changeFile)) {
				cout << "Fehler >> Audiodatei nicht vorhanden\n";
				return;
			}
			inChange = false;
			changeFile = "leer";
			vlmwum = music->getVolume() * vlm;
			vlm = 1;
			music->play();
		}
	}
}
void Audio::changeSong(string filename) {	//initiiert die �nderung des Liedes zu dem �bergebenen Lied
	inChange = true;						//um Eventspezifische Musik zu erm�glichen
	changeFile = filename;
}
void Audio::songRadio() {			//setzt einen Zuf�lligen Song als n�chstes, solange keiner spielt
	//Music checker
	if (music->getStatus() != Music::Playing) {
		music->stop();
		int tmp;
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(1, maxsongs); // define the range

		tmp = distr(gen);
		if (tmp != last) {
			if (!music->openFromFile("ressources/audio/music" + to_string(tmp) + ".ogg")) {
				return;
			}
			last = tmp;
			music->play();
		}
	}
}
void Audio::skipSong() {			//�berspringt das aktuelle Lied und startet ein neues auf Basis des Radios
	music->stop();					//Funtioniert, da die songRadio - Methode nach einem "Playing" Status sucht,
}									//hier ist jedoch nur ein stop vorhanden

//void Audio::setIntensity(int iIntensity) {
//	intensity = iIntensity;
//	last = 0;
//	this->nextSong();
//}
void Audio::setVolume(float volume) { //volume ist der multiplikator der Lautst�rke. d.h. 1 == 100% der std. Lautst�rke -> max = 400% / 4

	vlmwum =25 * volume*this->volume;
	return;
}

void Audio::lsregler(RenderWindow* window) {
	int mousex = window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x;
	int mousey = window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y;

	Sprite bar;
	Texture bar2;
	bar2.loadFromFile("ressources/grafics/lsbar.png");
	bar.setTexture(bar2);
	Sprite pin;
	Texture pin2;
	pin2.loadFromFile("ressources/grafics/lspin.png");
	pin.setTexture(pin2);
	bar.setPosition(1100, 20);
	bar.setScale(5, 5);
	pin.setPosition(pinx, piny);
	pin.setScale(4, 4);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		if ((mousey < 35   and mousey > 15 and mousex < 1200 and mousex > 1100)or mousepressed == true) {
			if (mousex < 1100) mousex = 1100;
			if (mousex > 1200) mousex = 1200;
			volume = (mousex - 1100.f) / 25;
			cout << volume << endl;
			pinx = mousex - 10;
			mousepressed = true;
		}

	}
	else { mousepressed = false; }
	this->music->setVolume(vlmwum * volume);
	window->draw(bar);
	window->draw(pin);

}