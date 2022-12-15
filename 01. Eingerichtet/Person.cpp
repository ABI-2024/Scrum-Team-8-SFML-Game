#include "Person.h"


Person::Person(Datum* bday, short age, char gender, std::string name) {
	geburtsDatum = *bday;
	is_available = true;
	status = idle;
	sex = gender;
	this->name = name;
	this->age = age;
	hunger = 0;
	mental_health = 1000;
	physical_health = 1000;
}
Person::~Person() {
	return;
}

void Person::update() {

}
void Person::hurt(int dmg) {
	physical_health -= dmg;
}
void Person::psyDmg(int dmg) {
	mental_health -= dmg;
}