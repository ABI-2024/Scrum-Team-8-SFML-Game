#include "Ereignis.h"
#include <random>
#include <fstream> 
#include <stdlib.h> 
#include "SetEvents.h"

using namespace std;

string Ereignis::text;
int Ereignis::antworten;
int Ereignis::minWater[3];
int Ereignis::minFood[3];
int Ereignis::maxWater[3];
int Ereignis::maxFood[3];
short Ereignis::phase = 0;

int Ereignis::nextevent[3];

Ressource* Ereignis::water;
Ressource* Ereignis::food;
Textausgabe* Ereignis::txt;

int randomIntinRange(int a, int b);

void Ereignis::newevent() {
	
	ifstream file;
	string temp;
	int rnd;
	int eventindex = Warteschlange::getFirst();
	if (eventindex == 0) {
		file.open("ressources/events.csv", ios::in);

		int phaseDependantEventEnd = 0;
		int phaseDependantEventNumber = 0;
		for (int i = 0; i <= phase; i++) {
			getline(file, temp, ';');

			phaseDependantEventEnd += stoi(temp);
			phaseDependantEventNumber = stoi(temp);

			getline(file, temp, '\n');
			for (int n = 0; n < phaseDependantEventNumber; n++) {
				getline(file, temp, '\n');
			}

		}

		file.close();
		rnd = randomIntinRange(phaseDependantEventEnd - phaseDependantEventNumber + 1, phaseDependantEventEnd);

	}
	else {
		rnd = eventindex;
	}
	file.open("ressources/events.csv", ios::in);
	for (int i = 0; !file.eof(); i++) {
		if (i == rnd) {

			if (/*rnd >= SetEvents::getSetEventStartID()*/0) {
				getline(file, temp, ';');
			}

			getline(file, temp, ';');
			text = temp;
			getline(file, temp, ';');
			antworten = stoi(temp);
			for (int i = 0; i <= 2; i++) {
				getline(file, temp, '#');
				minWater[i] = stoi(temp);
				getline(file, temp, ';');
				maxWater[i] = stoi(temp);

				getline(file, temp, '#');
				minFood[i] = stoi(temp);
				getline(file, temp, ';');
				maxFood[i] = stoi(temp);

			}



			for (int i = 0; i < 2; i++) {
				getline(file, temp, ';');
				nextevent[i] = stoi(temp);
			}
			getline(file, temp, '\n');
			nextevent[2] = stoi(temp);

		}
		else { getline(file, temp, '\n'); }

	}


	txt->uniInsertion(text, antworten);

	file.close();

}

string Ereignis::getText() {
	return text;
}


void Ereignis::processAntwort(int index) {

	if (index > 0 && index <= 3) {
		water->addmenge(randomIntinRange(minWater[index - 1], maxWater[index - 1]));
		food->addmenge(randomIntinRange(minFood[index - 1], maxFood[index - 1]));

		if (nextevent[index - 1] == 0) {
			newevent();
			return;
		}
		else {
			ifstream file;
			file.open("ressources/events.csv", ios::in);

			string temp;
			getline(file, temp, ';');

			Warteschlange::forceNext(stoi(temp) + nextevent[index - 1] + 1);
			file.close();
			newevent();
		}
	}
	else {
		newevent();
	}



}

void Ereignis::setRessources(Ressource* nfood, Ressource* nwater) {
	water = nwater;
	food = nfood;
}

void Ereignis::setTxt(Textausgabe* ntxt) {
	txt = ntxt;
}

int randomIntinRange(int a, int b) {

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	if (a > b) {
		std::uniform_int_distribution<> distr(b, a); // define the range
		return distr(gen);
	}
	else {
		std::uniform_int_distribution<> distr(a, b); // define the range	
		return distr(gen);
	}
}