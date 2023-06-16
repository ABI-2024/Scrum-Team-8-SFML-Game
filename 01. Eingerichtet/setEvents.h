#pragma once
#include "Warteschlange.h"
#include <fstream>
#include <string>
#include <iostream>
#include "CSVcontrol.h"
class SetEvents
{

private:
	static int* setEventID[2]; //wird als 2-dimensionales Array erstellt, welches [2][x] groß ist, wobei x die eingetragene Anzahl an setEvents ist
	static int setEventStartID;
	static int amount;
	static int currentEvent;
public:
	static void loadFromFile();		//lädt die SetEvents in das Programm
	static void checkdate(int calculatableDate);	//checkt ob ein Event ausgeführt werden muss bei dem Datum
	static int getSetEventStartID();//wann die setevent zeilen beginnen
	static int getSetEventAmount();	
	static int getEnd();			//wann die setevent zeilen enden
};