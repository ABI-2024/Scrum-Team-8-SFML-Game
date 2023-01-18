#pragma once
#include "stdafx.h"
using namespace std;
using namespace sf;
enum leave : char {
	wait_for_input = 0,
	leave_immediatly = 1,
	leave_after_enter = 2
};
class Textausgabe
{
private:
	string text;		//Die Texte, die ausgegeben werden sollen als  in Zeilen unterteilt
	int ausgeg;			//ein int counter f�r die Anzahl an ausgegebenen Zeichen
	int tics;			//ein int counter, der die Tics zwischen der ausgabe regelt und die 
	//Ausgabegeschwindigkeit indirekt regelt
	int from;
	bool cont;				//Ein interner Bool, welcher angibt ob weiter gez�hlt und ausgegeben wird
	int maxlines;			//Ein interner Counter, welcher die ausgegebenen Zeilen auf dem Bildschirm speichert
	leave done;				//Wert, welcher angibt, ob sich das Textfeld einfach durch eine Bet�tigung der Leertaste schlie�en l�sst (standard = true)
	string txtbackground;	//adjustierbarer Wert um verschiedene Hintergr�nde einzusetzen, falls diese sich ver�ndern sollen
	//(muss sich unter ressources/grafics befinden mit einer skalierung von 1270 zu 240)
	Sprite txtbg;
	Text ausgabe;

	sf::Sound soundeffect;
	SoundBuffer buffer;

	//zu dem Tastatur einlesen und Aufrufen der Folgeevents
	int* result;


public:
	Textausgabe();
	~Textausgabe();
	bool display(RenderWindow*);		//Eine Methode, welche regul�r am Ende der main aufgerufen werden 
	//soll und wenn Text vorhanden ist, diesen teilweise ausgeben soll

	void einlesen(std::string);			//Eine M�glichkeit den auszugebenen String zu setzen 

	void setExit(leave);

	void setBackground(std::string, Color);	//setzt den Hintergrund des Textfeldesm welches in dem grafics-Ordner hinterlegt werden muss
	//(Ma�e: 1270 : 240)


// Einlesen von der Tastatur f�r neue Events


	void setResult(int, int, int);
	void keyboardInsertion();


	//Simple allwertige einlesefunktion f�r Ereignisse mit Folge
	//resultC = 0, wenn keine dritte Antwortm�glichkeit existiert
	//followup = 0, wenn keines, = 1 wenn eines erfolgt;
	void uniInsertion(string text, int resultA, int resultB, int resultC);

};


