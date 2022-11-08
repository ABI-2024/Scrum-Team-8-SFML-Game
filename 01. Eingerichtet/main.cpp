#include "stdafx.h"


using namespace sf;
using namespace std;

int main() {
	Textausgabe txtausgabe;
	Datum Date(1, 1, 1999, 1);
	Date = Datum();
	RenderWindow window(VideoMode(1280, 720), "Hold On!");
	window.setFramerateLimit(30);


	while (window.isOpen()) {

		

		window.clear();
		Date.display(&window);
		txtausgabe.display(&window);
		window.display();
	}
}
