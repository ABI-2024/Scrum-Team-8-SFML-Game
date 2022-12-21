#pragma once
#include "Textausgabe.h"
#include "Ressource.h"
#include <string>
class Textausgabe;
class Ressource;
class Ereignis {
private:
	static string text;
	static int antworten;
	static int awater[2];
	static int afood[2];
	static int bwater[2];
	static int bfood[2];
	static int cwater[2];
	static int cfood[2];

	static Ressource* water;
	static Ressource* food;

	static Textausgabe* txt;

public:
	static string getText();
	static string newevent(int);
	static void processAntwort(int);
	static void setRessources(Ressource*, Ressource*);
	static void setTxt(Textausgabe*);


};
