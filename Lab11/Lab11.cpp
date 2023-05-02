//С клавиатуры вводится имя пользователя и возраст, возраст может вводиться либо числом,
//либо в строковом представлении(словами).Вывести год рождения для обоих случаев.

#include <iostream>
#include <Windows.h>
#include <sstream>
#include <string>
#include <map>

using namespace std;

const int year = 2022;

map <string, int> word_to_digit = {
    {"один", 1},
    {"два", 2},
    {"три", 3},
    {"четыре", 4},
    {"пять", 5},
    {"шесть", 6},
    {"семь", 7},
    {"восемь", 8},
    {"девять", 9},
    {"десять", 10},
    {"одиннадцать", 11},
    {"двенадцать", 12},
    {"тринадцать", 13},
    {"четырнадцать", 14},
    {"пятнадцать", 15},
    {"шестнадцать", 16},
    {"семнадцать", 17},
    {"восемнадцать", 18},
    {"девятнадцать", 19},
    {"двадцать", 20},
    {"тридцать", 30},
    {"сорок", 40},
    {"пятьдесят", 50},
    {"шестьдесят", 60},
    {"семьдесят", 70},
    {"восемьдесят", 80},
    {"девяносто", 90}
};

int Birth(unsigned int age)
{
    return year - age;
}

int Birth(string age)
{
    int result = 0;
    istringstream ist(age);
    map <string, int> ::iterator it;
    for (string word; ist >> word;)
    {
        it = word_to_digit.find(word);
        result += it->second;
    }
    return year - result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string name;
    string age_str;
    unsigned int age_int;

    cout << "Введите свое имя: "; getline(cin, name);
    int choice;
    cout << "Выберите способ ввода возраста: 1 - число, 2 - строкой "; cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Введите свой возраст: "; cin >> age_int;
        cout << "Ваш год рождения: " << Birth(age_int) << endl;
        break;
    case 2:
        cout << "Введите свой возраст: "; 
        cin.get();
        getline(cin, age_str);
        cout << "Ваш год рождения: " << Birth(age_str) << endl;
        break;
    default:
        cout << "Неверный выбор! " << endl;
        break;
    }
}