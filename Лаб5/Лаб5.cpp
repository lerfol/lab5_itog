#include <iostream>
#include <clocale>
#include <fstream>
#include <ctime>
#include "ClassBin.h"
using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");
    cout << "#1" << endl;
    ClassFile EX1;
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    EX1.FileCinBin("ex1.bin", size);
    EX1.FileCoutBin("ex1.bin", size);
    EX1.ex_1("ex1.bin",size);

    cout << endl;
    cout << "#2" << endl;
    ClassFile EX2;
    int size_2, n;
    cout << "Введите размер массива: ";
    cin >> size_2;
    cout << "Введите размер матрицы: ";
    cin >> n;
    EX2.ex_2("ex2.bin", size_2, n);

    cout << endl;
    cout << "#4" << endl;
    ClassFile EX4;
    int size_4;
    cout << "Введите размер массива: ";
    cin >> size_4;
    EX4.ex_4("ex_4.txt", size_4);

    cout << endl;
    cout << "#5" << endl;
    ClassFile EX5;
    int size_5;
    cout << "Введите размер массива: ";
    cin >> size_5;
    EX5.ex_5("ex_5.txt", size_5);

    cout << endl;
    cout << "#6" << endl;
    ClassFile EX6;
    EX6.ex_6("ex_6.txt");
}

