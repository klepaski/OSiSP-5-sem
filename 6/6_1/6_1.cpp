// 6_1.cpp

#include "pch.h"
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)


//1А + 1Б : Найти файл .exe И запуск его на выполнение
void zad6_1()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;

	WIN32_FIND_DATA FindFileData;
	TCHAR filesearch[] = TEXT("D:\\3\\ms*.exe");
	TCHAR buf[] = TEXT("mspaint.exe");


	// Найти первый файл в директории
	HANDLE hFind = INVALID_HANDLE_VALUE;
	hFind = FindFirstFile(filesearch, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
		printf("Файл не найден.\n", GetLastError());
	else
	{
		std::cout << "Файл был найден и открыт!\n";

		if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0,
			NULL, NULL, &cif, &pi)))
			std::wcout << "Ошибка " << '\n';
		FindClose(hFind);
	}
}



// 1В : запуск процесса с выводом его системного №
void zad6_1B()
{
	DWORD processID;
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");
	processID = CreateProcess(NULL, buf, NULL, NULL, FALSE, 0,
		NULL, NULL, &cif, &pi);

	std::cout << "Системный № процесса (PID):" << pi.dwProcessId << '\n';
}


// 2 : запуск процесса с удал. консольного окна через 2 сек
void zad6_2()
{
	DWORD processID;
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");

	if (!(processID = CreateProcess(NULL, buf, NULL, NULL, FALSE, 0,
		NULL, NULL, &cif, &pi)))
		std::wcout << "Running " << '\n';

	HANDLE hProcess = GetCurrentProcess(); //получаем pID консольного приложен.

	if (hProcess == NULL) std::wcout << "Error when terminating " << '\n';
	else
	{
		Sleep(2000);
		BOOL result = TerminateProcess(hProcess, 0);
		CloseHandle(hProcess);
	}
}


// 3 : вывод имен всех запущенных процессов
void zad6_3()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot) {
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hSnapshot, &pe32)) {
			do {

				std::cout << "Имя процесса :";
				std::wcout << pe32.szExeFile << '\n';
			} while (Process32Next(hSnapshot, &pe32));
		}
	}
}


// 4 : проверяет, вып ли процесс
bool AreEqual(const TCHAR *a, const TCHAR *b)
{
	while (*a == *b)
	{
		if (*a == TEXT('\0')) return true;
		a++; b++;
	}
	return false;
}

bool zad6_4()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	TCHAR buf[] = TEXT("mspaint.exe");
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &pe);

	if (AreEqual(pe.szExeFile, buf)) return true;

	while (Process32Next(hSnapshot, &pe))
	{
		if (AreEqual(pe.szExeFile, buf)) return true;
	}
	return false;

}

void main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 100;
	while (choice != 0)
	{
		std::cout << "\n-----------------------------------\n";
		std::cout << "Enter number of task:\n";
		std::cout << "0  - exit\n";
		std::cout << "1  - 6.1:  Найти файл exe и запустить его\n";
		std::cout << "11 - 6.B:  Запуск процесса с выводом его системного №\n";
		std::cout << "2  - 6.2:  Запуск процесса + удал консоли через 2 сек\n";
		std::cout << "3  - 6.3:  Вывод имен всех запущенных процессов\n";
		std::cout << "4  - 6.4:  Выполняется ли процесс?\n";
		std::cin >> choice;

		switch (choice) {
		case 1: zad6_1(); break;
		case 11: zad6_1B(); break;
		case 2: zad6_2(); break;
		case 3: zad6_3(); break;
		case 4: if (zad6_4()) std::cout << "Выполняется";
				else std::cout << "НЕ выполняется";
				break;
		}
	}
}