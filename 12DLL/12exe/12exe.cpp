// 12exe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "12.h"
#include<conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	for (;;)
	{
		int choice;
		cout << "\n\nВыберите задание:\n";
		cout << "1. Запись строки в файл\n";
		cout << "2. Запуск процесса на выполнение\n";
		cout << "3. Проверка наличия файла в папке\n";
		cin >> choice;

		if (choice == 1)
		{
			char input[50];
			cout << "Введите строку для помещения в файл: ";
			cin >> input;
			Write(input);
		}
		if (choice == 2)
		{
			ProcessRun();
		}
		if (choice==3)
		{
			string path, file_name;
			cout << "Введите путь: "; cin >> path;
			cout << "Введите имя файла: "; cin >> file_name;
			if (CheckFile(path, file_name))
				cout << "Файл найден!\n";
			else
				cout << "Файл не найден!\n";
		}
	}
	return 0;
}
