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
	static int nextevent[3];
	static short phase;
	static int lastEvent;
	static int dateChange[3];

	static short specialActionIndex[3];
	static string specialActionText[3];

	static Ressource* water;
	static Ressource* food;
	static Textausgabe* txt;

public:
	static int getcurrentevent();
	static string getText();
	static void newevent();
	static void processAntwort(int);
	static void setRessources(Ressource*, Ressource*);
	static void setTxt(Textausgabe* ntxt);
	static void specialAction(int index);
	static bool specialActionPossible();
	static int getPhase();
}; 
