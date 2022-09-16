/* 9.	�������� ��������� ����� ���� � ����������. 
�������� � ������ ��������: ������� � �������� ������, ��������, ��� �������, ���������� ����������� ������ ����� � ����������.
��������� ������ ������������ ����� � ������� ���� � ���������� ����� �� ��������� �������:              
� ���������� ������ � ������, ����� ����������� � ����������; 
� �������� ������ � ����������� ������; 
� ������ �������� � ���� ������, ������������� �� �������� �������;
� ������ �������� � ���� ������, ������������� �� ����� �������. 
�������� ������ ������������ � ����������� ������������� ������ multimap, � �������� ����� ������������ �������� ������.*/

#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
#include <locale.h>
#include<string.h>
#include<map>
#include<conio.h>
#include<string>
#include <windows.h>
using namespace std;

// �������� �� ����� ����� 
bool Check_123(string b, int k, int n) {
	if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "������������ ����"; }
	for (int i = 0; i < b.size(); i++) {
		if (b[i] < '0' || b[i] > '9') {
			throw "������������ ����";
		}
	}
	return 1;
}

// ����� ����������
class Library {
	multimap<string, pair<string, pair<int, int>>> data;
public:
	
	// ���������� ����
	void push_data() {
		int n;    // ���������� ���� ��� ����������
		cout << "������� ���� ������ ��������: ";
		cin >> n;
		string name;   // ������� ������
		string title;  // �������� �����
		int year;      // ��� �������
		int instance;  // ���������� �����������
		string temp; 
		for (int i = 0; i < n; i++) {
			cout << "������� ������� ������: ";
			cin >> name;
			cout << "�������� �����: ";
			cin >> title;
			cout << "��� �������: ";
			cin >> temp;
			if (Check_123(temp, 1900, 2022)) year = atoi(temp.c_str());
			cout << "���������� ����������� ������ ����� � ����������: ";
			cin >> temp;
			if (Check_123(temp, 0, 100000))  instance = atoi(temp.c_str());
			data.emplace(name, pair<string, pair<int, int>>(title, pair<int, int>(year, instance)));
		}
	}

	// �������� �����
	void remove() {
		string name;
		string title;
		cout << "������� ������� � �������� ������: ";
		cin >> name;
		cout << "������� �������� �����: ";
		cin >> title;
		int temp = 0;
		multimap<string, pair<string, pair<int, int>>>::iterator p;
		for (multimap<string, pair<string, pair<int, int>>>::iterator i = data.begin(); i != data.end(); i++) {
			if (i->first == name && i->second.first == title) {
				p = i;
				temp++;
				break;
			}
		}
		if (temp) {
			cout << "������� ������" << endl;
			data.erase(p);
		}
		else {
			cout << "������� �� ������" << endl;
		}
	}

	//����� ���������� � �����
	void output() {
		for (multimap<string, pair<string, pair<int, int>>>::iterator i = data.begin(); i != data.end(); i++) {
			cout << "������� ������: " << i->first << "\n�������� �����: " << i->second.first << "\n��� �������: " << i->second.second.first << "\n���������� �����������: " << i->second.second.second << endl << endl;
		}
	}

	//���������� ���� �� ����
	void sort_year() {
		multimap<string, pair<string, pair<int, int>>>::iterator i = data.begin();
		vector<int> g;
		for (; i != data.end(); i++) {
			g.push_back(i->second.second.first);
		}
		sort(g.begin(), g.end());
		i = data.begin();
		unsigned int h = 0;
		while (h != g.size()) {
			for (; i != data.end(); i++) {
				if (g[h] == i->second.second.first) {
					cout << "������� ������: " << i->first << "\n�������� �����: " << i->second.first << "\n��� �������: " << i->second.second.first << "\n���������� �����������: " << i->second.second.second << endl << endl;
					break;
				}
			}
			i = data.begin();
			h++;
		}
	}
};



int main() {
	try {
		setlocale(LC_ALL, "rus");
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		Library lib;
		int n;
		do {
			system("cls");
			cout << "=========================== ���������� ===============================" << endl;
			cout << " �������� ��������:" << endl;
			cout << " 1) ���������� �����." << endl;
			cout << " 2) �������� �����." << endl;
			cout << " 3) ������ �������� � ���� ������, ������������� �� �������� �������." << endl;
			cout << " 4) ������ �������� � ���� ������, ������������� �� ����� �������." << endl;
			cout << endl << " 0) �����" << endl;
			cout << "======================================================================= " << endl;
			cin >> n;
			switch (n) {
			case 1:
				system("cls");
				lib.push_data();
				break;
			case 2:
				system("cls");
				lib.remove();
				_getch();
				_getch();
				break;
			case 3:
				system("cls");
				lib.output();
				_getch();
				_getch();
				break;
			case 4:
				system("cls");
				lib.sort_year();
				_getch();
				_getch();
				break;
			}
		} while (n != 0);
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
		system("pause");
		return 0;
}