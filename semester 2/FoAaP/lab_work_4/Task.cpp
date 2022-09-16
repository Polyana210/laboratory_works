/* Задание. В задачах 1 - 10 необходимо разработать заголовочный файл, содержащий
описание соответствующего класса, включающего все необходимые для решения
задачи данные и операторы (<< , >> и т.д.).
Определение функций-членов класса разместите в отдельном файле.
Предусмотрите обработку исключительных ситуаций.
Подготовьте программу, демонстрирующую работу с подготовленным классом.
10.Найдите разность и частное двух несократимых рациональных дробей.
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
    cout << "Введите первую дробь"<< endl;
    cin >> fraction1;
    cout << "Введите вторую дробь" << endl;
    cin >> fraction2;
           // выбрасывается исключение типа const char*

        // Если пользователь ввел положительное число, то выполняется операция и выводится результат
  
    
    cout << "Введенные Вами дроби: " << endl;
    cout << fraction1;
    cout << fraction2;

    cout << endl << "Разность данных дробей: " << endl;
    cout << fraction1 - fraction2;
    cout << endl << "Произведение данных дробей: " << endl;
    cout << fraction1 * fraction2;


    }
    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
    return 0;
}
