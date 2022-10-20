#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>


using namespace sf;
using namespace std;

int main() {

    RenderWindow window(VideoMode(1920 / 2, 1080 / 2), "Hold On!");
    window.setFramerateLimit(30);

    while (window.isOpen()) {



        window.clear();
        window.display();
    }
}