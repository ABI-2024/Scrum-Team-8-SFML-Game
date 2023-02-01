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
	int ausgeg;			//ein int counter für die Anzahl an ausgegebenen Zeichen
	int tics;			//ein int counter, der die Tics zwischen der ausgabe regelt und die 
	//Ausgabegeschwindigkeit indirekt regelt
	int from;
	bool cont;				//Ein interner Bool, welcher angibt ob weiter gezählt und ausgegeben wird
	int maxlines;			//Ein interner Counter, welcher die ausgegebenen Zeilen auf dem Bildschirm speichert
	leave done;				//Wert, welcher angibt, ob sich das Textfeld einfach durch eine Betätigung der Leertaste schließen lässt (standard = true)
	string txtbackground;	//adjustierbarer Wert um verschiedene Hintergründe einzusetzen, falls diese sich verändern sollen
	//(muss sich unter ressources/grafics befinden mit einer skalierung von 1270 zu 240)
	Sprite txtbg;
	Text ausgabe;
	Font font;
	Texture txtfeldbg;

	sf::Sound soundeffect;
	SoundBuffer buffer;

	//zu dem Tastatur einlesen und Aufrufen der Folgeevents

	int awnser;

public:
	Textausgabe();
	~Textausgabe();
	bool display(RenderWindow*);		//Eine Methode, welche regulär am Ende der main aufgerufen werden 
	//soll und wenn Text vorhanden ist, diesen teilweise ausgeben soll

	void einlesen(std::string);			//Eine Möglichkeit den auszugebenen String zu setzen 

	void setExit(leave);

	void setBackground(std::string);	//setzt den Hintergrund des Textfeldesm welches in dem grafics-Ordner hinterlegt werden muss
	//(Maße: 1270 : 240)


// Einlesen von der Tastatur für neue Events


	void keyboardInsertion();


	//Simple allwertige einlesefunktion für Ereignisse mit Folge
	//resultC = 0, wenn keine dritte Antwortmöglichkeit existiert
	//followup = 0, wenn keines, = 1 wenn eines erfolgt;

	void uniInsertion(string text, int awnsers);


};


