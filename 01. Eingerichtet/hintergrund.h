#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Audio.h"

using namespace sf;
using namespace std;

class hintergrund
{
private:
	string name;
	int id;
	Sprite popup;
	Texture bild;
	int current;

	SoundBuffer buffer;
	Sound sound;

public:
	hintergrund(string name, int id);
	~hintergrund();

	void newimage(string name); //setzten eines neuen Bildes name gleich name der bild datei
	string getname();

	void darstellen(RenderWindow* window); //darstellung des Bildes. Das Fenster aus der main wird übergeben

	void update_hintergrund(Audio* music, RenderWindow* window);	//aktualisierung des Hintergrunds. Music objekt aus der main wird übergeben
};

