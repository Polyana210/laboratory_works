#pragma once
#include <iostream>
using namespace std;

// ���� 

struct Node {
	int d;
	Node* p;
};

Node* first(int d);
void push(Node** top, int d);
int pop(Node** top);