//Дан вектор x из n целых чисел и квадратная матрица A порядка n.
//Строки матрицы A заменить вектором x.

#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	vector <int> x;
	int n;
	cout << "Введите размерность вектора х: ";
	cin >> n;
	cout << "Введите элементы вектора х: ";
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		x.push_back(input);
	}

	vector<vector<int>> A;
	A.resize(n);
	for (int i = 0; i < n; i++)
	{
		A[i].resize(n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 10 + 1;
		}
	}

	cout << "Исходная матрица: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = x[j];
		}
	}

	cout << "Результат замены строк матрицы на вектор: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
