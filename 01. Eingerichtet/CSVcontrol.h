#pragma once
class CSVcontrol
{

private:
	static short config[5];

	static short rowStart[5];
public:
	static void loadConfig();				//lädt die Werte aus der CSV
	static int getEventAmount(int number);	//gibt die Anzahl der Events der verschiedenen Gruppen zurück (1. phase 2.... folgeevents, setevents ...)
	static int getEventStart(int number);	//gibt den Startwert (Zeile) zu denen die versch. Gruppen an Events starten
};

