#include "Audio.h"
#include <random>

#define maxsongs 3		//maximale Anzahl an Liedern

Audio::Audio() {		//Standardkonstruktor
	music = new Music();
	inChange = false;
	last = 0;
	//intensity = 1;
	music->setVolume(25.f);
	vlm = 1;
	changeFile = "leer";
}

Audio::~Audio() {
	delete music;
}

Music* Audio::getMusicObject() {		//eine rückgabe des music-pointers, die in der Regel nicht benötigt werden sollte
	return music;
}
void Audio::update() {
	if (!inChange) {		//schaut ob eine Songänderung aktuell stattfindet, wenn nicht wird das Radio laufen gelassen
		this->songRadio();
	}
	else {					//verringert die Lautstärke um einen fließenderes Gefühl bei dem Übergang zu gewährleisten
		if (vlm < 12) {
			music->setVolume(music->getVolume() * vlm / (vlm + 0.15f));		//wird jedes mal um 15% verringert, d.h. erst 15%, dann 30% etc von der ausgangslautstärke
			vlm += 0.15f;

		}
		else {				//wenn es bei 1200% Reduktion angekommen ist, wird die Lautstärke zurückgesetzt und der neue Song gestartet
			if (!music->openFromFile(changeFile)) {
				cout << "Fehler >> Audiodatei nicht vorhanden\n";
				return;
			}
			inChange = false;
			changeFile = "leer";
			music->setVolume(music->getVolume() * vlm);
			vlm = 1;
			music->play();
		}
	}
}
void Audio::changeSong(string filename) {	//initiiert die Änderung des Liedes zu dem übergebenen Lied
	inChange = true;						//um Eventspezifische Musik zu ermöglichen
	changeFile = filename;
}
void Audio::songRadio() {			//setzt einen Zufälligen Song als nächstes, solange keiner spielt
	//Music checker
	if (music->getStatus() != Music::Playing) {
		music->stop();
		int tmp;
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(1, maxsongs); // define the range

		tmp = distr(gen);
		if (tmp != last) {
			if (!music->openFromFile("ressources/audio/music" + to_string(tmp) + ".wav")) {
				return;
			}
			last = tmp;
			music->play();
		}
	}
}
void Audio::skipSong() {			//Überspringt das aktuelle Lied und startet ein neues auf Basis des Radios
	music->stop();					//Funtioniert, da die songRadio - Methode nach einem "Playing" Status sucht,
}									//hier ist jedoch nur ein stop vorhanden

//void Audio::setIntensity(int iIntensity) {
//	intensity = iIntensity;
//	last = 0;
//	this->nextSong();
//}
void Audio::setVolume(float volume) { //volume ist der multiplikator der Lautstärke. d.h. 1 == 100% der std. Lautstärke -> max = 400% / 4

	this->music->setVolume(25 * volume);
	return;
}