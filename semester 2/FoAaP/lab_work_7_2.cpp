/* Дана последовательность действительных чисел. Необходимо используя
алгоритм //сортировки вставками сформировать новую последовательность,
упорядоченную:
а) по возрастанию;
б) по убыванию.*/

#include <iostream>
#include <vector>
#include <iterator>
#include <windows.h>
using namespace std;


vector<double> Input_vector(vector<double>& v) {
	cout << "Введите последовательность дробных чисел  (конец ввода - Ctrl+Z)\n";

	istream_iterator<double> cin_iter(cin);
	istream_iterator<double> cin_end;

	while (cin_iter != cin_end) {
		double x = *cin_iter;
		v.push_back(x);
		cin_iter++;
	}
	return v;
}

void Output_vector(vector<double>& v, const char* Name) {
	cout << "Последовательность дробных чисел: "<<Name<<endl;
	vector<double>::iterator iter;
	iter = v.begin();
	while (iter < v.end()) {
		cout << *iter << "  ";
		iter++;
	}
	cout << endl;
}

template <typename Iterator>
void insertion_sort_increasing(Iterator first, Iterator last)
{
	if (!(first < last))
		return;

	for (Iterator i = first + 1; i != last; ++i)
		for (Iterator j = i; j != first && *j < *(j - 1); --j)
			iter_swap(j - 1, j);
}

template <typename Iterator>
void insertion_sort_decreasing(Iterator first, Iterator last)
{
	if (!(first < last))
		return;

	for (Iterator i = first + 1; i != last; ++i)
		for (Iterator j = i; j != first && *j > *(j - 1); --j)
			iter_swap(j - 1, j);
}

int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		vector<double> v;
		Input_vector(v);
		Output_vector(v, "ИСХОДНАЯ");
		insertion_sort_increasing(v.begin(), v.end());
		Output_vector(v, "ПО ВОЗРАСТАНИЮ");
		insertion_sort_decreasing(v.begin(), v.end());
		Output_vector(v, "ПО УБЫВАНИЮ");
	}
	catch (const char* exception)
	{
		std::cerr << "ОШИБКА: " << exception << '\n';
	}
	system("pause");
	return 0;
}