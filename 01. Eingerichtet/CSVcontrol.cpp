#include "CSVcontrol.h"
#include <fstream>
#include <iostream>
#include <string>


short CSVcontrol::config[] = { 0 };
short CSVcontrol::rowStart[] = { 0 };

int CSVcontrol::getEventAmount(int confignumber) {
	return config[confignumber - 1];
}
int CSVcontrol::getEventStart(int number) {
	return rowStart[number - 1];
}

void CSVcontrol::loadConfig() {
	std::ifstream file;
	std::string buffer;
	int counter = 0;
	file.open("ressources/events.csv", std::ios::in);
	std::cout << "FileIDS:\n";
	for (int i = 0; i < 5; i++) {
		std::getline(file, buffer, ';');
		std::cout << "Iteration : " << i << "\n";
		config[i] = std::stoi(buffer);
		std::cout << config[i] << "\t" << counter + 1 << std::endl;
		rowStart[i] = counter;
		counter += 1;
		std::getline(file, buffer, '\n');

		for (int n = 0; n < config[i]; n++) {
			std::getline(file, buffer, '\n');
			counter += 1;
		}
	}
	file.close();
}