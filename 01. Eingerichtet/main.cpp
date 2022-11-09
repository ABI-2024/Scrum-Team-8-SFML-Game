#include "stdafx.h"

using namespace sf;
using namespace std;


int main() {
    Textausgabe txtausgabe;
    Datum Date(1, 1, 1999, 1);
    
    RenderWindow window(VideoMode(1280, 720), "Hold On!");
    window.setFramerateLimit(30);

    Ressource essen("Essen", 1);
    Ressource wasser("Wasser", 1);
 
    while (window.isOpen()) {




        while (window.isOpen()) {

            window.clear();

            Date.display(&window);
            essen.darstellen(&window);
            wasser.darstellen(&window);
            if (!txtausgabe.display(&window)) {
                txtausgabe.einlesen(newevent());
            }

            window.display();

        }
    }
}