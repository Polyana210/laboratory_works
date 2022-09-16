#include <iostream>

using namespace std;

// функци€ обмена значений элементов массива
void swap(int* a, int i, int j) 
{    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

bool NextSet(int* a, int n)
{
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false; // больше перестановок нет
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1; // сортируем оставшуюс€ часть последовательности
    while (l < r)
        swap(a, l++, r--);
    return true;
}
void Print(int* a, int n)  // вывод перестановки
{
    static int num = 1; // номер перестановки
    cout.width(3); // ширина пол€ вывода номера перестановки
    cout << num++ << ") ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "¬ведите натуральное число N = ";
    cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    Print(a, n);
    while (NextSet(a, n))
        Print(a, n);
    //cin.get(); cin.get();
    return 0;
}