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
	unsigned int calculatable; //eine pure Integer-Version des Datums um leichter Reichnen zu k�nnen
	string wochentag;
	static Datum* date;
public:
	static Datum* getDate();
	static void setWorldDate(Datum* idate);			//globales Datum definieren
	Datum();
	Datum(int itag, int imonat, int ijahr, int iwtid);
	~Datum();
	void display(sf::RenderWindow*);				//Zeichnet das Datum auf den Bildschirm
	void add(int);									//f�gt x tage auf das datum hinzu (wird erst bei update aktualisiert
	void update();									//aktualisiert das datum
	int getAdder();									//gibt die Zahl zur�ck, die gerade im Buffer steht um hinzugef�gt zu werden
	void updateWochentag();							//wochentag wird angepasst
	string getWT();
	unsigned int getCalculatable();					//gibt das datum als einen leicht vergleichbaren int zur�ck
	int getJahr();
	int getMonat();
	int getTag();
};

