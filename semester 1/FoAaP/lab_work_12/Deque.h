#pragma once
#pragma once
#include <iostream>
using namespace std;

struct Node2 {
	int d;
	Node2* p;
};

void push_back(Node2** beg, int d);
int pop_back(Node2** beg);
Node2* front(int d);