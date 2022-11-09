#include "stdafx.h"
#include <ctime>
#include <fstream> 
#include <stdlib.h> 

using namespace std;



string newevent() {
	string datastore = "ressources/events.csv";

	srand((unsigned)time(0));

	ifstream file;
	file.open(datastore, ios::in);
	struct dscontent data;

	string temp;
	int max = 0;

	getline(file, temp, '\n');
	max = stoi(temp);


	int rnd = (rand() % max);

	for (int i = 0; !file.eof(); i++) {

		if (i == rnd) {
			getline(file, temp, ';');
			data.text = temp;

			getline(file, temp, ';');
			data.antwort[0] = temp;

			getline(file, temp, ';');
			data.antwort[1] = temp;

			getline(file, temp, '\n');
			data.antwort[2] = temp;

		}
		else { getline(file, temp, '\n'); }

	}

	// Klasse Ressource aufrufen (später mit Zufallszahl)

	file.close();
	return data.text;
}