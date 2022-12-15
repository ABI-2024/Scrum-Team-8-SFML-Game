#pragma once
#include <string>
#include "Datum.h"
enum status : short {
	idle,
	dead,
	enlisted,
	working,
	outside
};
class Person
{
private:
	Datum geburtsDatum;
	bool is_available;
	status status;
	char sex;
	std::string name;
	short age;
	short hunger;
	short mental_health;
	short physical_health;


public:

};

