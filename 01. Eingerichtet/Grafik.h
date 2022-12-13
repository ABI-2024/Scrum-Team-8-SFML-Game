#pragma once
#include "stdafx.h"
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

	void newimage(string name);
	string getname();

	void darstellen(RenderWindow* window);
};

