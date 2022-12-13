#include "Textausgabe.h"
#include "stdafx.h"

using namespace std;
using namespace sf;

Textausgabe::Textausgabe() {
	text = "leer";
	ausgeg = 0;
	tics = 0;
	cont = true;
	from = 0;
	maxlines = 0;
	exit = char(0);
	txtbackground = "textfeld.png";
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	buffer.loadFromFile("ressources/audio/typesound.wav");
	soundeffect.setBuffer(buffer);
	soundeffect.setVolume(3);
}

void Textausgabe::setBackground(std::string bg) {
	txtbackground = bg;
}

void Textausgabe::setExit(char insert) {					//Der char gibt an, ob ein Einlesen von Antwortmöglichkeiten auf die Ausgabe folgen soll
	exit = insert;										// 0 => es gibt keine Folgeaktion von der Textausgabe extern
}														// 1 => es gibt eine Folgeaktion
														// 2 => die Folgeaktion ist vollständig durchgeführt

void Textausgabe::einlesen(std::string insert) {		//ließt den Text in die Textausgabe ein
	if (insert.length() == 0) {
		text = "leer";
	}
	else {
		text = "";
		for (int i = 0; i < insert.length(); i++) {

			if (insert[i] == '§') {
				text = text + "\n";
			}
			else {
				text = text + insert[i];

			}
		}
	}
}

bool Textausgabe::display(RenderWindow* window) {		//Ausgabe des Textfeldes samt Texthintergrund
	if (text == "leer") {
		return false;
	}
	else {

		Texture txtfeldbg;
		txtfeldbg.loadFromFile("ressources/grafics/" + txtbackground);
		Sprite txtbg(txtfeldbg);
		txtbg.setScale(1, 1);
		txtbg.setPosition(5, 475);
		Font font;
		font.loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");
		Text ausgabe("", font);

		ausgabe.setLetterSpacing(0.5f);
		ausgabe.setFillColor(Color(100, 50, 30, 255));
		ausgabe.setPosition(40, 500);

		if (cont) {
			if (Keyboard::isKeyPressed(Keyboard::Space)) {				//schaut, ob die Leertaste gedrückt ist und skippt, wenn nötig die langsame Textausgabe

				while (ausgeg <= text.length()) {
					if (text[ausgeg] == '\n') {

						maxlines++;
						
						break;
					}
					ausgeg++;
				}
				ausgeg++;
			}
			else {														//Die normale Animation, wenn es keinen schnelldurchlauf gibt
				tics++;
				if (tics >= 1) {

					tics = 0;
					if (text[ausgeg] == '\n') {

						maxlines++;
					}

					ausgeg++;
				}
			}
		}
		if (ausgeg >= text.length()) {	//Ende der Ausgabe

			if (soundeffect.getStatus() == Sound::Playing) {
				soundeffect.pause();
			}

			ausgabe.setString(text.substr(from, ausgeg - from));
			cont = false;
			if (exit == char(1)) {

				this->keyboardInsertion();

			}
			else if (exit == char(0)) {
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {

					ausgabe.setString("");
					text = "leer";
					ausgeg = 0;
					tics = 0;
					cont = true;
					from = 0;
					maxlines = 0;
					return false;
				}
			}
			else {
				exit = char(0);
				ausgabe.setString("");
				text = "leer";
				ausgeg = 0;
				tics = 0;
				cont = true;
				from = 0;
				maxlines = 0;
				return false;
			}

		}
		else if (maxlines != 5) {
			ausgabe.setString(text.substr(from, ausgeg - from));
			if (soundeffect.getStatus() != Sound::Playing) {
				soundeffect.play();
			}

		}
		else {
			if (soundeffect.getStatus() == Sound::Playing) {
				soundeffect.pause();
			}
			cont = false;
			ausgabe.setString(text.substr(from, ausgeg - from));
			if (Keyboard::isKeyPressed(Keyboard::Enter)) {
				maxlines = 0;

				from = ausgeg ;
				cont = true;
			}

		}

		cout << maxlines;
		window->draw(txtbg);
		window->draw(ausgabe);
		return true;
	}

}


Textausgabe::~Textausgabe() {
	return;
}






//Einlesen der Antwortmöglickeiten durch die Tastatur

void Textausgabe::setResult(int a, int b, int c) {
	exit = char(1);
	result[0] = a;
	result[1] = b;
	result[2] = c;
	return;
}

void Textausgabe::keyboardInsertion() {
	if (result[1] != 0) { //schaut ob es nur eine Antwortmöglichkeit / Folge gibt, setzt sonst die einzige mögichkeit direkt die Folge
		if (Keyboard::isKeyPressed(Keyboard::Num1)) {
			int ret = result[0];
			exit = char(2);
			result[0] = 0;
			result[1] = 0;
			result[2] = 0;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Num2)) {
			int ret = result[1];
			exit = char(2);
			result[0] = 0;
			result[1] = 0;
			result[2] = 0;
		}
		else if (result[2] != 0) {
			if (Keyboard::isKeyPressed(Keyboard::Num3)) {
				int ret = result[2];
				exit = char(2);
				result[0] = 0;
				result[1] = 0;
				result[2] = 0;
			}
		}
		else {

			return;
		}
	}
	else {
		int ret = result[0];
		exit = char(0);
	}

	//Aufruf eines set-Events der Zeile ret

}

//Allwertige, vereinfachte Einlesefunktion
// 
//Wenn followup = 0 ist, fällt jedes einlesen von Tastatureingaben und somit jede Folge darauf nicht statt:
//standardinput sollte sein: (<auszugebener Text>, <Zeile des Folgeereignis 1>,<des 2.>, <des 3. ( = 0, wenn es nur 2 gibt)>, <1> (die 1 für eine folgendes Texteinlesen))
void Textausgabe::uniInsertion(string text, int resultA, int resultB, int resultC) {
	this->einlesen(text);
	if (resultA != 0) {

		exit = char(1);
	}
	else {
		exit = char(0);
	}
	result[0] = resultA;
	result[1] = resultB;
	result[2] = resultC;
	return;
}