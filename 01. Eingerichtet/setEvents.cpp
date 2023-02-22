#include "SetEvents.h"
#include "Warteschlange.h"
#include <fstream>
#include <string>
#include <iostream>
#include "CSVcontrol.h"
int* SetEvents::setEventID[2] = { nullptr,nullptr };
int SetEvents::setEventStartID = 0;
int SetEvents::amount = 0;
int SetEvents::currentEvent = 0;
void SetEvents::loadFromFile() {
	std::string buffer;
	std::ifstream file;
	file.open("ressources/events.csv", std::ios::in);
	setEventStartID = CSVcontrol::getEventStart(5);
	amount = CSVcontrol::getEventAmount(5);
	std::cout << "\namount etc: " << amount << " d " << setEventStartID;
	
	setEventID[0] = new int[amount];
	setEventID[1] = new int[amount];
	
	for (int i = 0; i < setEventStartID+1; i++) {

		std::getline(file, buffer, '\n');
	}
	for (int i = 0; i < CSVcontrol::getEventAmount(5); i++) {
		std::getline(file, buffer, ';');
		setEventID[0][i] = std::stoi(buffer);
		std::getline(file, buffer, ';');
		setEventID[1][i] = setEventStartID + i+1;
		std::getline(file, buffer, '\n');

	}
}


void SetEvents::checkdate(int calculatableDate) {

	if (setEventID[currentEvent][0] <= calculatableDate) {
		Warteschlange::addQueue(setEventID[1][0]);
		currentEvent += 1;
	}
	else {
		return;
	}

}
int SetEvents::getSetEventStartID() {
	return setEventStartID;
}
int SetEvents::getSetEventAmount() {
	return amount;
}

int SetEvents::getEnd() {
	return (setEventStartID + amount);
}
