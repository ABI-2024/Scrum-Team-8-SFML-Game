#include <random>
#include "Warteschlange.h"

using namespace std;

int rando(int a, int b);

void Zufallsgenerator() {
	int zahl = 0;
	int counter = 0; //erstellen der Variablen
	bool check[15];

	for (int i = 0; i < 3; i++) {

		fill_n(check, 15, true); //zurücksetzen der Variablen nach jedem Durchlauf
		counter = 0;

		while (counter < 15) {

			zahl = rando(1, 15);  //generieren einer Zufallszahl

			if (check[zahl - 1]) { //Überprüfung ob die Zahl bereits benutzt wurde

				check[zahl - 1] = false;
				Warteschlange::addQueue(zahl + i * 16); //Einfügen in die Warteschlange
				counter++;
			}

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