#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Ressource.h"

string EndCheck(Ressource essen, Ressource wasser) {
	if (essen.getmenge() <= 0) { //pr�fen, ob Nahrung alle ist
		return "Nahrung";		 // ist dies der Fall wird Nahrung bzw. Wasser zur�ckgegeben
	}

	else if (wasser.getmenge() <= 0) { //pr�fen, ob Wasser alle ist
		return "Wasser";
	}


}