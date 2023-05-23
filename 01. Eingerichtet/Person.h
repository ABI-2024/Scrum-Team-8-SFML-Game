#pragma once
#include <string>
#include <list>
#include "Datum.h"
enum status : short {
	idle = 1,
	dead = 2,
	enlisted = 3,
	working = 4,
	outside = 5
};
class Person
{
private:
	static list<Person*> family;
	Sprite icon;
	Texture txture;
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
	static list<Person*> getFamily();
	static void update();
	static void loadChars();
	void hurt(int dmg);
	enum status getStatus();
	void psyDmg(int dmg);
	string getName();
	void setStatus(enum status set);
	static void displayFamily(RenderWindow* window);
	void loadVisualDisplay(int row);
	void render(RenderWindow* window);
	static int getPresentCharactarAmount();
	//void calAge(Datum* date);
};

