/* ����� ��������� ������������������, ������������� ����� ������ � ������
�������������� ����������.*/

#include <iostream>
#include <vector>
#include <iterator>
#include <windows.h>
using namespace std;


vector<double> Input_vector(vector<double> &v) {
	cout << "������� ������������������ ������� �����  (����� ����� - Ctrl+Z)\n";

	istream_iterator<double> cin_iter(cin);
	istream_iterator<double> cin_end;

	while (cin_iter != cin_end) {
		double x = *cin_iter;
		v.push_back(x);
		cin_iter++;
	}
	return v;
}

void Output_vector(vector<double>& v) {
	cout << "������������������ ������� �����:\n";
	vector<double>::iterator iter;
	iter = v.begin();
	while (iter < v.end()) {
		cout << *iter << "  ";
		iter++;
	}
}

double Summ(vector<double>& v) {
	vector<double>::iterator ir; // �������� ��������
	vector<double>::iterator it = v.end(); // �������� ������� �������������� ��������
	vector<double>::iterator in = v.begin(); // �������� ������� �������������� ��������
	int m = 0;
	double sum = 0;
	ir = v.begin();
	while (ir < v.end()) {
		if (*ir > 0 && m == 0) {
			it = ir;  m++;
		}
		else	if (*ir > 0 && m == 1) { in = ir; m++; }
		if (m == 2) break;
		ir++;
	}
	if (it == v.end() || in == v.begin()) throw "� ������������������ ��� ���� ������������� ��������";

	while (it <= in) { 
		sum += *it;
		it++; 
	}
	return sum;
}

int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		vector<double> v;
		Input_vector(v);
		Output_vector(v);
		cout << endl <<"C���� ��������� ������������������ ����� ������ � ������ �������������� ����������: "<< endl  << Summ(v) << endl;

	}
	catch (const char* exception)
	{
		std::cerr << "������: " << exception << '\n';
	}
	system("pause");
	return 0;
}