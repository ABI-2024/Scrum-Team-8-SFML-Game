#include <random>
#include "Warteschlange.h"

#include "CSVcontrol.h"

using namespace std;

int rando(int a, int b);

void Zufallsgenerator() {
	int zahl = 0;
	int counter; //erstellen der Variablen
	bool check[20];
	int phase1 = CSVcontrol::getEventAmount(1);
	int phase2 = CSVcontrol::getEventAmount(2);
	int phase3 = CSVcontrol::getEventAmount(3);

	fill_n(check, phase1, true); //zurücksetzen der Variablen nach jedem Durchlauf
	counter = 0;
	Warteschlange::addQueue(43);
	while (counter < phase1) {

		zahl = rando(1, phase1);  //generieren einer Zufallszahl

		if (check[zahl - 1]) { //Überprüfung ob die Zahl bereits benutzt wurde

			check[zahl - 1] = false;
			Warteschlange::addQueue(zahl); //Einfügen in die Warteschlange
			counter++;
		}

	}
	
	fill_n(check, phase2, true); //zurücksetzen der Variablen nach jedem Durchlauf
	counter = 0;

	while (counter < phase2) {

		zahl = rando(1, phase2);  //generieren einer Zufallszahl

		if (check[zahl - 1]) { //Überprüfung ob die Zahl bereits benutzt wurde

			check[zahl - 1] = false;
			Warteschlange::addQueue(zahl + phase1 + 1); //Einfügen in die Warteschlange
			counter++;
		}

	}


	fill_n(check, phase3, true); //zurücksetzen der Variablen nach jedem Durchlauf
	counter = 0;

	while (counter < phase3) {

		zahl = rando(1, phase3);  //generieren einer Zufallszahl

		if (check[zahl - 1]) { //Überprüfung ob die Zahl bereits benutzt wurde

			check[zahl - 1] = false;
			Warteschlange::addQueue(zahl + phase1 + phase2 + 2); //Einfügen in die Warteschlange
			counter++;
		}

	}

}

int rando(int a, int b) {

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