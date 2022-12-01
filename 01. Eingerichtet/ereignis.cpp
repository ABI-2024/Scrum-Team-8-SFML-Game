#include "stdafx.h"
#include <ctime>
#include <fstream> 
#include <stdlib.h> 

using namespace std;




string ereignisse::newevent(int eventindex) {
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

string ereignisse::getText() {
	return text;
}

string ereignisse::getAntwort(int index) {
	return antworten[index+1];
}

void ereignisse::setRessourcePointers(Ressource* objekte[2]) {
	water = objekte[0];
	food = objekte[1];
};