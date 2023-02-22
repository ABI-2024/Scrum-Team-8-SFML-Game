#include "Person.h"


Person::Person(Datum* bday, char gender, std::string name) {
	geburtsDatum = *bday;
	is_available = true;
	status = idle;
	sex = gender;
	this->name = name;
	hunger = 0;
	mental_health = 1000;
	physical_health = 1000;
	characters.push_back(this);
}
Person::~Person() {
	return;
}

enum status Person::getStatus() {
	return status;
}

list<Person*> Person::getchars() {

	return characters;
}

string Person::getName() {
	return name;
}

void Person::update() {

}
void Person::hurt(int dmg) {
	physical_health -= dmg;
}
void Person::psyDmg(int dmg) {
	mental_health -= dmg;
}