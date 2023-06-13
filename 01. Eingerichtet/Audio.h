#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
class Audio
{

private:
	sf::Music* music;			//der benutzte Music pointer
	int last;				//ID des zuletzt gespielten Songs
	//int intensity;		//Für eventuelle spätere Ergänzungen für differente Stimmungen welche durch verschiedene Musiklisten abgespielt werden soll
	bool inChange;			//bool für den check ob gerade ein Song gewechselt werden soll
	float vlm;				//multiplikator für das Volumen um dieses erst herunter zu setzen
	std::string changeFile;		//der Song, zu dem gewechselt werden soll
	float volume = 1; // lautstärkeregler
	float vlmwum;
	int pinx = 1125;
	int piny = 10;
	bool mousepressed = false;

	Sprite bar;
	Texture bar2;
	Sprite pin;
	Texture pin2;

public:
	Audio();
	~Audio();
	void update();
	sf::Music* getMusicObject();
	void changeSong(string filename);
	void songRadio();
	void skipSong();
	//void setIntensity(int iIntensity);
	void setVolume(float volume);
	void lsregler(RenderWindow* window);
};

