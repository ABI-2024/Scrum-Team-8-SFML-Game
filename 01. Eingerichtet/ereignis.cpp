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

int Ereignis::nextevent[3];

Ressource* Ereignis::water;
Ressource* Ereignis::food;
Textausgabe* Ereignis::txt;

int randomIntinRange(int a, int b);

void Ereignis::newevent() {
	string datastore = "ressources/events.csv";

	ifstream file;
	file.open(datastore, ios::in);

	string temp;
	int randomEventNumber = 0;

	getline(file, temp, ';');
	randomEventNumber = stoi(temp);
	getline(file, temp, '\n');
	file.close();
	file.open(datastore, ios::in);

	int rnd;
	int eventindex = Warteschlange::getFirst();
	if (eventindex == 0) {
		rnd = randomIntinRange(1, randomEventNumber);

	}
	else {
		rnd = eventindex;
	}

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
				cout << temp;
				minWater[i] = stoi(temp);
				getline(file, temp, ';');
				cout << "-" << temp << "\n";
				maxWater[i] = stoi(temp);

				getline(file, temp, '#');
				cout << temp;
				minFood[i] = stoi(temp);
				getline(file, temp, ';');
				cout << "-" << temp << "\n";
				maxFood[i] = stoi(temp);

			}



			for (int i = 0; i < 2; i++) {
				getline(file, temp, ';');
				nextevent[i] = stoi(temp);
				cout << temp << "\n";
			}
			getline(file, temp, '\n');
			nextevent[2] = stoi(temp);
			cout << temp << "\n";
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
			Warteschlange::forceNext(stoi(temp) + nextevent[index - 1] + 2);
			file.close();
			newevent();
		}
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