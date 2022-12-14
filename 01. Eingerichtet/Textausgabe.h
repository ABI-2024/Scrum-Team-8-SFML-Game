#pragma once
#include "stdafx.h"
using namespace std;
using namespace sf;

class Textausgabe
{
private:
	static string text;		//Die Texte, die ausgegeben werden sollen als  in Zeilen unterteilt
	static int ausgeg;			//ein int counter f�r die Anzahl an ausgegebenen Zeichen
	static int tics;			//ein int counter, der die Tics zwischen der ausgabe regelt und die 
	//Ausgabegeschwindigkeit indirekt regelt
	static int from;
	static bool cont;				//Ein interner Bool, welcher angibt ob weiter gez�hlt und ausgegeben wird
	static int maxlines;			//Ein interner Counter, welcher die ausgegebenen Zeilen auf dem Bildschirm speichert
	static char exit;				//Wert, welcher angibt, ob sich das Textfeld einfach durch eine Bet�tigung der Leertaste schlie�en l�sst (standard = true)
	static string txtbackground;	//adjustierbarer Wert um verschiedene Hintergr�nde einzusetzen, falls diese sich ver�ndern sollen
	//(muss sich unter ressources/grafics befinden mit einer skalierung von 1270 zu 240)


	static sf::Sound soundeffect;
	static SoundBuffer buffer;

//zu dem Tastatur einlesen und Aufrufen der Folgeevents
	static int* result;

public:
	
	static bool display(RenderWindow*);		//Eine Methode, welche regul�r am Ende der main aufgerufen werden 
	//soll und wenn Text vorhanden ist, diesen teilweise ausgeben soll

	static void einlesen(std::string);			//Eine M�glichkeit den auszugebenen String zu setzen 

	static void setExit(char);
	static void init();
	static void setBackground(std::string);	//setzt den Hintergrund des Textfeldesm welches in dem grafics-Ordner hinterlegt werden muss
	//(Ma�e: 1270 : 240)


// Einlesen von der Tastatur f�r neue Events


	static void setResult(int, int, int);
	static void keyboardInsertion();


	//Simple allwertige einlesefunktion f�r Ereignisse mit Folge
	//resultC = 0, wenn keine dritte Antwortm�glichkeit existiert
	//followup = 0, wenn keines, = 1 wenn eines erfolgt;
	static void uniInsertion(string text, int resultA, int resultB, int resultC);

};


