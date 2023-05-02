//Сформировать двумерный массив A случайных целых чисел из m строк и n столбцов.
//Упорядочить строки массива A в порядке убывания сумм цифр первого элемента каждой строки.

#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

const int ABSLIMIT = 100;

int sum_digit(int *elem)
{
    int temp = abs(*elem);
    int sum = 0;
    while (temp != 0)
    {
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned int>(time(NULL)));
    int m, n;
    cout << "m: ";
    cin >> m;
    cout << "n: ";
    cin >> n;
    int** A = new int* [m];
    for (int i = 0; i < m; i++)
    {
        *(A + i) = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(A + i) + j) = rand() % (ABSLIMIT + ABSLIMIT + 1) - ABSLIMIT;
        }
    }

    cout << "Вывод несортированного массива: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(*(A + i) + j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (sum_digit(*(A + j)) < sum_digit(*(A + j + 1)))
            {
                int* temp = *(A + j);
                *(A + j) = *(A + j + 1);
                *(A + j + 1) = temp;
            }
        }
    }

    cout << "Вывод отсортированного массива: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(*(A + i) + j) << " ";
        }
        cout << endl;
    }
}