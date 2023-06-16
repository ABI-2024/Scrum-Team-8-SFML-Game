#include "renderwindow.h"


sf::RenderWindow* renderwindow::window = nullptr;

void renderwindow::setWindow(sf::RenderWindow* iwindow) {
	window = iwindow;
}

sf::RenderWindow* renderwindow::getWindow() {
	return window;
}