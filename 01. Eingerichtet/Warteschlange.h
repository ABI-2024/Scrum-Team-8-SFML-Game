#pragma once
class Warteschlange
{
private:
	static int warteschlange[10];
	static bool secure;
public:
	static int getFirst();
	static void forceNext(int);
	static void addQueue(int);//setzt das �bergebene Ereignis an die n�chste freie stelle
	static void forceAt(int index, int event); //setzt das gegebene Ereignis garantiert an die �bergebene Zeile
	static void queueAfter(int index, int event);
	static void lock();/*invertiert den status, ob die Warteschlange ver�ndert werden kann, was force methoden verhindert*/
};