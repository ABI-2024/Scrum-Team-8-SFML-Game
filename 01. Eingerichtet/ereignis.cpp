#include "Ereignis.h"
#include "Datum.h"

using namespace std;

string Ereignis::text;
int Ereignis::antworten;
int Ereignis::minWater[3];
int Ereignis::minFood[3];
int Ereignis::maxWater[3];
int Ereignis::maxFood[3];
short Ereignis::specialActionIndex[3];
string Ereignis::specialActionText[3];
short Ereignis::phase = 1;
int Ereignis::lastEvent = 100;
int Ereignis::nextevent[3];

Ressource* Ereignis::water;
Ressource* Ereignis::food;
Textausgabe* Ereignis::txt = nullptr;

int randomIntinRange(int a, int b);

void Ereignis::newevent() {

	ifstream file;
	string temp;
	int rnd = 0;
	int eventindex = Warteschlange::getFirst();
	if (eventindex == 0) {
	

		rnd = 1 + randomIntinRange(CSVcontrol::getEventStart(phase), CSVcontrol::getEventStart(phase) + CSVcontrol::getEventAmount(phase) - 1);

	}
	else {
		rnd = eventindex;
	}
	file.open("ressources/events.csv", ios::in);
	//getline(file, temp, '\n');
	for (int i = 0; !file.eof(); i++) {
		if (i == rnd) {

			if (rnd >= SetEvents::getSetEventStartID() && rnd <= SetEvents::getSetEventStartID() + SetEvents::getSetEventAmount()) {
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



			for (int i = 0; i < 3; i++) {
				getline(file, temp, ';');
				nextevent[i] = stoi(temp);
			}
			for (int i = 0; i < 2; i++) {
				getline(file, temp, ';');
				specialActionIndex[i] = stoi(temp);
				getline(file, temp, ';');
				specialActionText[i] = temp;

			}
			getline(file, temp, ';');
			specialActionIndex[2] = stoi(temp);
			getline(file, temp, '\n');
			specialActionText[2] = temp;
			
		}
		else { getline(file, temp, '\n'); }

	}


	if (specialActionPossible()) {

		txt->uniInsertion(text, antworten);

	}
	else {

	}

	file.close();

}

string Ereignis::getText() {
	return text;
}


void Ereignis::processAntwort(int index) {
	Datum::getDate()->add(1);
	if (index > 0 && index <= 3) {
		water->addmenge(randomIntinRange(minWater[index - 1], maxWater[index - 1]));
		food->addmenge(randomIntinRange(minFood[index - 1], maxFood[index - 1]));

		if (nextevent[index - 1] == 0) {

			newevent();
			return;
		}
		else if (nextevent[index - 1] == -1) {
			return;
		}
		else {

			Warteschlange::forceNext(CSVcontrol::getEventStart(4) + nextevent[index - 1]);
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


void Ereignis::specialAction(int index) {
	bool ret = true;
	int loss;
	string name;
	switch (specialActionIndex[index]) {
	case 0:
		break;
	case 1:

		break;
	case 2:
		bool stillname = true;
		for (int i = 0; i < specialActionText[index].length(); i++) {
			if (specialActionText[index][i] == '#') {
				stillname = false;
				continue;
			}
			if (stillname) {
				name[i] = specialActionText[index][i];
			}
			else {
				loss = stoi(specialActionText[index].substr(name.length(), specialActionText[index].length()));
			}
		}
		for (Person* iterator : Person::getchars()) {
			if (iterator->getName() == name) {
				if (iterator->getStatus() != idle) {
					//a

				}
			}
		}

		break;
	}
	return;
}
bool Ereignis::specialActionPossible() {
	bool ret = true;
	string name;
	for (int i = 0; i < 3; i++) {
		switch (specialActionIndex[i]) {
		case 0:
			ret = true;
			break;
		case 1:		//specific Person leaves
			for (Person* iterator : Person::getchars()) {
				if (iterator->getName() == specialActionText[i]) {
					if (iterator->getStatus() != idle) {
						ret = false;
					}
				}
			}
			break;
		case 2:		//specific Person loses mental health
		{
			bool stillname = true;

			for (int n = 0; n < specialActionText[n].length(); n++) {
				if (specialActionText[i][n] == '#') {
					stillname = false;
					continue;
				}
				if (stillname) {
					name[n] = specialActionText[i][n];
				}

			}

			for (Person* iterator : Person::getchars()) {
				if (iterator->getName() == name) {
					if (iterator->getStatus() != idle) {
						ret = false;
					}
					break;
				}
			}


			break;
		}

		case 3:		//Person loses physical health

			break;
		}
	}
	return true;
}