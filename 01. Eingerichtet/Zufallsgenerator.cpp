#include <random>
#include "Warteschlange.h"

using namespace std;

int rando(int a, int b);

void Zufallsgenerator() {
	int zahl = 0;
	int counter; //erstellen der Variablen
	bool check[20];
	int phase1 = 16;
	int phase2 = 15;
	int phase3 = 15;

	fill_n(check, phase1, true); //zur�cksetzen der Variablen nach jedem Durchlauf
	counter = 0;

	while (counter < phase1) {

		zahl = rando(1, phase1);  //generieren einer Zufallszahl

		if (check[zahl - 1]) { //�berpr�fung ob die Zahl bereits benutzt wurde

			check[zahl - 1] = false;
			Warteschlange::addQueue(zahl); //Einf�gen in die Warteschlange
			counter++;
		}

	}
	
	fill_n(check, phase2, true); //zur�cksetzen der Variablen nach jedem Durchlauf
	counter = 0;

	while (counter < phase2) {

		zahl = rando(1, phase2);  //generieren einer Zufallszahl

		if (check[zahl - 1]) { //�berpr�fung ob die Zahl bereits benutzt wurde

			check[zahl - 1] = false;
			Warteschlange::addQueue(zahl + phase1 + 1); //Einf�gen in die Warteschlange
			counter++;
		}

	}


	fill_n(check, phase3, true); //zur�cksetzen der Variablen nach jedem Durchlauf
	counter = 0;

	while (counter < phase3) {

		zahl = rando(1, phase3);  //generieren einer Zufallszahl

		if (check[zahl - 1]) { //�berpr�fung ob die Zahl bereits benutzt wurde

			check[zahl - 1] = false;
			Warteschlange::addQueue(zahl + phase1 + phase2 + 2); //Einf�gen in die Warteschlange
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