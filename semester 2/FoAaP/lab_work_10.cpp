/* 9.	Написать программу учета книг в библиотеке. 
Сведения о книгах содержат: фамилию и инициалы автора, название, год издания, количество экземпляров данной книги в библиотеке.
Программа должна обеспечивать выбор с помощью меню и выполнение одной из следующих функций:              
• добавление данных о книгах, вновь поступающих в библиотеку; 
• удаление данных о списываемых книгах; 
• выдача сведений о всех книгах, упорядоченных по фамилиям авторов;
• выдача сведений о всех книгах, упорядоченных по годам издания. 
Хранение данных организовать с применением контейнерного класса multimap, в качестве ключа использовать «фамилию автора».*/

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

// Проверка на целое число 
bool Check_123(string b, int k, int n) {
	if (atoi(b.c_str()) > n || atoi(b.c_str()) < k) { throw  "Неккоректный ввод"; }
	for (int i = 0; i < b.size(); i++) {
		if (b[i] < '0' || b[i] > '9') {
			throw "Неккоректный ввод";
		}
	}
	return 1;
}

// класс библиотека
class Library {
	multimap<string, pair<string, pair<int, int>>> data;
public:
	
	// добавление книг
	void push_data() {
		int n;    // количество книг для добавления
		cout << "Сколько книг хотите добавить: ";
		cin >> n;
		string name;   // Фамилия автора
		string title;  // Название книги
		int year;      // год издания
		int instance;  // количество экземпляров
		string temp; 
		for (int i = 0; i < n; i++) {
			cout << "Введите фамилию автора: ";
			cin >> name;
			cout << "Название книги: ";
			cin >> title;
			cout << "Год издания: ";
			cin >> temp;
			if (Check_123(temp, 1900, 2022)) year = atoi(temp.c_str());
			cout << "Количество экземпляров данной книги в библиотеке: ";
			cin >> temp;
			if (Check_123(temp, 0, 100000))  instance = atoi(temp.c_str());
			data.emplace(name, pair<string, pair<int, int>>(title, pair<int, int>(year, instance)));
		}
	}

	// удаление книги
	void remove() {
		string name;
		string title;
		cout << "Введите Фамилия и инициалы автора: ";
		cin >> name;
		cout << "Введите название книги: ";
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
			cout << "Элемент удален" << endl;
			data.erase(p);
		}
		else {
			cout << "Элемент не удален" << endl;
		}
	}

	//вывод информации о книге
	void output() {
		for (multimap<string, pair<string, pair<int, int>>>::iterator i = data.begin(); i != data.end(); i++) {
			cout << "Фамилия автора: " << i->first << "\nНазвание книги: " << i->second.first << "\nГод издания: " << i->second.second.first << "\nКоличество экземпляров: " << i->second.second.second << endl << endl;
		}
	}

	//сортировка книг по году
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
					cout << "Фамилия автора: " << i->first << "\nНазвание книги: " << i->second.first << "\nГод издания: " << i->second.second.first << "\nКоличество экземпляров: " << i->second.second.second << endl << endl;
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
			cout << "=========================== БИБЛИОТЕКА ===============================" << endl;
			cout << " Выберите действие:" << endl;
			cout << " 1) Добавление книги." << endl;
			cout << " 2) Удаление книги." << endl;
			cout << " 3) Выдача сведений о всех книгах, упорядоченных по фамилиям авторов." << endl;
			cout << " 4) Выдача сведений о всех книгах, упорядоченных по годам издания." << endl;
			cout << endl << " 0) Выход" << endl;
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