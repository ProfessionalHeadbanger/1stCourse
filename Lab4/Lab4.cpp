#include <iostream>
#include <Windows.h> 
#include <cmath>

using namespace std;

const int R = 1;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int N;
    double x, E;
    cout << "Введите значения x, N и E, где x лежит в интервале (" << -R << ";" << R << "), а N - натуральное число: " << endl;
    cout << "x: ";
    cin >> x;
    if (x > R || x < -R)
    {
        cout << "Введенный x не принадлежит интервалу (" << -R << ";" << R << ")" << endl;
        return 0;
    }
    cout << "N: ";
    cin >> N;
    if (N <= 0)
    {
        cout << "Введенный N не является натуральным числом" << endl;
    }
    cout << "E: ";
    cin >> E;
    double E1 = E / 10;

    double sum1 = x;
    double g1 = x * x;
    double den1 = 2;
    double slag1 = 1;
    int step1 = 3;
    double multi;

    for (int i = 0; i < N - 1; i++)
    {
        multi = slag1 * (1 / den1) * (x * g1 / (den1 + 1));
        sum1 = sum1 + multi;
        slag1 *= (step1 / den1);
        g1 *= x * x;
        den1 += 2;
        step1 += 2;
    }

    cout << "Первая сумма равна: " << sum1 << endl << endl;

    double sum2 = x;
    double g2 = x * x;
    double den2 = 2;
    double slag2 = 1;
    int step2 = 3;
    int slag_count1 = 0;
    double multi2 = slag2 * (1 / den2) * (x * g2 / (den2 + 1));

    while (abs(multi2) > E)
    {
        sum2 = sum2 + multi2;
        slag2 *= (step2 / den2);
        g2 *= x * x;
        den2 += 2;
        step2 += 2;
        slag_count1++;
        multi2 = slag2 * (1 / den2) * (x * g2 / (den2 + 1));
    }

    cout << "Вторая сумма равна: " << sum2 << endl;
    cout << "Количество слагаемых: " << slag_count1+1 << endl << endl;

    double sum3 = x;
    double g3 = x * x;
    double den3 = 2;
    double slag3 = 1;
    int step3 = 3;
    int slag_count2 = 0;
    double multi3 = slag3 * (1 / den3) * (x * g3 / (den3 + 1));

    while (abs(multi3) > E1)
    {
        sum3 = sum3 + multi3;
        slag3 *= (step3 / den3);
        g3 *= x * x;
        den3 += 2;
        step3 += 2;
        slag_count2++;
        multi3 = slag3 * (1 / den3) * (x * g3 / (den3 + 1));
    }

    cout << "Третья сумма равна: " << sum3 << endl;
    cout << "Количество слагаемых: " << slag_count2+1 << endl << endl;

    double arcsin_x = asin(x);
    cout << "Точное значение функции arcsin(x): " << arcsin_x << endl;
}
