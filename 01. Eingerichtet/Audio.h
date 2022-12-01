#pragma once
#include "stdafx.h"
class Audio
{

private:
	Music* music;			//der benutzte Music pointer
	int last;				//ID des zuletzt gespielten Songs
	//int intensity;		//F�r eventuelle sp�tere Erg�nzungen f�r differente Stimmungen welche durch verschiedene Musiklisten abgespielt werden soll
	bool inChange;			//bool f�r den check ob gerade ein Song gewechselt werden soll
	float vlm;				//multiplikator f�r das Volumen um dieses erst herunter zu setzen
	string changeFile;		//der Song, zu dem gewechselt werden soll

public:
	Audio();
	~Audio();
	void update();
	Music* getMusicObject();
	void changeSong(string filename);
	void songRadio();
	void skipSong();
	//void setIntensity(int iIntensity);
	void setVolume(float volume);
};

