#include "Queue.h"
//#include <iostream>
using namespace std;

Node1 *first1(int d) {
	Node1 *pv = new Node1;
	pv->d = d;
	pv->p = 0;
	return pv;
}

void add(Node1 **pend, int d) {
	Node1 *pv = new Node1;
	pv->d = d;
	pv->p = 0;
	(*pend)->p = pv;
	*pend = pv;
}

int del(Node1 **pbeg) {
	int temp = (*pbeg)->d;
	Node1 *pv = *pbeg;
	*pbeg = (*pbeg)->p;
	delete pv;
	return temp;
}