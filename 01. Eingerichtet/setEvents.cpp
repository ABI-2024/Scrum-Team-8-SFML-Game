#include "SetEvents.h"
#include "Warteschlange.h"
#include <fstream>
#include <string>

int* SetEvents::setEventID[2] = { nullptr,nullptr };
int SetEvents::setEventStartID = 0;
int SetEvents::amount = 0;
int SetEvents::currentEvent = 0;
void SetEvents::loadFromFile() {

	std::string buffer;
	std::ifstream file;
	file.open("ressources/events.csv", std::ios::in);
	std::getline(file, buffer, ';');
	int tmp = std::stoi(buffer);
	setEventStartID = tmp;
	std::getline(file, buffer, '\n');
	for (int i = 0; i < tmp; i++) {
		std::getline(file, buffer, '\n');
	}
	std::getline(file, buffer, ';');
	tmp = std::stoi(buffer);
	setEventStartID += tmp + 2;
	std::getline(file, buffer, '\n');
	for (int i = 0; i < tmp; i++) {
		std::getline(file, buffer, '\n');
	}
	std::getline(file, buffer, ';');
	tmp = std::stoi(buffer);
	std::getline(file, buffer, '\n');
	setEventID[0] = new int[tmp];
	setEventID[1] = new int[tmp];
	int i = 0;
	for (; i < tmp; i++) {
		std::getline(file, buffer, ';');
		setEventID[0][i] = std::stoi(buffer);
		std::getline(file, buffer, ';');
		setEventID[1][i] = setEventStartID + i;
		std::getline(file, buffer, '\n');

	}
	amount = i + 1;
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
