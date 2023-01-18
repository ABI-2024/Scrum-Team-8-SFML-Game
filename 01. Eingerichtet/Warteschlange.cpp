#include "Warteschlange.h"


int Warteschlange::warteschlange[10] = { 0,0,0,0,0,0,0,0,0,0 };
bool Warteschlange::secure = false;

void Warteschlange::addQueue(int add) {
	
	for (int i = 0; i < 9; i++) {
		if (warteschlange[i] == 0) {
			warteschlange[i] = add;
			break;
		}
	}
}
void Warteschlange::forceNext(int next) {
	if (!secure) {
		warteschlange[0] = next;
	}
	else {
		addQueue(next);
	}
}

int Warteschlange::getFirst() {

	int tmp = warteschlange[0];
	for (int i = 0; i < 9; i++) {
		warteschlange[i] = warteschlange[i + 1];
	}
	return tmp;
}

void Warteschlange::forceAt(int index, int event) {
	if (!secure) {
		warteschlange[index - 1] = event;
	}
	else {
		queueAfter(index, event);
	}
}

void Warteschlange::queueAfter(int index, int event) {
	for (int i = index-1; i < 9; i++) {
		if (warteschlange[i] == 0) {
			warteschlange[i] = event;
			break;
		}
	}
}

void Warteschlange::lock() {
	secure = !secure;
}