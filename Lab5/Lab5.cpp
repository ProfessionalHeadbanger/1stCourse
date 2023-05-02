//Дан одномерный массив из N вещественных чисел.Определить количество троек соседних элементов, которые могут быть длинами сторон
//треугольника.Создать массив из наибольших сторон таких треугольников,
//упорядочить его элементы по убыванию, используя алгоритм сортировки
//методом пузырька.

#include <iostream>
#include <Windows.h>
#include <random>
#include <ctime>
#include <vector>

using namespace std;
int const N = 10;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    default_random_engine randEng(time(NULL));
    uniform_real_distribution<double> randNumb(1, 100);
    double num_array[N];

    cout << "Заполнение массива случайными вещественными числами и его вывод: " << endl;
    for (int i = 0; i < N; i++)
    {
        num_array[i] = randNumb(randEng);
        cout << num_array[i] << " ";
    }
    cout << endl;

    vector <double> triangles;
    for (int i = 1; i < N - 1; i++)
    {
        if ((num_array[i] < num_array[i - 1] + num_array[i + 1]) && (num_array[i + 1] < num_array[i] + num_array[i - 1]) && (num_array[i - 1] < num_array[i + 1] + num_array[i]))
        {
            triangles.push_back(max(max(num_array[i], num_array[i - 1]), num_array[i + 1]));
        }
    }

    cout << "Вывод массива наибольших сторон треугольников: " << endl;
    for (int i = 0; i < triangles.size(); i++)
    {
        cout << triangles[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < triangles.size(); i++)
    {
        for (int j = 0; j < triangles.size() - 1; j++)
        {
            if (triangles[j] < triangles[j + 1])
            {
                double buff = triangles[j];
                triangles[j] = triangles[j + 1];
                triangles[j + 1] = buff;
            }
        }
    }

    cout << "Вывод отсортированного массива наибольших сторон треугольников: " << endl;
    for (int i = 0; i < triangles.size(); i++)
    {
        cout << triangles[i] << " ";
    }
    cout << endl;
}