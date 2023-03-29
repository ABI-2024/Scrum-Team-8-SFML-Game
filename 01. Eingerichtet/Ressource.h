#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


class Ressource
{
private:
	static int typc;				//Attribute der Klasse
	int typ;
	string name;					//interner Name der Ressource und ebenfalls der Name der zugehörigen Grafik
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

