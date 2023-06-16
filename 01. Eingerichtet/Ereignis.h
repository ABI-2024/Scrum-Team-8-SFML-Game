#pragma once
#include <random>
#include <fstream> 
#include <stdlib.h> 
#include "Textausgabe.h"
#include "Ressource.h"
#include "Warteschlange.h"
#include "CSVcontrol.h"
#include "Person.h"
#include "SetEvents.h"
#include <string>
class Textausgabe;
class Ressource;
class Ereignis {

private:
	static int currentevent;

	static string text;
	static int antworten;
	static int minWater[3];
	static int minFood[3];
	static int maxWater[3];
	static int maxFood[3];
	static int nextevent[3][5];
	static short phase;
	static int lastEvent;
	static int dateChange[3];

	static short specialActionIndex[3];
	static string specialActionText[3];
	static Ressource* water;
	static Ressource* food;
	static Textausgabe* txt;

public:
	static int getcurrentevent();	//gibt das aktuelle event zur�ck
	static string getText();		//gibt den text zur�ck
	static void newevent();			//l�dt ein neues Event ein
	static void processAntwort(int);//verrechnet die gegebene Antwort auf entscheidungsfragen mit den definierten Resultaten
	static void setRessources(Ressource*, Ressource*);//gibt referenz auf die Ressourcen um die zu �ndern
	static void setTxt(Textausgabe* ntxt);//gibt Referenz auf das Textmodul um Werte zu �bergeben
	static void specialAction(int index); //spezifische Aktionen werden ausgef�hrt (tod, einschreiben von charakteren)
	static bool specialActionPossible();  //Schaut ob die Spezialaktion m�glich ist
	static int getPhase();				  //gibt die Spielphase zur�ck
}; 
