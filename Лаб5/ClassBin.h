 #pragma once
#include <random>
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
using namespace std;

class ClassFile
{
	int mas[];
public:
	void FileCinBin(string filename, int size) {
		int* mas = new int[size];
		for (int i = 0; i < size; i++) {
			mas[i] = rand() % 10;
		}
		ofstream file1_wr(filename, ios::out | ios::binary);
		if (file1_wr.is_open()) {
			file1_wr.write((char*)mas, size*sizeof(int));
		}
		delete[] mas;
	}
	void FileCoutBin(string filename, int size) {
		int* mas2 = new int[size];
		ifstream file1_r(filename, ios::in | ios::binary);
		if (file1_r.is_open()) {
			file1_r.read((char*)mas2, size * sizeof(int));
		}
		for (int i = 0; i < size; i++) {
			cout << mas2[i] << " ";
		}
		cout << endl;
		delete[] mas2;
	}

	void FileCinTXT_Num5(string filename, int size) {
		ofstream File(filename);
		int x = 0;
		int str = 0;
		if (File.is_open()) {
			while (x < size) {
				str = 0;
				while ((str < rand() % 10) && (x<size)) {
					File << rand() % 100 << " ";
					x++;
					str++;
				}
				File << endl;
			}
			File.close();
		}
		else {
			cout << "Ошибка в открытии файла!" << endl;
			return;
		}
	}

	void FileCinTXT(string filename, int size) {
		ofstream File(filename);
		if (File.is_open()) {
			for (int i = 0; i < size; i++) {
				File << rand() % 100 << endl;
			}
			File.close();
		}
		else {
			cout << "Ошибка в открытии файла!" << endl;
			return;
		}
	}

	void FileCoutTXT(string filename) {
		ifstream File(filename);
		if (File.is_open()) {
			int num;
			cout << "Файл содержит: ";
			while (File >> num) {
				cout << num << " ";
			}
			cout << endl;
			File.close();

		}
		else {
			cout << "Ошибка в открытии файла!" << endl;
			return;
		}
	}

	void ex_1(string filename, int size) {
		int* mas1 = new int[size];
		ifstream file1_r(filename, ios::in | ios::binary);
		if (file1_r.is_open()) {
			file1_r.read((char*)mas1, size*sizeof(int));
		}
		int* array = new int[size];
		int count = 0;
		int k = 0;
		cout << "Массив" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < count; j++) {
				if (mas1[i] == array[j]) {
					k = 1;
					continue;
				}
			}
			if (k == 0) {
				array[count] = mas1[i];
				cout << array[count] << " ";
				count++;
			}
			else {
				k = 0;
			}
		}
		cout << endl;
		int array_size = count * sizeof(int);
		ofstream file1_wr(filename, ios::out | ios::binary);
		if (file1_wr.is_open()) {
			file1_wr.write((char*) array, array_size);
		}
		FileCoutBin(filename, count);
		delete[] array;
	}

	void ex_2(string filename, int size, int n) {
		int** matrix = new int* [n];
		for (int i = 0; i < n; ++i) {
			matrix[i] = new int[n];
		}
		FileCinBin(filename, size);
		FileCoutBin(filename, size);
		int* mas = new int[size];
		ifstream file_r(filename, ios::out | ios::binary);
		if (file_r.is_open()) {
			file_r.read((char*)mas, size * sizeof(int));
		}
		int i = 0, j = 0, k =0;
		while ((i < n)) {
			while ((j < n)) {
				if (k < size) {
					// Заменяем неченые числа
					if (mas[k] % 2 == 1) {
						int x = mas[k];
						while (x >= 10) {
							x /= 10;
						}
						matrix[i][j] = x;
						k++;
						j++;
					}
					else {
						matrix[i][j] = mas[k];
						k++;
						j++;
					}
				}
				else {
					matrix[i][j] = 0;
					j++;
				}
			}
			j = 0;
			i++;
		}
		cout << "Матрицa размером " << n << "*" << n << " : " << endl;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		delete[] matrix;
		delete[] mas;
	}

	void ex_4(string filename, int size) {
		FileCinTXT(filename, size);
		FileCoutTXT(filename);
		cout << "Введите цифру, чтобы посчитать сумму элементов оканчивающихся на эту цифру: ";
		int x;
		cin >> x;
		int sum = 0;
		ifstream File(filename);
		if (File.is_open()) {
			int num;
			while (File >> num) {
				if ((num % 10) == x) {
					sum += num;
				}
			}
			File.close();

		}
		else {
			cout << "Ошибка в открытии файла!" << endl;
			return;
		}
		cout << "Сумма чисел оканчивающихся на " << x << " равна: " << sum << endl;

	}

	void ex_5(string filename, int size) {
		FileCinTXT_Num5(filename, size);
		FileCoutTXT(filename);
		int first = 0, min_num = 0 , raz, count = 0;

		ifstream File(filename);
		if (File.is_open()) {
			int num;
			while (File >> num) {
				if (count == 0) {
					min_num = num;
					first = num;
				}
				min_num = min(num, min_num);
				count = 1;

			}
			raz = first - min_num;
			File.close();

		}
		else {
			cout << "Ошибка в открытии файла!" << endl;
			return;
		}
		cout << "Разность первого и минимального равна: " << raz << endl;

	}

	bool TestString(string line) {
		const string test = ",.!?():";
		for (char c : test) {
			if (line.find(c) != string::npos) {
				return false;
			}
		}
		return true;
	}

	void ex_6(string filename) {
		string filenameIn;
		cout << "Введите название файла, в который нужно перезаписать: ";
		cin >> filenameIn;
		ofstream FileIn(filenameIn);
		ifstream FileOut(filename);
		if (FileOut.is_open() && FileIn.is_open()) {
			char ch;
			int test = 1;
			string line;
			cout << endl;
			cout << "Исходный файл: " << endl;
			while (getline(FileOut, line)) {
				cout << line << endl;
				if (TestString(line)) {
					FileIn << line << endl;
				}
			}
			FileOut.close();
			FileIn.close();
		}
		cout << endl;
		cout << "Новый файл: " << endl;
		ifstream FileOut_2(filenameIn);
		if (FileOut_2.is_open()) {
			char ch2;
			while (FileOut_2.get(ch2)) {
				cout << ch2;
			}
		}
		else {
			cout << "Ошибка в открытии файла!" << endl;
			return;
		}
		FileOut_2.close();
	}
};

