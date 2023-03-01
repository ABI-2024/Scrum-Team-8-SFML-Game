#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>


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
	unsigned int calculatable; //eine pure Integer-Version des Datums um leichter Reichnen zu können
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
	unsigned int getCalculatable();
	int getJahr();
	int getMonat();
	int getTag();
};

