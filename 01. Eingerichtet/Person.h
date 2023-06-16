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
	short hunger;			//wurde nie benutzt
	short mental_health;	//wurde nie benutzt
	short physical_health;	//wurde nie benutzt
	Texture statustexture;	
	Sprite statusicon;

public:
	Person(Datum* bday, char gender, std::string name);
	~Person();
	static list<Person*> getFamily();		//gibt eine Referenz auf die Familie
	static void update();					//updatet die charaktere (status etc)
	static void loadChars();				//lädt die charaktere
	void hurt(int dmg);						//wurde nie benutzt
	enum status getStatus();				
	void psyDmg(int dmg);					//wurde nie benutzt
	string getName();					
	void setStatus(enum status set);		//ändert den Sstatus der charaktere
	static void displayFamily(RenderWindow* window);	//zeichnet alle charaktere nacheinander
	void loadVisualDisplay(int row);		//lädt die Bilder ein
	void render(RenderWindow* window);		//zeichnet die person
	static int getPresentCharactarAmount(); //Anzahl der anwesenden Charaktere
	//void calAge(Datum* date);
};

