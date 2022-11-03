#pragma once
#include "stdafx.h"
using namespace std;
using namespace sf;

class Textausgabe
{
private:
	string* text;		//Die Texte, die ausgegeben werden sollen als array in Zeilen unterteilt
	int ausgeg;			//ein int counter f�r die Anzahl an ausgegebenen Zeichen
	int tics;			//ein int counter, der die Tics zwischen der ausgabe regelt und die 
						//Ausgabegeschwindigkeit indirekt regelt
	int strings;		//Anzahl der Strings im Array
	
public:
	Textausgabe();
	~Textausgabe();
	void darstellen(RenderWindow*);		//Eine Methode, welche regul�r am Ende der main aufgerufen werden 
											//soll und wenn Text vorhanden ist, diesen teilweise ausgeben soll
	void einlesen(std::string*, int);				//Eine M�glichkeit den auszugebenen String zu setzen
	

};

