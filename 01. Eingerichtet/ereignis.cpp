#include "Ereignis.h"
#include <ctime>
#include <fstream> 
#include <stdlib.h> 

using namespace std;


string Ereignis::text;
string Ereignis::antworten[3];
int Ereignis::awater[2];
int Ereignis::afood[2];
int Ereignis::bwater[2];
int Ereignis::bfood[2];
int Ereignis::cwater[2];
int Ereignis::cfood[2];
Ressource* Ereignis::water;
Ressource* Ereignis::food;



string Ereignis::newevent(int eventindex) {
	string datastore = "ressources/events.csv";

	srand((unsigned)time(0));

	ifstream file;
	file.open(datastore, ios::in);

	string temp;
	int max = 0;

	getline(file, temp, '\n');
	max = stoi(temp);

	int rnd;

	if (eventindex == 0) {
		rnd = (rand() % max);
	}
	else { rnd = eventindex; }

	for (int i = 0; !file.eof(); i++) {
		if (i == rnd) {
			getline(file, temp, ';');
			text = temp;

			getline(file, temp, ';');
			antworten[0] = temp;
			getline(file, temp, ';');
			antworten[1] = temp;
			getline(file, temp, ';');
			antworten[2] = temp;

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
	


	file.close();
	return text;
}

string Ereignis::getText() {
	return text;
}

string Ereignis::getAntwort(int index) {
	return antworten[index+1];
}



void Ereignis::processAntwort(int index) {
	if (index == 1) {
		water->addmenge(-(rand() % awater[1] + awater[0]));
		food->addmenge(-(rand() % afood[1] + afood[0]));
	}

	if (index == 2) {
		water->addmenge(-(rand() % bwater[1] + bwater[0]));
		food->addmenge(-(rand() % bfood[1] + bfood[0]));
	}

	if (index == 3) {
		water->addmenge(-(rand() % cwater[1] + cwater[0]));
		food->addmenge(-(rand() % cfood[1] + cfood[0]));
	}
	Ereignis::newevent(0);
}