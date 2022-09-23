#include <iostream>
#include "data_structures.h"
#include <string>
#include <Windows.h>
using namespace std;

void print_names() {
	cout << endl << " 1 - first type of product" << endl
		<< " 2 - second type of product" << endl
		<< " 2 - third type of product" << endl
		<< " 4 - robot" << endl
		<< " 5 - finished product" << endl << endl;
}

int main() {
	setlocale(0, "");
	int time = 1000;

	steck* container_1 = new steck;
	steck* container_2 = new steck;
	steck* container_3 = new steck;

	init_steck(container_1, 100);
	for (int i = 0; i < 6; i++) {
		push(container_1, 1);
	}

	init_steck(container_2, 100);
	for (int i = 0; i < 6; i++) {
		push(container_2, 2);
	}

	init_steck(container_3, 100);
	for (int i = 0; i < 6; i++) {
		push(container_3, 3);
	}

	queue* robots = new queue;
	init_queue(robots, 5);
	for (int i = 0; i <= 5; i++) {
		push_begin_queue(robots, 4);
	}

	deque* sorting_tape = new deque;
	init_deque(sorting_tape, 100);
	for (int i = 0; i < 5; i++) {
		push_begin_deque(sorting_tape, 5);
		push_end_deque(sorting_tape, 5);
	}

	while (true) {
		int t = rand() % 7;
		for (int i = 0; i < 1; i++) {
			system("cls");
			if (emptiness_steck(container_1) || emptiness_steck(container_2) || emptiness_steck(container_3)) {
				continue;
			}
			pop(container_1);
			pop(container_2);
			pop(container_3);
			print_names();
			cout << " Container 1: ";
			pop_as(container_1);
			cout << " Container 2: ";
			pop_as(container_2);
			cout << " Container 3: ";
			pop_as(container_3);
			int robot = pop_queue(robots);
			cout << " Robots: ";
			print_begin_queue(robots);

			cout << " Sorting_tape: ";
			print_begin_deque(sorting_tape);
			cout << " ";
			print_end_deque(sorting_tape);
			Sleep(time);
		}

		int g = rand() % 7;
		for (int i = 0; i < g; i++) {
			system("cls");
			print_names();
			cout << " Container 1: ";
			pop_as(container_1);
			cout << " Container 2: ";
			pop_as(container_2);
			cout << " Container 3: ";
			pop_as(container_3);
		
			
			if (emptiness_queue(robots)) {
				 continue;
			}
			int temp = pop_queue(robots);
			

			cout << " Robots: ";
			print_begin_queue(robots);
			if (rand() % 2) {
				push_begin_deque(sorting_tape, 5);
			}
			else {
				push_end_deque(sorting_tape, 5);
			}

			push_begin_queue(robots, temp);
			cout << " Sorting_tape: ";
			print_begin_deque(sorting_tape);
			cout << " ";
			print_end_deque(sorting_tape);
			Sleep(time);
		}
		int h = rand() % 7;
		for (int i = 0; i < h; i++) {
			system("cls");
			if (rand() % 2) {
				if (emptinnes_begin_deque(sorting_tape)) {
					continue;
				}
				pop_begin_deque(sorting_tape);
			}
			else {
				if (emptinnes_end_deque(sorting_tape)) {
					continue;
				}
				pop_end_deque(sorting_tape);
			}
			int h1 = rand() % 4;
			for (int i=0; i<h1; i++) push(container_1, 1);
			h1 = rand() % 4;
			for (int i = 0; i < h1; i++) push(container_2, 2);
			h1 = rand() % 4;
			for (int i = 0; i < h1; i++) push(container_3, 3);
			print_names();
			cout << " Container 1: ";
			pop_as(container_1);
			cout << " Container 2: ";
			pop_as(container_2);
			cout << " Container 3: ";
			pop_as(container_3);
			cout << " Robots: ";
			print_begin_queue(robots);
			cout << " Sorting_tape: ";
			print_begin_deque(sorting_tape);
			cout << " ";
			print_end_deque(sorting_tape);
			Sleep(time);
		}
	}

	system("pause");
	return 0;
}
