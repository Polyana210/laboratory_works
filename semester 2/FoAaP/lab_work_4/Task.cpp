/* �������. � ������� 1 - 10 ���������� ����������� ������������ ����, ����������
�������� ���������������� ������, ����������� ��� ����������� ��� �������
������ ������ � ��������� (<< , >> � �.�.).
����������� �������-������ ������ ���������� � ��������� �����.
������������� ��������� �������������� ��������.
����������� ���������, ��������������� ������ � �������������� �������.
10.������� �������� � ������� ���� ������������ ������������ ������.
*/
#include <windows.h>
#include "Header.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");
    Fraction fraction1;
    Fraction fraction2;
try 
    {
    cout << "������� ������ �����"<< endl;
    cin >> fraction1;
    cout << "������� ������ �����" << endl;
    cin >> fraction2;
           // ������������� ���������� ���� const char*

        // ���� ������������ ���� ������������� �����, �� ����������� �������� � ��������� ���������
  
    
    cout << "��������� ���� �����: " << endl;
    cout << fraction1;
    cout << fraction2;

    cout << endl << "�������� ������ ������: " << endl;
    cout << fraction1 - fraction2;
    cout << endl << "������������ ������ ������: " << endl;
    cout << fraction1 * fraction2;


    }
    catch (const char* exception) // ���������� ���������� ���� const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}
