#pragma once
#include "Textausgabe.h"
#include "Ressource.h"
#include "Warteschlange.h"
#include <string>
class Textausgabe;
class Ressource;
class Ereignis {

private:
	static string text;
	static int antworten;
	static int minWater[3];
	static int minFood[3];
	static int maxWater[3];
	static int maxFood[3];
	static int nextevent[3];

	static Ressource* water;
	static Ressource* food;

	static Textausgabe* txt;

public:
	static string getText();
	static void newevent();
	static void processAntwort(int);
	static void setRessources(Ressource*, Ressource*);
	static void setTxt(Textausgabe*);


}; 
