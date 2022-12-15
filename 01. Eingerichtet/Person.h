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
	Person(Datum* bday, short age, char gender, std::string name);
	~Person();
	void update();
	void hurt(int dmg);
	void psyDmg(int dmg);
	void calAge(Datum* date);
};

