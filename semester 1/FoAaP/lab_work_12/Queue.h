#pragma once
#include <iostream>
using namespace std;

struct Node1 {
	int d;
	Node1 *p;
};

Node1 *first1(int d);
void add(Node1 **pend, int d);
int del(Node1 **pbeg)