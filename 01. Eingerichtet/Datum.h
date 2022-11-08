#pragma once
#include "stdafx.h"

using namespace std;
using namespace sf;

class Datum
{
private:
	int tag;
	int monat;
	int jahr;
	int adder;
	int wtid;
	string wochentag;

public:
	Datum();
	Datum(int, int, int, int);
	~Datum();
	void display(sf::RenderWindow*);
	void add(int);
	void update();
	void updateWochentag();
	string getWT();
	int getJahr();
	int getMonat();
	int getTag();
};

