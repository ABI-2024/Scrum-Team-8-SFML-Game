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
void Warteschlange::forceNext(int next) { //in work r8 now
	if (!secure) {
		int tmp = 0;
		for (int i = -1; i < 9; i++) {
			if (warteschlange[i + 1] == 0) {
				warteschlange[i + 1] = next;
			}
			else {
				next = warteschlange[i + 1];
				warteschlange[i + 1] = next;
				next = tmp;
			}
		}
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
	warteschlange[9] = 0;
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
	for (int i = index - 1; i < 9; i++) {
		if (warteschlange[i] == 0) {
			warteschlange[i] = event;
			break;
		}
	}
}

void Warteschlange::lock() {
	secure = !secure;
}