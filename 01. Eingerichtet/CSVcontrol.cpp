#include "CSVcontrol.h"
#include <fstream>
#include <iostream>
#include <string>


short CSVcontrol::config[] = {0};

int CSVcontrol::getConfig(int confignumber) {
	return config[confignumber - 1];
}

void CSVcontrol::loadConfig() {
	std::ifstream file;
	std::string buffer;
	file.open("ressources/events.csv", std::ios::in);

	for (int i = 0; i < 4; i++) {
		std::getline(file, buffer, ';');

		std::cout << "\n\t" << buffer;
		config[i] = std::stoi(buffer);
		std::cout << "\t" << config[i];
		std::getline(file, buffer, '\n');
		for (int n = 0; n < config[i]; n++) {
			std::getline(file, buffer, '\n');
		}
	}
	file.close();
}