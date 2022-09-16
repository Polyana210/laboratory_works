/* ����������� �������� ������ � ����� ����� (����� ��� ���� ���������).
��������. ������ ������, ��������� ����� "�������� � ��������"
������� ������ ����� ����� �������� "���� � ������" �� ��������� ������ �������. 
�� ������ �������� ������ ����� � ��������� ���� �� ��������� ���������� � ����� �� ������� � ��������� ���� �� ��������� ����������. 
���������� � ����� ����  �� ����� ������, � ����� �������, ����� �������� ������������ �������. 
�� ���� �������� ������ �� ���������� ����� � ������ ����. �� ����� ������ ���� 2 ���� (��� ������� �������) � ���������� �������.*/

#include <iostream>
#include <string>
using namespace std;
int Date_1;  // ���������� ��� ��� �������
int Date_2;  // ���������� ��� ��� �������

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

// ������ ������������ ����� ����� ���������� ������������������
int Case_3(int* arr, int a, int b, int n){
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = b; i >= a; i--){
        sum = sum + arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = b + 1; i <= n; i++){
        sum = sum + arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
}

// ������ ������������ ������������ ������� � �������� ������������������
int Case_1_2(int* arr, int l, int h){  
    if (l == h) return arr[l];
    int m = (l + h) / 2;
    int MAX = max(Case_1_2(arr, l, m),  Case_1_2(arr, m + 1, h),  Case_3(arr, l, m, h));
    return MAX;
}

// ����� �������� ����
int Poisk_Day(int* arr, int n, int MAX) {
    for (int i = 0; i <= n; i++) {
        int sum = arr[i];
        for (int j = i+1; j <= n; j++) {
            if (sum == MAX) {
                Date_1 = i; Date_2 = i + 2; return 0;
            }
            else sum += arr[j];
            if (sum == MAX) {
                Date_1 = i+1; Date_2 = j + 2; return 0;
            }
        }
    }
    return -1;
}


int main() {
    try{
	setlocale(LC_ALL, "rus");
	string days;
    cout << "������� ���������� ���� (����������� ����� �� 3 �� 366)  ";
	cin >> days;
	int Days = atof(days.c_str());
    if (Days <= 0) throw "��� ������ ����!!!";
    if (Days <=2 && Days>0) throw "���� ������ ���� ������ 2!!!";
    if (Days >366 ) throw "���� ������ ������ 366!!!";

    int* Stocks =  new int[Days]; // ������ ����
	for (int i = 0; i < Days; i++) {
		cout << "������� ���� ����� � " << i+1 << " ���� (����������� ����� �� 1 �� 100000000)";
		cin >> Stocks[i];
        if (Stocks[i]<=0 || Stocks[i] > 1000000000) throw "��������� ����� �� ����������!!!";
	}
	int N = Days - 1;
	int* Diff =  new int[N];  // ������ ������ ����� ������ 
	for (int i = 0; i < N; i++) {
		Diff[i]=Stocks[i+1]- Stocks[i];
	}

    int max_sum = Case_1_2(Diff, 0, N - 1);
    Poisk_Day(Diff, N - 1, max_sum);
    cout <<" ����������� ��������� ������� " << max_sum << endl << " ���� �������: " << Date_1 << endl << " ���� �������: " << Date_2;

	delete[] Diff;
	delete[] Stocks; 
	return 0;
}
catch (const char* exception) // ���������� ���������� ���� const char*
{
    std::cerr << "Error: " << exception << '\n';
}
}