#pragma once
#include "stdafx.h"
using namespace std;
using namespace sf;

class Textausgabe
{
private:
	string text;		//Die Texte, die ausgegeben werden sollen als  in Zeilen unterteilt
	int ausgeg;			//ein int counter für die Anzahl an ausgegebenen Zeichen
	int tics;			//ein int counter, der die Tics zwischen der ausgabe regelt und die 
						//Ausgabegeschwindigkeit indirekt regelt
	int from;
	bool cont;
	int maxlines;
	Text ausgabe;
public:
	Textausgabe();
	~Textausgabe();
	bool darstellen(RenderWindow*);		//Eine Methode, welche regulär am Ende der main aufgerufen werden 
											//soll und wenn Text vorhanden ist, diesen teilweise ausgeben soll
	void einlesen(std::string);				//Eine Möglichkeit den auszugebenen String zu setzen
	

};

