#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class hintergrund
{
private:
	string name;
	Sprite popup;
	Texture bild;
	int current;

public:
	hintergrund(string name);
	~hintergrund();

	void newimage(string name); //setzten eines neuen Bildes
	string getname();

	void darstellen(RenderWindow* window); //darstellung des Bildes

	void update_hintergrund();	//aktualisierung des Hintergrunds
};

