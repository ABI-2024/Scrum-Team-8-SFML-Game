using namespace std;

#include <iostream>
#include <string>
#include <ctime>
#include <fstream> 
#include <stdlib.h> 



struct dscontent {
	string text;
	string antwort[3];



};

string newevent() {
	string datastore = "events.csv";

	srand((unsigned)time(0));

	ifstream filec;
	filec.open(datastore, ios::in);
	struct dscontent data;

	string temp;
	int max = 0;

	for (int i = 0; !filec.eof(); i++) {
		getline(filec, temp, '\n');
		max++;
	}

	int rnd = (rand() % max);

	filec.close();
	ifstream file;
	file.open(datastore, ios::in);

	for (int i = 0; !file.eof(); i++) {

		if (i==rnd) {
			getline(file, temp, ';');
			data.text = temp;

			getline(file, temp, ';');
			data.antwort[0] = temp;

			getline(file, temp, ';');
			data.antwort[1] = temp;

			getline(file, temp, '\n');
			data.antwort[2] = temp;

		} else{ getline(file, temp, '\n'); }
		
	}

	// Klasse Ressource aufrufen (später mit Zufallszahl)

	file.close();
	return data.text;
}