#pragma once
class Warteschlange
{
private:
	static int warteschlange[50];
	static bool secure;
public:
	static int getFirst();
	static void forceNext(int);//wird als nächstes abgespielt
	static void addQueue(int);//setzt das übergebene Ereignis an die nächste freie stelle
	static void forceAt(int index, int event); //setzt das gegebene Ereignis garantiert an die übergebene Zeile
	static void queueAfter(int index, int event); //reiht nach dem index ein
	static void lock();/*invertiert den status, ob die Warteschlange verändert werden kann, was force methoden verhindert*/
};