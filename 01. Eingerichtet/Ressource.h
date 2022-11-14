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
	float menge;

public:

	~Ressource();					//Destruktor und Konstruktor
	Ressource(string, float);
	float getmenge();				//Get und Set Methoden
	string getname();
	void setname(string);
	void setmenge(float);
	void addmenge(float);			//Zum Ändern der Menge
	void darstellen(RenderWindow*); // Ausgabe der Werte in der oberen linken Ecke

};

