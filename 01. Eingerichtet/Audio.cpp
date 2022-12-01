#include "Audio.h"
#include <random>

#define maxsongs 3

Audio::Audio() {
	music = new Music();
	inChange = false;
	last = 0;
	//intensity = 1;
	music->setVolume(25.f);
	vlm = 1;
	changeFile = "leer";
}
Audio::~Audio() {
	delete music;
}
Music* Audio::getMusicObject() {
	return music;
}
void Audio::update() {
	if (!inChange) {
		this->songRadio();
	}
	else {
		if (vlm < 10) {
			music->setVolume(music->getVolume() * vlm / (vlm + 0.1f));
			vlm += 0.1f;

		}
		else {
			if (!music->openFromFile(changeFile)) {
				return;
			}
			inChange = false;
			changeFile = "leer";
			music->setVolume(music->getVolume() * vlm);
			vlm = 1;
			music->play();
		}
	}
}
void Audio::changeSong(string filename) {
	inChange = true;
	changeFile = filename;
}
void Audio::songRadio() {
	//Music checker
	if (music->getStatus() != Music::Playing) {
		music->stop();
		int tmp;
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(1, maxsongs); // define the range

		tmp = distr(gen);
		if (tmp != last) {
			if (!music->openFromFile("ressources/audio/music" + to_string(tmp) + ".wav")) {
				return;
			}
			last = tmp;
			music->play();
		}
	}
}
void Audio::nextSong() {
	int tmp;
	while (1 && maxsongs > 1) {
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(1, maxsongs); // define the range

		tmp = distr(gen);
		if (tmp != last) {
			break;
		}
	}

	this->changeSong("ressources/audio/music" + to_string(tmp) + ".wav");
	last = tmp;

}
//void Audio::setIntensity(int iIntensity) {
//	intensity = iIntensity;
//	last = 0;
//	this->nextSong();
//}
void Audio::setVolume(float volume) { //volume ist der multiplikator der Lautstärke. d.h. 1 == 100% der std. Lautstärke -> max = 400% / 4

	this->music->setVolume(25 * volume);
	return;
}