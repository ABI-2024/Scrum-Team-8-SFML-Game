#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class Grafik
{
private:
	string name;
	Sprite popup;
	Texture bild;

public:
	Grafik(string name);
	~Grafik();

	void newimage(string name); //setzten eines neuen Bildes
	string getname();

	void darstellen(RenderWindow* window); //darstellung des Bildes
};

