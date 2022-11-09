#pragma once

#include "stdafx.h"

using namespace std;
using namespace sf;


class Ressource
{
private:
	static int typc;
	int typ;
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
	void darstellen(RenderWindow*);

};

