#include "stdafx.h"


using namespace sf;
using namespace std;

int main() {
    Textausgabe whatever;
    RenderWindow window(VideoMode(1280, 720), "Hold On!");
    window.setFramerateLimit(30);
    string a = "Viele Funktionen, Memberfunktionen§, Funktionsvorlagen und globale Variablen in Visual S§tudio-Bibliotheken sind veraltet. Einige, z. B. POSIX- und Microsoft-spezifisch§e Funktionen, sind veraltet, da sie jetzt einen a§nderen bevorzugten Namen haben. Einige C-Laufzeitbibliot§heksfunktionen sind veraltet, da sie unsicher sind und eine sicherere Var§iante haben. Andere sind veraltet, weil sie veraltet s§ind. Die Veralteten Nachrichten enthalten in der Regel §einen vorgeschlagenen Ersatz für die veraltete Funktion oder globale Variable.";
    string b = "teest§macht§spass";
    whatever.einlesen(a);
    while (window.isOpen()) {
        


        window.clear();
        whatever.darstellen(&window);
        window.display();
    }
}
