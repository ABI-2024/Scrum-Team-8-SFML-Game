#pragma once
#include "Textausgabe.h"
#include "Ressource.h"
#include <string>

class Ereignis {
private:
	static string text;
	static string antworten[3];
	static int awater[2];
	static int afood[2];
	static int bwater[2];
	static int bfood[2];
	static int cwater[2];
	static int cfood[2];

	static Ressource* water;
	static Ressource* food;

public:
	static string getText();
	static string getAntwort(int);
	static string newevent(int);
	static void processAntwort(int);


};
