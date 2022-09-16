#include <iostream>
using namespace std;

template <typename T>
class MATRIX {
	int m;  // ���������� �����
	int n;  // ���������� ��������
	T** M;  // �������
public:
	MATRIX() {
		n = 0; m = 0; 
	}

	MATRIX(int N, int M1) {
		n = N; m = M1;
		M = (T**) new T * [m];     //�������� ������ �  ��������� ��� ���� �����
	    
		for (int i = 0; i < m; i++)
		M[i] = (T*)new T[n];           //�������� ������ �  ��������� ��� ���� ��������

		for (int i = 0; i < m; i++)    //��������� ������ ������
			for (int j = 0; j < n; j++)
				M[i][j] = 0;
	}

	MATRIX(const MATRIX& M1) //����������� �����������
	{
		n = M1.n; m = M1.m;
		M = (T**) new T * [m]; 
		for (int i = 0; i < m; i++)
			M[i] = (T*) new T[n];

		// ��������� ����������
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = M1.M[i][j];
	}
	
	T GetM_i_j(int i, int j) {  //����� �������
		if ((m > 0) && (n > 0))
			return M[i][j];
		else
			return 0;
	}

	void SetM_i_j(int i, int j, T value) {
		if ((i < 0) || (i >= m))
			return;
		if ((j < 0) || (j >= n))
			return;
		M[i][j] = value;
	}

	void Print(const char* Name)  // ����� �������
	{
		cout << "Object: " << Name << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << M[i][j] << "\t";
			cout << endl;
		}
		cout << "-----------------------" << endl << endl;
	}

	// �������� ����������� - ������������
	MATRIX operator=(const MATRIX& _M)
	{
		if (n > 0)
		{
			// ���������� ������, ���������� ����� ��� ������� *this
			for (int i = 0; i < m; i++)
				delete[] M[i];
		}

		if (m > 0)
		{
			delete[] M;
		}

		// ����������� ������ M <= _M
		m = _M.m;
		n = _M.n;

		// �������� ������ ��� M �����
		M = (T**) new T * [m]; // ���������� �����, ���������� ����������
		for (int i = 0; i < m; i++)
			M[i] = (T*) new T[n];

		// ��������� ����������
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				M[i][j] = _M.M[i][j];
		return *this;
	}

	// ���������� - ����������� ������, ���������� ��� �������
	~MATRIX()
	{
		if (n > 0)
		{
			// ���������� ���������� ������ ��� ������ ������
			for (int i = 0; i < m; i++)
				delete[] M[i];
		}

		if (m > 0)
			delete[] M;
	}

	MATRIX SUMMA(MATRIX& M1, MATRIX& M2) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int t = M1.GetM_i_j(i, j) + M2.GetM_i_j(i, j);
				SetM_i_j(i, j, t);
			}
		return  *this;
	}

	MATRIX RAZN( MATRIX& M1, MATRIX& M2) {
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int t = M1.GetM_i_j(i, j) - M2.GetM_i_j(i, j);
				SetM_i_j(i, j, t);
			}
		return  *this;
	}

};

int main() {
	try {
		setlocale(LC_ALL, "rus");
		double n1, m1, n, m;
		cout << "������� ����� �����: ";    cin >> n1;
		cout << "������� ����� ��������: ";  cin >> m1;
		n = int(n1); m = int(m1);
		if (n1 <= 0 || n1 - n != 0 || m1 - m != 0 || m1 <= 0) throw "���������� ����� � �������� ������ ���� ������������ �������!!!";

		MATRIX<int> M1(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				M1.SetM_i_j(i, j, 1 + rand() % 20);
		M1.Print("M1");

		MATRIX<int> M2(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				M2.SetM_i_j(i, j, 1 + rand() % 20);
		M2.Print("M2");

		MATRIX<int> SUM(n, m);
		SUM.SUMMA(M1, M2);
		SUM.Print("SUMMA");

		MATRIX<int> Raz(n, m);
		Raz.RAZN(M1, M2);
		Raz.Print("RAZNOST");


		return 0;
	}
	catch (const char* exception)
	{
		cerr << "������: " << exception << '\n';
		exit(-1);
	}
}