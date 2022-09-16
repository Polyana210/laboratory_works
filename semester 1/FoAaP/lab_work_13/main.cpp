#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
	int  k = 1;
	setlocale(LC_ALL,"rus");
	cout << "Введите количество элементов бинарного дерева: ";
	int n;
	cin >> n;
	int *b = new int[n];
	cout << "Введите элементы бинарного дерева: ";
	for (int i = 0; i < n; i++) cin>>b[i];
	TREE *top;
	first(top, b[0]);
	for (int i = 1; i < n; i++)
		add(top, b[i]);
	cout << endl;
	print_tree_level(top, 0);
	
	double sum = top->d;
	while (top->left) {
		top = top->left;
		sum += top->d;
		k++;
	}
	double m=sum/k;
	cout << "Cреднее арифметическое значений в тех узлах, которые лежат на пути от корня до узла с минимальным элементом равно " <<m<<endl;
	cout << "Ответ: " << m << endl;

	del_tree(top);
	cout << endl;
	delete[]b;
	system("pause");
	return 0;
}




