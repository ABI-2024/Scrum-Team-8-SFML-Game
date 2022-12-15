#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Ressource.h"

string EndCheck(Ressource essen, Ressource wasser) {
	if (essen.getmenge() <= 0) { //prüfen, ob Nahrung alle ist
		return "Nahrung";		 // ist dies der Fall wird Nahrung bzw. Wasser zurückgegeben
	}

	else if (wasser.getmenge() <= 0) { //prüfen, ob Wasser alle ist
		return "Wasser";
	}


}