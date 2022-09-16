#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>
#include <cctype>
#include "Header.h"
using namespace std;


LESSON InputLesson(void)
{
	setlocale(LC_ALL, "rus");
	LESSON lesson;
	cout << "ÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÄÈÑÖÈÏËÈÍÛ (ðóññêèìè áóêâàìè, íå áîëåå 35 ñèìâîëîâ, áåç ïðîáåëîâ) ======> ";
	cin >> lesson.LessonName;
	if (lesson.LessonName.size() > 35) { cout << "Íåêêîðåêòíûé ââîä" << endl; exit(-1); }
	for (int i = 0; i < lesson.LessonName.size(); i++) {
		if ('ÿ' < lesson.LessonName[i] || lesson.LessonName[i] < 'À') {
			cout << "Íåêêîðåêòíûé ââîä" << endl;	exit(-1);
		}
	}
	cout << "ÂÂÅÄÈÒÅ ÔÀÌÈËÈÞ ÏÐÅÏÎÄÀÂÀÒÅËß  (ðóññêèìè áóêâàìè, íå áîëåå 15 ñèìâîëîâ) ===> ";
	cin >> lesson.LastName;
	if (lesson.LastName.size() > 15) { cout << "Íåêêîðåêòíûé ââîä" << endl; exit(-1); }
	for (int i = 0; i < lesson.LastName.size(); i++) {
		if ('ÿ' < lesson.LastName[i] || lesson.LastName[i] < 'À') {
			cout << "Íåêêîðåêòíûé ââîä" << endl; exit(-1);
		}
	}
	cout << "ÂÂÅÄÈÒÅ ÈÌß ÏÐÅÏÎÄÀÂÀÒÅËß  (ðóññêèìè áóêâàìè, íå áîëåå 15 ñèìâîëîâ) =======> ";
	cin >> lesson.FirstName;
	if (lesson.FirstName.size() > 15) { cout << "Íåêêîðåêòíûé ââîä" << endl; exit(-1); }
	for (int i = 0; i < lesson.FirstName.size(); i++) {
		if ('ÿ' < lesson.FirstName[i] || lesson.FirstName[i] < 'À') {
			cout << "Íåêêîðåêòíûé ââîä" << endl; exit(-1);
		}
	}
	cout << "ÂÂÅÄÈÒÅ ÎÒ×ÅÑÒÂÎ ÏÐÅÏÎÄÀÂÀÒÅËß (ðóññêèìè áóêâàìè, íå áîëåå 15 ñèìâîëîâ) ===> ";
	cin >> lesson.MiddleName;
	if (lesson.FirstName.size() > 15) { cout << "Íåêêîðåêòíûé ââîä" << endl; exit(-1); }
	for (int i = 0; i < lesson.MiddleName.size(); i++) {
		if ('ÿ' < lesson.MiddleName[i] || lesson.MiddleName[i] < 'À') {
			cout << "Íåêêîðåêòíûé ââîä" << endl;	exit(-1);
		}
	}

	return lesson;
}
