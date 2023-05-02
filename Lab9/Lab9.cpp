//Пусть дано n треугольников.Определите количество треугольников, которые пересекают границы заданного квадрата.
//Используйте функцию для определения, пересекает ли треугольник границы квадрата.

#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

bool CheckTriangle(vector<vector<double>> &square, vector<vector<double>> &triangle)
{
    int check_count = 0;
    for (int i = 0; i < 3; i++)
    {
        if ((triangle[i][0] > square[0][0]) && (triangle[i][0] > square[1][0]) && (triangle[i][0] < square[2][0]) && (triangle[i][0] < square[3][0]))
        {
            if ((triangle[i][1] > square[0][1]) && (triangle[i][1] < square[1][1]) && (triangle[i][1] < square[2][1]) && (triangle[i][1] > square[3][1]))
            {
                check_count++;
            }
        }
    }
    if ((check_count == 3) || (check_count == 0))
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<vector<double>> square;
    square.resize(4);
    for (int i = 0; i < 4; i++)
    {
        square[i].resize(2);
    }
retry:
    cout << "Введите координаты точек квадрата ABCD(А - левая нижняя точка, точки располагаются по часовой стрелке, стороны квадрата должны быть параллельны осям координат): " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << (char)(i + 65) << ": ";
        for (int j = 0; j < 2; j++)
        {
            cin >> square[i][j];
        }
    }
    if ((square[0][0] >= square[3][0]) && (square[1][0] >= square[2][0]) && (square[0][1] >= square[1][1]) && (square[3][1] >= square[2][1]))
    {
        cout << "Неверно заданы точки квадрата." << endl << endl;
        goto retry;
    }
    if ((square[0][0] != square[1][0]) || (square[3][0] != square[2][0]) || (square[0][1] != square[3][1]) || (square[1][1] != square[2][1]))
    {
        cout << "Стороны квадрата не параллельны осям координат." << endl << endl;
        goto retry;
    }

    vector<vector<vector<double>>> triangles;
    int n;
    cout << endl << "Введите количество треугольников: "; cin >> n;
    triangles.resize(n);
    for (int i = 0; i < n; i++)
    {
        triangles[i].resize(3);
        for (int j = 0; j < 3; j++)
        {
            triangles[i][j].resize(2);
        }
    }
    cout << "Введите координаты треугольников: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Треугольник " << i+1 << ": ";
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cin >> triangles[i][j][k];
            }
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (CheckTriangle(square, triangles[i]))
        {
            cout << "Треугольник " << i + 1 << " пересекается с квадратом ABCD. " << endl;
        }
    }
}
