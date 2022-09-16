#include <iostream>
#include "Header.h"
using namespace std;

void first(TREE *&top, int d) {
	top = new TREE;
	top->d = d;
	top->left = top->right = NULL;
}

TREE *search(TREE *top, int d) {
	TREE *pv = top, *ppv = pv;
	while (pv) {
		ppv = pv;
		if (d < pv->d) pv = pv->left;
		else pv = pv->right;
	}
	return ppv;
}

void add(TREE *top, int d) {
	TREE *ppv, *pnew = new TREE;
	pnew->d = d;
	pnew->left = NULL;
	pnew->right = NULL;
	ppv = search(top, d);
	if (d < ppv->d) ppv->left = pnew;
	else ppv->right = pnew;
}

void print_tree_level(TREE *top, int level) {
	if (top) {
		print_tree_level(top->left, level + 1);
		for (int i = 0; i < level; i++)
			cout << "       ";
		cout << top->d << endl;
		print_tree_level(top->right, level + 1);
	}
}

void del_tree(TREE *&top) {
	if (top) {
		del_tree(top->left);
		del_tree(top->right);
		delete top;
		top = NULL;
	}
}
