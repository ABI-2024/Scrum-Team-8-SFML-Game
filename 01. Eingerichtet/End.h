#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Ressource.h"
#include "Audio.h"
#include "Datum.h"
#include "Textausgabe.h"

class End
{
private:
	static RenderWindow* window;
	static Audio* audio;
	static Textausgabe* text;
	static Datum* datum;
	static bool game_is_on;
public: 
	static void init(RenderWindow* iwindow, Audio* iaudio, Textausgabe* itext, Datum* idatum);	//initialisiert alle Werte
	static void endwin();		//das Fenster bei dem Absolvieren aller Events
	static void alliesWin();	//das Fenster bei der Flucht in die USA
	static void close();		//beendet das Spiel
	
};

