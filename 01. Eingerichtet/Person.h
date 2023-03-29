#pragma once
#include <string>
#include <list>
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
	static list<Person*> characters;

	Datum geburtsDatum;
	bool is_available;
	status status;
	char sex;
	std::string name;
	short hunger;
	short mental_health;
	short physical_health;


public:
	Person(Datum* bday, char gender, std::string name);
	~Person();
	static list<Person*> getchars();
	static void update();
	void hurt(int dmg);
	enum status getStatus();
	void psyDmg(int dmg);
	string getName();
	void setStatus(enum status set);
	//void calAge(Datum* date);
};

