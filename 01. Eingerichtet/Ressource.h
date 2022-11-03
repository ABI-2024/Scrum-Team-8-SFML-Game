#pragma once

#include <string>
#include <iostream>

using namespace std;


class Ressource
{
private:
	string name;
	float menge;

public:

	~Ressource();
	Ressource(string, float);
	float getmenge();
	string getname();
	void setname(string);
	void setmenge(float);
	void addmenge(float);

};

