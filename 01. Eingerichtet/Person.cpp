#include "Person.h"

list<Person*> Person::family;

Person::Person(Datum* bday, char gender, std::string name) {
	geburtsDatum = *bday;
	is_available = true;
	status = idle;
	sex = gender;
	this->name = name;
	hunger = 0;
	mental_health = 1000;
	physical_health = 1000;
	
}
Person::~Person() {
	return;
}

int Person::getPresentCharactarAmount() {

	int i = 0;
	for (Person* g : family) {
		if (g->getStatus() == idle) {
			i++;
		}
	}
	return i;
}
void Person::loadChars() {
	family.push_back(new Person(new Datum(5, 10, 1928, 2), 'm', "Kenzo")); //brother
	family.push_back(new Person(new Datum(5, 10,1920,2), 'f', "Akari")); //female main character
	family.push_back(new Person(new Datum(5, 10, 1892, 2), 'f', "Sakura")); //mother
	family.push_back(new Person(new Datum(5, 10, 1920, 2), 'm', "Kenji")); //father
	family.push_back(new Person(new Datum(5, 10, 1920, 2), 'f', "Himari")); //grandmother
	int i = 0;
	for (Person* g : family) {
		g->loadVisualDisplay(i);
		i++;
	}
}
enum status Person::getStatus() {
	return status;
}
void Person::setStatus(enum status set) {
	status = set;
}
list<Person*> Person::getFamily() {
	
	return family;
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

void Person::displayFamily(RenderWindow* window) {
	int i = 0;
	for (Person* g : family) {
		g->render(window);
		i++;
	}
}
void Person::loadVisualDisplay(int row) {

	txture.loadFromFile("ressources/grafics/Family/" + name + ".png");
	icon.setTexture(txture);
	icon.setPosition(Vector2f(1100, 50 + 80 * (row)));
	icon.scale(Vector2f(0.16f, 0.16f));
	statusicon.setScale(Vector2f(0.16f, 0.16f));
	statusicon.setPosition(icon.getPosition().x - 6, icon.getPosition().y);
	statusicon.setColor(Color(255, 255, 255, 192));
}

void Person::render(RenderWindow* window) {
	window->draw(icon);
	
	statustexture.loadFromFile("ressources/grafics/Family/status" + to_string(status) + ".png");
	
	statusicon.setTexture(statustexture);
	window->draw(statusicon);
}