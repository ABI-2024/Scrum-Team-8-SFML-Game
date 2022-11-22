#pragma once

#include "stdafx.h"

using namespace std;
using namespace sf;


class Ressource
{
private:
	static int typc;				//Attribute der Klasse
	int typ;
	string name;
	int menge;

public:

	~Ressource();					//Destruktor und Konstruktor
	Ressource(string, int);
	int getmenge();				//Get und Set Methoden
	string getname();
	void setname(string);
	void setmenge(int);
	void addmenge(int);			//Zum Ändern der Menge
	void darstellen(RenderWindow*); // Ausgabe der Werte in der oberen linken Ecke

};

