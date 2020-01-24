// os3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include <string>
#include "string.h"

#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	HANDLE consoleOutput;
	COORD cursorPos;

	// Получаем хэндл консоли 
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for (int i = 0; i < 3; i++) {
		cursorPos.X = 0;
		cursorPos.Y = i;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		cout << setw(40) << setfill('_') << '_' << "|";
	}



	string students[3] = { "Petrov", "Ivanov", "Kulich" };
	int groups[3] = { 4, 6, 7 };

	for (int i = 0; i < 3; i++) {
		cursorPos.X = 0;
		cursorPos.Y = i;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		cout << "|" << setw(11) << students[i];
	}


	for (int i = 0; i < 3; i++) {
		cursorPos.X = 20;
		cursorPos.Y = i;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		cout << "|" << setw(9) << groups[i];
	}

		cout << "\n\n";
		system("pause");
		return 0;

}
