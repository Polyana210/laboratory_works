#include <iostream>
#include "Stаck.h"
#include "Queue.h"
#include "Deque.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	
	int a, n, N;
	bool res1 = 1, res2 = 1;
	cout << "Введите количество элементов последовательности: ";
	cin >> N;
	cout << "Введите 1 элемент последовательности:";
	cin >> n;
	Node* top = first(n);
	Node1 *pbeg = first1(n);
	Node1 *pend = pbeg;
	Node2* beg = front(n);
	for (int i = 2; i <= N; i++) {
		cout << "Введите " << i << " элемент последовательности: ";
		cin >> a;
		push(&top, a);
		add(&pend, a);
		push_back(&beg, a);
	}

	cout << endl << "Реализация с помощью очереди:" << endl;
	int fir = 1, second = 1;
	for (int i = 0; i < N; i++) {
		fir = del(&pbeg);
		if (i == 0) {
			second = fir;
			continue;
		}
		if (second > fir) {
			res1 = false;
			second = fir;
		}
		else if (second < fir)
		{
			res2 = false;
			second = fir;
		}
		else {
			res1 = 0;
			res2 = 0;
		}
	}
	if (res1 == 1) cout << "Последовательность возрастает" << endl;
	else {
		if (res2 == 1) cout << "Последовательность убывает" << endl;
		else cout << "Последовательность не упорядоченная" << endl;
	}



	cout << endl << "Реализация с помощью стека:" << endl;
	int last = 1, pre_last = 1;
	for (int i = 0; i < N; i++) {
		last = pop(&top);
		if (i == 0) {
			pre_last = last;
			continue;
		}
		if (pre_last < last) {
			res1 = false;
			pre_last = last;
		}
		else if (pre_last > last)
		{
			res2 = false;
			pre_last = last;
		}
		else {
			res1 = 0;
			res2 = 0;
		}
	}
	if (res1 == 1 ) cout << "Последовательность возрастает"<<endl;
	else {
		if (res2 == 1) cout << "Последовательность убывает" << endl;
		else cout << "Последовательность не упорядоченная" << endl;
	}

	cout << endl << "Реализация с помощью дека:" << endl;
	int last1 = 1, pre_last1 = 1;
	for (int i = 0; i < N; i++) {
		last1 = pop_back(&beg);
		if (i == 0) {
			pre_last1 = last1;
			continue;
		}
		if (pre_last1 < last1) {
			res1 = false;
			pre_last1 = last1;
		}
		else if (pre_last1 > last1)
		{
			res2 = false;
			pre_last1 = last1;
		}
		else {
			res1 = 0;
			res2 = 0;
		}
	}
	if (res1 == 1) cout << "Последовательность возрастает" << endl;
	else {
		if (res2 == 1) cout << "Последовательность убывает" << endl;
		else cout << "Последовательность не упорядоченная" << endl;
	}

	system("pause");
	return 0;
}


