#pragma once
#include <iostream>
using namespace std;
struct TREE {
	int d;
	TREE *left;
	TREE *right;
};

void first(TREE *&, int);
TREE *search(TREE *, int);
void add(TREE *, int);
void print_tree_level(TREE *, int);
void del_tree(TREE *&top);