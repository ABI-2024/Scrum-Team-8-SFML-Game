#include "Ereignis.h"
#include <random>
#include <fstream> 
#include <stdlib.h> 

using namespace std;

string Ereignis::text;
int Ereignis::antworten;
int Ereignis::awater[2];
int Ereignis::afood[2];
int Ereignis::bwater[2];
int Ereignis::bfood[2];
int Ereignis::cwater[2];
int Ereignis::cfood[2];
Ressource* Ereignis::water;
Ressource* Ereignis::food;
Textausgabe* Ereignis::txt;

int randomIntinRange(int a, int b);

string Ereignis::newevent(int eventindex) {
	string datastore = "ressources/events.csv";

	srand((unsigned)time(0));

	ifstream file;
	file.open(datastore, ios::in);

	string temp;
	int max = 0;

	getline(file, temp, ';');
	max = stoi(temp);
	getline(file, temp, '\n');

	int rnd;

	if (eventindex == 0) {
		rnd = randomIntinRange(0, max-1);
	}
	else { rnd = eventindex; }

	for (int i = 0; !file.eof(); i++) {
		if (i == rnd) {
			getline(file, temp, ';');
			text = temp;

			getline(file, temp, ';');
			antworten = stoi(temp);


			getline(file, temp, ';');
			awater[0] = stoi(temp);
			getline(file, temp, ';');
			awater[1] = stoi(temp);

			getline(file, temp, ';');
			afood[0] = stoi(temp);
			getline(file, temp, ';');
			afood[1] = stoi(temp);

			getline(file, temp, ';');
			bwater[0] = stoi(temp);
			getline(file, temp, ';');
			bwater[1] = stoi(temp);

			getline(file, temp, ';');
			bfood[0] = stoi(temp);
			getline(file, temp, ';');
			bfood[1] = stoi(temp);

			getline(file, temp, ';');
			cwater[0] = stoi(temp);
			getline(file, temp, ';');
			cwater[1] = stoi(temp);

			getline(file, temp, ';');
			cfood[0] = stoi(temp);
			getline(file, temp, '\n');
			cfood[1] = stoi(temp);


		}
		else { getline(file, temp, '\n'); }

	}
	// Klasse Ressource aufrufen (später mit Zufallszahl)

	txt->uniInsertion(text, antworten);

	file.close();
	return text;
}

string Ereignis::getText() {
	return text;
}



void Ereignis::processAntwort(int index) {

	if (index == 0) {

	}
	else if (index == 1) {
		water->addmenge(randomIntinRange(awater[1], awater[0]));
		food->addmenge(randomIntinRange(afood[1], afood[0]));
	}

	else if (index == 2) {
		water->addmenge(randomIntinRange(bwater[1], bwater[0]));
		food->addmenge(randomIntinRange(bfood[1], bfood[0]));

	}
	else if (index == 3) {
		water->addmenge(randomIntinRange(cwater[1], cwater[0]));
		food->addmenge(randomIntinRange(cfood[1], cfood[0]));
	}
	Ereignis::newevent(0);
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
	//for (int n = 0; n < 40; ++n)
	//{
	//	std::cout << distr(gen) << ' '; // generate numbers
	//}


}