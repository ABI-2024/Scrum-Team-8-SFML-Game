#include "Ereignis.h"


using namespace std;

string Ereignis::text;
int Ereignis::antworten;
int Ereignis::minWater[3];
int Ereignis::minFood[3];
int Ereignis::maxWater[3];
int Ereignis::maxFood[3];
short Ereignis::specialActionIndex[3];
string Ereignis::specialActionText[3];
short Ereignis::phase = 2;

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
		for (int i = 0; i < 3; i++) {
			std::cout << "\n\tMinRandomNumber " << i + 1 << ":" << CSVcontrol::getEventStart(i + 1);
			std::cout << "\n\tMaxRandomNumber " << i + 1 << ":" << CSVcontrol::getEventStart(i + 1) + CSVcontrol::getEventAmount(i + 1) - 1 << "\t Amount: " << CSVcontrol::getEventAmount(i + 1) << endl;

		}
		rnd = 1 + randomIntinRange(CSVcontrol::getEventStart(phase), CSVcontrol::getEventStart(phase) + CSVcontrol::getEventAmount(phase) - 1);
	}
	else {
		rnd = eventindex;
	}
	cout << "\n\tCSV-Row: " << rnd;
	file.open("ressources/events.csv", ios::in);
	//getline(file, temp, '\n');
	for (int i = 0; !file.eof(); i++) {
		if (i == rnd) {

			if (rnd >= SetEvents::getSetEventStartID() && rnd <= SetEvents::getSetEventStartID()+SetEvents::getSetEventAmount()) {
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
				std::cout << "\nerror ? :\t" << temp << endl;
				specialActionIndex[i] = stoi(temp);
				getline(file, temp, ';');
				specialActionText[i] = temp;

			}
			getline(file, temp, ';');
			specialActionIndex[2] = stoi(temp);
			getline(file, temp, '\n');
			specialActionText[2] = temp;
			/*for (int i = 0; i < 3; i++) {
				std::cout << "\n" << specialActionText[i] << "\t" << specialActionIndex[i];
			}*/
		}
		else { getline(file, temp, '\n'); }

	}


	std::cout << "cp1 passed\n";
	if (specialActionPossible() || 1) {

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
	switch (specialActionIndex[index]) {
	case 0:
		break;
	case 1:

		break;
	case 2:
		break;
	}
	return;
}
bool Ereignis::specialActionPossible() {
	bool ret = true;
	for (int i = 0; i < 3; i++) {
		switch (specialActionIndex[i]) {
		case 0:
			ret = true;
			break;
		case 1:		//Person leaves
			for (Person* iterator : Person::getchars()) {
				if (iterator->getName() == specialActionText[i]) {
					if (iterator->getStatus() != idle) {
						ret = false;
					}
				}
			}
			break;
		case 2:		//Person loses mental health
			break;


		case 3:		//Person loses physical health
			break;
		}
	}
	return true;
}