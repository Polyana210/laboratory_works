#pragma once

struct deque {
	int size;
	int* p;
	int pend;
	int pbeg;
};

void init_deque(deque* s, int n);
int pop_begin_deque(deque* s);
int pop_end_deque(deque* s);
void push_begin_deque(deque* s, int i);
void push_end_deque(deque* s, int i);
void print_begin_deque(deque* s);
void print_end_deque(deque* s);
void del_deque(deque* s);
bool emptinnes_begin_deque(deque* s);
bool emptinnes_end_deque(deque* s);


struct queue {
	int size;
	int* p;
	int pend;
	int pbeg;
};
void init_queue(queue* s, int n);
void push_begin_queue(queue* s, int i);
int pop_queue(queue* s);
void print_begin_queue(queue* s);
void del_queue(queue* s);
bool emptiness_queue(queue* s);

struct steck {
	int size;
	int* p;
	int top;
};

void init_steck(steck* s, int n);
void push(steck* s, int i);
int pop(steck* s);
void del_steck(steck* s);
void pop_as(steck* s);
bool emptiness_steck(steck* s);