#include "SetEvents.h"

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
	
	setEventID[0] = new int[amount];
	setEventID[1] = new int[amount];
	
	for (int i = 0; i < setEventStartID+1; i++) {

		std::getline(file, buffer, '\n');
	}
	for (int i = 0; i < amount; i++) {
		std::getline(file, buffer, ';');
		setEventID[0][i] = std::stoi(buffer);
		std::getline(file, buffer, ';');
		setEventID[1][i] = setEventStartID + i+1;
		std::getline(file, buffer, '\n');

	}

}


void SetEvents::checkdate(int calculatableDate) {
	if (setEventID[0][currentEvent] <= calculatableDate) {
		Warteschlange::forceNext(setEventID[1][currentEvent]);
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
