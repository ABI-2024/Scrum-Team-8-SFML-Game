#include "Datum.h"


using namespace std;
using namespace sf;
Datum* Datum::date;

Datum::Datum() {
	tag = -1;
	monat = -1;
	jahr = -1;
	wtid = -1;
	adder = 0;
	date = this;
	this->updateWochentag();
}
Datum* Datum::getDate() {
	return date;
}

void Datum::setWorldDate(Datum* idate) {
	date = idate;
}
Datum::Datum(int itag, int imonat, int ijahr, int iwtid) {		//Parameterkonstruktor mit allen Werten umgetragen in das Objekt
	tag = itag;
	monat = imonat;
	jahr = ijahr;
	wtid = iwtid % 7;
	adder = 0;
	calculatable = ((jahr) * 100 + monat) * 100 + tag;
	this->updateWochentag();		//Ruft die funktion auf um den Wochentag aufgrund des wtid (wochentagindex) zu aktualisieren, welcher leichter zu ver�ndern ist als ein string
}
Datum::~Datum() {
	return;
}

void Datum::add(int adder) {		//schreibt die Anzahl der Tage in den adder, ohne diese direkt hinzuzuf�gen, um das Datum erst nach Ende eines Ereignisses aktualisieren zu k�nnen, falls n�tig
	this->adder += adder;
	return;
}
int Datum::getAdder() {
	return adder;
}
void Datum::update() {				//verrechnet den adder mit dem effektiven Datum und �bertr�gt die Tage auch in Monate und Jahre
	wtid = (wtid + adder) % 7;
	this->updateWochentag();
	tag += adder;
	adder = 0;
	bool done = false;
	while (!done) {
		switch (monat)
		{
		case 1:case 3: case 5: case 7: case 8: case 10: case 12:
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

		case 4: case 6: case 9:	case 11:
			if (tag > 30) {
				tag -= 30;
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

	calculatable = ((jahr) * 100 + monat) * 100 + tag;
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

unsigned int Datum::getCalculatable() {
	return this->calculatable;
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