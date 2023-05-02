//Массив из 20 символьных строк содержит информацию об изделиях мебельной фабрики.Каждая строка начинается с пробела.
//Следующие две цифры соответствуют номеру изделия, далее записано название изделия (Стол, Стул, Шкаф), затем параметры изделия(ширина, длина, высота).
//Пример одной из строк :
// 12) Стол ширина - 75.5 см; длина - 90.8 см; высота - 80 см
//Составить программу для формирования символьной строки из номеров изделий, являющихся столами, площадь которых больше 0,8 м2.

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int const N = 20;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <string> furniture;
    string line;
    ifstream F("list.txt");

    while (!F.eof())
    {
        getline(F, line);
        furniture.push_back(line);
    }

    cout << "Полученный список изделий: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << furniture[i] << endl;
    }
    cout << endl;

    string result;
    for (int i = 0; i < N; i++)
    {
        if (furniture[i].find("Стол") != -1)
        {
            string sub_string1 = furniture[i].substr(furniture[i].find("ширина") + 9, furniture[i].find("см;") - furniture[i].find("ширина") - 9);
            double width_fur = stod(sub_string1, NULL);

            string sub_string2 = furniture[i].substr(furniture[i].find("длина") + 8, furniture[i].find("см;", furniture[i].find("длина")) - furniture[i].find("длина") - 8);
            double lenght_fur = stod(sub_string2, NULL);
            
            if (width_fur * lenght_fur > 8000)
            {
                result += furniture[i].substr(0, furniture[i].find(")"));
            }
        }
    }
    cout << "Номера изделий, являющихся столами, площадь которых больше 0.8 м^2: " << endl << result;
}
