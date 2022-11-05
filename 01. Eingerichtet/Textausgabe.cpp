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

}


void Textausgabe::einlesen(std::string insert) {
	text = "";
	for (int i = 0; i < insert.length(); i++) {

		if (insert[i] == '§') {
			text = text + "\n";
		}
		else {
			text = text + insert[i];

		}
	}
	/*
	text = new string[amount];
	for (int i = 0; i < amount; i++) {
		text[i] = insert[i];
	}
	*/
}

bool Textausgabe::darstellen(RenderWindow* window) {		//Ausgabe des Textfeldes samt Texthintergrund
	if (text == "leer") {
		return false;
	}
	else {							//Muss noch die ausgabe regeln mit mehr als 5 Zeilen und dass 5 Zeilen ausgegeben werden

		Texture txtfeldbg;
		txtfeldbg.loadFromFile("ressources/grafics/textfeld.png");
		Sprite txtbg(txtfeldbg);
		txtbg.setScale(1, 1);
		txtbg.setPosition(5, 475);
		Font font;
		font.loadFromFile("ressources/fonts/arcadeclassic.ttf");
		ausgabe = Text("", font);
		ausgabe.setFillColor(Color(100, 50, 30, 255));
		ausgabe.setPosition(40, 500);

		if (tics >= 1 && cont == true) {

			ausgeg++;
			tics = 0;
			cout << "\npremax - ";
			if (text[ausgeg] == '\n') {

				maxlines++;
				cout << " - maxlines: " << maxlines;
			}
		}
		if (ausgeg >= text.length()) {
			cout << "F1";	//Ende der Ausgabe

			ausgabe.setString(text.substr(from, ausgeg - from));
			cont = false;
			
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				
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
		else if (maxlines != 6) {

			ausgabe.setString(text.substr(from, ausgeg - from));
			cout << text.substr(from, ausgeg - from);
			if (tics == 0) cout << "\nfrom: " << from << "  to: " << ausgeg;
		}
		else {
			cout << "F5";
			cont = false;
			ausgabe.setString(text.substr(from, ausgeg - from));
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				maxlines = 0;

				from = ausgeg + 1;
				ausgeg++;
				cont = true;
			}

		}

		if (cont == true) {
			tics++;
		}
		window->draw(txtbg);
		window->draw(ausgabe);
		return true;
	}

}


Textausgabe::~Textausgabe() {
	return;
}