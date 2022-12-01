#include "Datum.h"
#include "stdafx.h"

using namespace std;
using namespace sf;
Datum::Datum() {
	tag = -1;
	monat = -1;
	jahr = -1;
	wtid = -1;
	adder = 0;
	this->updateWochentag();
}
Datum::Datum(int itag, int imonat, int ijahr, int iwtid) {		//Parameterkonstruktor mit allen Werten umgetragen in das Objekt
	tag = itag;
	monat = imonat;
	jahr = ijahr;
	wtid = iwtid % 7;
	adder = 0;
	this->updateWochentag();		//Ruft die funktion auf um den Wochentag aufgrund des wtid (wochentagindex) zu aktualisieren, welcher leichter zu verändern ist als ein string
}
Datum::~Datum() {
	return;
}

void Datum::add(int adder) {		//schreibt die Anzahl der Tage in den adder, ohne diese direkt hinzuzufügen, um das Datum erst nach Ende eines Ereignisses aktualisieren zu können, falls nötig
	this->adder += adder;
	return;
}
void Datum::update() {				//verrechnet den adder mit dem effektiven Datum und überträgt die Tage auch in Monate und Jahre
	wtid = (wtid + adder) % 7;
	this->updateWochentag();
	tag += adder;
	adder = 0;
	bool done = false;
	while (!done) {
		switch (monat)
		{
		case 1:
			if (tag > 31) {
				tag -= 31;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 2:
			if (tag > 28) {
				tag -= 28;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 3:
			if (tag > 31) {
				tag -= 31;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 4:
			if (tag > 30) {
				tag -= 30;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 5:
			if (tag > 31) {
				tag -= 31;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 6:
			if (tag > 30) {
				tag -= 30;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 7:
			if (tag > 31) {
				tag -= 31;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 8:
			if (tag > 31) {
				tag -= 31;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 9:
			if (tag > 30) {
				tag -= 30;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 10:
			if (tag > 31) {
				tag -= 31;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 11:
			if (tag > 30) {
				tag -= 30;
				monat++;
			}
			else {
				done = true;
			}
			break;
		case 12:
			if (tag > 31) {
				tag -= 31;
				monat++;
			}
			else {
				done = true;
			}
			break;
		default:
			monat -= 12;
			jahr++;
			break;
		}
	}
}

string Datum::getWT() {
	return wochentag;
}
int Datum::getJahr() {
	return jahr;
}
int Datum::getMonat() {
	return monat;
}
int Datum::getTag() {
	return tag;
}

void Datum::display(sf::RenderWindow* window) {		//Zeigt das Datum mit Wochentag in der Mitte am oberen Bildschirmrand an
	
	Font font;
	font.loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");

	Text ausgabe(wochentag + ", den " + to_string(tag) + "." + to_string(monat) + "." + to_string(jahr), font);
	ausgabe.setCharacterSize(20);
	ausgabe.setLetterSpacing(0.3f);
	ausgabe.setFillColor(Color(0, 0, 0, 255));
	ausgabe.setPosition(500, 15);

	window->draw(ausgabe);
}

void Datum::updateWochentag() {		//verrechnet die wtid (WochentagID) und wandelt den wochentag zu dem passenden um
	switch (wtid)
	{
	case 1:
		wochentag = "Montag";
		break;
	case 2:
		wochentag = "Dienstag";
		break;
	case 3:
		wochentag = "Mittwoch";
		break;
	case 4:
		wochentag = "Donnerstag";
		break;
	case 5:
		wochentag = "Freitag";
		break;
	case 6:
		wochentag = "Samstag";
		break;
	case 0:
		wochentag = "Sonntag";
		break;
	default:
		wochentag = "Framstag";
		break;
	}
}