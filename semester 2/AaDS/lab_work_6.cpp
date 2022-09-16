#include <iostream>
#include <ctime>
using namespace std;

const int array_size = 1000;
int compare = 0;
int swaps = 0;

int* random(int* array) {
    for (int counter = 0; counter < array_size; counter++)
    {
        array[counter] = rand() % 50 - rand() % 50; // заполняем массив случайными значениями в диапазоне от -49 до 49 включительно
        //cout << array[counter] << " ";
    }
    return array;
}
int* increasing(int* array) {
    for (int counter = 0; counter < array_size; counter++)
    {
        array[counter] = counter; 
       // cout << array[counter] << " ";
    }
    return array;
}
int* decreasing(int* array) {
    for (int counter = 0; counter < array_size; counter++)
    {
        array[counter] = array_size - counter;
      //  cout << array[counter] << " ";
    }
    return array;
}

void SelectionSort(int* A) //сортировка выбором
{
    compare = 0;
    swaps = 0;
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < array_size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < array_size; j++)  // для остальных элементов после i-ого
        {
            compare++;
            if (A[j] < A[min]) // если элемент меньше минимального,
                min = j;       // запоминаем его индекс в min
        }
        temp = A[i];      // меняем местами i-ый и минимальный элементы
        A[i] = A[min];
        A[min] = temp;
        swaps++;
    }
}
void insertionSort(int* A) {
    compare = 0;
    swaps = 0;
    int j;
    for (int i = 1; i < array_size; i++)
    {
        int value = A[i];
        for (j = i - 1; (j >= 0); j--) {
            compare++;
            if (A[j] > value) {
                A[j + 1] = A[j];
            }
        }
        A[j + 1] = value;
        swaps++;
    }
}
void BubbleSort(int* A) {
    compare = 0;
    swaps = 0;
    for (int i = 1; i < array_size - 1; i++) {
        for (int k = 0; k < array_size - 1; k++) {
            compare++;
            if (A[k] > A[k + 1]) {
                int buf = A[k];
                A[k] = A[k + 1];
                A[k + 1] = buf;
                swaps++;
            }
        }
    }
}

int getNextGap(int gap){
    // Уменьшить разрыв по коэффициенту сжатия
    gap = (gap * 10) / 13;
    if (gap < 1) return 1;
     return gap;}
void HairbrushSort(int* A){
    compare = 0;
    swaps = 0;
    int gap = array_size;
    bool swapped = true;
    while (gap != 1 || swapped == true){
       gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < array_size - gap; i++){
            compare++;
            if (A[i] > A[i + gap]){
                swap(A[i], A[i + gap]);
                swaps++;
                swapped = true;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int array1[array_size]; 
    int array2[array_size];
    int array3[array_size];
    increasing(array1);
    decreasing(array2);
    random(array3);
    clock_t time, start, finish;
    start = clock();
    HairbrushSort(array1);
    //SelectionSort(array1);
    //insertionSort(array1);
    //BubbleSort(array1);
    finish = clock();
    time = finish - start;
    cout <<  endl <<"Возрастание"<<endl<< "COMPARE:" << compare << endl;
    cout << "SWAP:" << swaps << endl;
    cout << "TIME:" << time  << endl;

    start = clock();
   // SelectionSort(array2);
   //insertionSort(array2);
   // BubbleSort(array2);
    HairbrushSort(array2);
    finish = clock();
    time = finish - start;
    cout << endl<<"Убывание" << endl << "COMPARE:" << compare << endl;
    cout << "SWAP:" << swaps << endl;
    cout << "TIME:" << time  << endl;

    start = clock();
    //SelectionSort(array3);
    //insertionSort(array3);
    // BubbleSort(array3);
     HairbrushSort(array3);
    finish = clock();
    time = finish - start;
    cout << endl << "Рандом" << endl << "COMPARE:" << compare << endl;
    cout << "SWAP:" << swaps << endl;
    cout << "TIME:" << time  << endl;

    system("pause");
    
    return 0;
}
