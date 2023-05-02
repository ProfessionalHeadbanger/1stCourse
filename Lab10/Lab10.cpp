#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

double Integral(double x, int n, double alpha)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return exp(alpha * x) * (alpha * x - 1) / pow(alpha, 2);
    }
    else
    {
        return (pow(x, n) * exp(alpha * x) / alpha) - Integral(x, n - 1, alpha) * n / alpha;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    double a, b;
    cout << "Введите границы интегрирования: " << endl;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    int n;
    cout << "Введите степень х: "; cin >> n;
    double alpha;
    cout << "Введите параметр альфа: "; cin >> alpha;
    cout << "Integral = " << Integral(b, n, alpha) - Integral(a, n, alpha);
}