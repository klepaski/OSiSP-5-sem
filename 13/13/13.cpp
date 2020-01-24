// 13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include "string.h"
#include "conio.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(NULL, "rus");

	while (true)
	{
		cout << "\nВведите пароль: ";

		char ch;
		char password[6];

		ifstream file("D:\\3\\ОСиСП\\13\\output.txt");
		file.getline(password, 6);
		file.close();

		bool priz = true;
		int i = 0;

		while ((ch = _getch()) != '\r')
		{
			_putch('*');

			if (ch != password[i++])
			{
				priz = false;
			}
		}


		if (priz) {
			cout << "\nВЕРНО!\n";
			break;
		}
		else cout << "\nНЕВЕРНО!\n";
	}

	system("pause");
	return 0;
}
