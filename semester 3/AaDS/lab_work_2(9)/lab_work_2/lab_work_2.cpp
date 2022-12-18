/*TASK: private hashing
sum of squares of digits
quadratic probing
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#define ELEM_NUM 11000 //size of the hash table
#define N 1000 //amount of numbers
using namespace std;

struct list {
	int data;
	struct list* ptr;
	bool flag;
};

int hashf(int num);
void hesh_search(struct list* hash_table);
int main() {
	setlocale(LC_ALL, "Rus");
	clock_t start, finish, start1, finish1;
	list hash_table[ELEM_NUM];
	for (int i = 0; i < ELEM_NUM; i++) {
		hash_table[i].data = 0;
		hash_table[i].ptr = NULL;
		hash_table[i].flag = true;
	}

	int num;
	int hash;

// Add first 1000 elements
	start = clock();
	for (int i = 0; i < 1000; i++) {
		num = rand() % 100 + 1;
		hash = hashf(num);
		if (hash_table[hash].flag == true) { 
			hash_table[hash].flag = false;
			hash_table[hash].data = num;

		}
		else {
			int a = hash; int i = 1;
			while (hash_table[a].flag == false) {
				a = hash + i * 1 + i * i * 1;
				i += 1;
			}
			hash_table[a].flag = false;
			hash_table[a].data = num;
		}
	}
	finish = clock();
	cout << "TIME: Add first 1000: " << (finish - start) / 1000 << endl;


//Add elements range 1001- N-1000
		for (int i = 1000; i < N - 1000; i++) {
			num = rand() % 100 + 1;
			if (hash_table[hash].flag == true) {
				hash_table[hash].flag = false;
				hash_table[hash].data = num;

			}
			else {
				int a = hash; int i = 1;
				while (hash_table[a].flag == false) {
					a = hash + i * 1 + i * i * 1;
					i += 1;
				}
				hash_table[a].flag = false;
				hash_table[a].data = num;
			}
		}


//Add last 1000 elements
	start1 = clock();
	for (int i = N-1000; i < N; i++) {
		num = rand() % 100 + 1;
		hash = hashf(num);
		if (hash_table[hash].flag == true) {
			hash_table[hash].flag = false;
			hash_table[hash].data = num;

		}
		else {
			int a = hash; int i = 1;
			while (hash_table[a].flag == false) {
				a = hash + i * 1 + i * i * 1;
				i += 1;
			}
			hash_table[a].flag = false;
			hash_table[a].data = num;
		}
	}
	finish1 = clock();
	cout << "TIME: Add last 1000: " << (finish1 - start1) / 1000 << endl;
	
	clock_t start2, finish2;
	start2 = clock();
	hesh_search(hash_table);
	finish2 = clock();
	cout << "TIME: Search element: " << (finish2 - start2) / 1000 << endl;
	return 0;
}

int hashf(int num) {
	int sum = 0;
	while (num > 0) {
		sum += (num % 10)* (num % 10);
		num /= 10;
	}
	return sum;
}


void hesh_search(struct list* hash_table) {
	int key, hash=0;
	struct list* lptr = hash_table;
	cout << "Enter number to search: ";
	cin >> key;
	hash = hashf(key);
	int a = hash; int i = 1;
	while (lptr[a].data != key && a<ELEM_NUM)
	{
			a = hash + i * 1 + i * i * 1;
			i += 1;
	}
	if (a >= ELEM_NUM) {
		cout << "Number not found"; return;
	}
	else {
		cout << "\nHash: " << a <<  " Number: " << key << endl;
		return;
	}
}