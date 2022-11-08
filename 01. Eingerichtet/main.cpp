#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Ressource.h"


using namespace sf;
using namespace std;

int main() {

    RenderWindow window(VideoMode(1920 / 1.5, 1080 / 1.5), "Hold On!");
    window.setFramerateLimit(30);

    Ressource essen("Essen", 1);
    Ressource wasser("Wasser", 1);


    while (window.isOpen()) {

        window.clear();

        essen.darstellen(&window);
        wasser.darstellen(&window);

        window.display();

    }
}