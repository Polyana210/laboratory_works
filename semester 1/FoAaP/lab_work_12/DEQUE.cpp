#include "Deque.h"
#include <iostream>
using namespace std;

Node2* front(int d) {
	Node2* pv = new Node2;
	pv->d = d;
	pv->p = 0;
	return pv;
}

void push_back(Node2** beg, int d) {
	Node2* pv = new Node2;
	pv->d = d;
	pv->p = *beg;
	*beg = pv;
}

int pop_back(Node2** beg) {
	int temp = (*beg)->d;
	Node2* pv = *beg;
	*beg = (*beg)->p;
	delete pv;
	return temp;
}
