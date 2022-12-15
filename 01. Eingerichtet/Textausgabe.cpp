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
	done = leave_after_enter;
	txtbackground = "textfeld.png";

	awnser = 0;
	buffer.loadFromFile("ressources/audio/typesound.wav");
	soundeffect.setBuffer(buffer);
	soundeffect.setVolume(3);

	Texture* txtfeldbg = new Texture;
	txtfeldbg->loadFromFile("ressources/grafics/" + txtbackground);
	txtbg = Sprite(*txtfeldbg);
	txtbg.setScale(1, 1);
	txtbg.setPosition(5, 475);
	Font* font = new Font;
	font->loadFromFile("ressources/fonts/Silkscreen-Regular.ttf");
	ausgabe = Text("", *font);

	ausgabe.setLetterSpacing(0.5f);
	ausgabe.setFillColor(Color(100, 50, 30, 255));
	ausgabe.setPosition(40, 500);
}

void Textausgabe::setBackground(std::string bg) {
	txtbackground = bg;
}

void Textausgabe::setExit(leave insert) {					//Der enum gibt an, ob ein Einlesen von Antwortmöglichkeiten auf die Ausgabe folgen soll
	done = insert;										// leave_after_enter => es gibt keine Folgeaktion von der Textausgabe extern
}														// wait_for_input => es gibt eine Folgeaktion
														// leave_immediatly => die Folgeaktion ist vollständig durchgeführt

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
			if (done == wait_for_input) {

				keyboardInsertion();

			}
			else if (done == leave_after_enter) {
				if (Keyboard::isKeyPressed(Keyboard::Enter)) {

					ausgabe.setString("");
					text = "leer";
					ausgeg = 0;
					tics = 0;
					cont = true;
					from = 0;
					maxlines = 0;
					Ereignis::processAntwort(awnser);
					
					return false;
					
				}
			}
			else {
				
				done = leave_after_enter;
				ausgabe.setString("");
				text = "leer";
				ausgeg = 0;
				tics = 0;
				cont = true;
				from = 0;
				maxlines = 0;
				Ereignis::processAntwort(awnser);
				
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

				from = ausgeg;
				cont = true;
			}

		}


		window->draw(txtbg);
		window->draw(ausgabe);
		return true;
	}

}







//Einlesen der Antwortmöglickeiten durch die Tastatur



void Textausgabe::keyboardInsertion() {
	//schaut ob es nur eine Antwortmöglichkeit / Folge gibt, setzt sonst die einzige mögichkeit direkt die Folge
	
	if (Keyboard::isKeyPressed(Keyboard::Num1)) {
		awnser = 1;
		done = leave_immediatly;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Num2)) {
		awnser = 2;
		done = leave_immediatly;
		
	}
	else if (awnser > 2) {
		if (Keyboard::isKeyPressed(Keyboard::Num3)) {
			awnser = 3;
			done = leave_immediatly;
		
		}
	}
	else {
		return;
	}
}



//Allwertige, vereinfachte Einlesefunktion
// 
//Wenn followup = 0 ist, fällt jedes einlesen von Tastatureingaben und somit jede Folge darauf nicht statt:
//standardinput sollte sein: (<auszugebener Text>, <Zeile des Folgeereignis 1>,<des 2.>, <des 3. ( = 0, wenn es nur 2 gibt)>, <1> (die 1 für eine folgendes Texteinlesen))
void Textausgabe::uniInsertion(string text, int awnsers) {
	einlesen(text);
	awnser = awnsers;

	if (awnser == 0 || awnser == 1) {
		done = leave_after_enter;
	}
	else {
		done = wait_for_input;
	}
	return;
}

Textausgabe::~Textausgabe() {

	return;
}