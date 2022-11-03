#include "stdafx.h"
#include "Textausgabe.h"


using namespace sf;
using namespace std;

int main() {
    Textausgabe whatever;
    RenderWindow window(VideoMode(1920 / 2, 1080 / 2), "Hold On!");
    window.setFramerateLimit(30);

    while (window.isOpen()) {



        window.clear();

        window.display();
    }
}