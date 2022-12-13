#pragma once
#include "stdafx.h"

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
	string getText();
	string getAntwort(int);
	string newevent(int);
	void processAntwort(int);


};
