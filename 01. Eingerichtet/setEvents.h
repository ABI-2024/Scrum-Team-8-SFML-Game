#pragma once
class SetEvents
{

private:
	static int* setEventID[2]; //wird als 2-dimensionales Array erstellt, welches [2][x] groﬂ ist, wobei x die eingetragene Anzahl an setEvents ist
	static int setEventStartID;
	static int amount;
	static int currentEvent;
public:
	static void loadFromFile();
	static void checkdate(int calculatableDate);
	static int getSetEventStartID();
	static int getSetEventAmount();
	static int getEnd();
};