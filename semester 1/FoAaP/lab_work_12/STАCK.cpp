#include "Stàck.h"
#include <iostream>
using namespace std;

Node* first(int d) {
	Node* pv = new Node;
	pv->d = d;
	pv->p = 0;
	return pv;
}

void push(Node** top, int d) {
	Node* pv = new Node;
	pv->d = d;
	pv->p = *top;
	*top = pv;
}

int pop(Node** top) {
	int temp = (*top)->d;
	Node* pv = *top;
	*top = (*top)->p;
	delete pv;
	return temp;
}
