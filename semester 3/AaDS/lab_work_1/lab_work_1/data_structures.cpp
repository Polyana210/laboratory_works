#include "data_structures.h"
#include <iostream>
using namespace std;
void init_deque(deque* s, int n) {
	s->p = new int[n];
	s->size = n;
	s->pbeg = 0;
	s->pend = n;
}
int pop_begin_deque(deque* s) {
	int temp = s->p[s->pbeg];
	s->p[s->pbeg] = s->p[s->pbeg + 1];
	s->pbeg--;
	return temp;
}
int pop_end_deque(deque* s) {
	int temp = s->p[s->pend];
	s->p[s->pend] = s->p[s->pend - 1];
	s->pend++;
	return temp;
}
void push_begin_deque(deque* s, int i) {
	s->p[s->pbeg++] = i;
}
void push_end_deque(deque* s, int i) {
	s->p[s->pend--] = i;
}
void print_begin_deque(deque* s) {
	for (int i = 0; i < s->pbeg; i++)
		cout << s->p[i] << " ";
}
void print_end_deque(deque* s) {
	for (int i = s->pend + 1; i < s->size + 1; i++)
		cout << s->p[i] << " ";
	cout << endl;
}
void del_deque(deque* s) {
	delete[] s->p;
}
bool emptinnes_begin_deque(deque* s) {
	if (s->pbeg == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool emptinnes_end_deque(deque* s) {
	if (s->pend == s->size) {
		return true;
	}
	else {
		return false;
	}
}

void init_queue(queue* s, int n) {
	s->p = new int[n];
	s->size = n;
	s->pbeg = 0;
	s->pend = 0;
}
void push_begin_queue(queue* s, int i) {
	s->p[s->pbeg++] = i;
}
int pop_queue(queue* s) {
	int temp = s->p[s->pend];
	s->pbeg--;
	return temp;
}
void print_begin_queue(queue* s) {
	for (int i = s->pend; i < s->pbeg; i++)
		cout << s->p[i] << " ";
	cout << endl;
}
void del_queue(queue* s) {
	delete[] s->p;
}
bool emptiness_queue(queue* s) {
	if (s->pbeg == 0) {
		return true;
	}
	else {
		return false;
	}
}


void init_steck(steck* s, int n) {
	s->p = new int[n];
	s->size = n;
	s->top = 0;
}
void push(steck* s, int i) {
	s->p[s->top++] = i;
}
int pop(steck* s) {
	s->top--;
	int temp = s->p[s->top];
	int del = s->top + 1;
	s->p[s->top] = s->p[del];
	return temp;
}
void del_steck(steck* s) {
	delete[]s->p;
}
void pop_as(steck* s) {
	for (int i = s->top - 1; i >= 0; i--)
		cout << s->p[i] << " ";
	cout << endl;

}
bool emptiness_steck(steck* s) {
	if (s->top == 0) {
		return true;
	}
	else {
		return false;
	}
}