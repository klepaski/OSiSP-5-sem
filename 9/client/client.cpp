// client.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include "time.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");
	system("cls");
	HANDLE hslot;
	hslot = CreateFile(                     // Созд (откр) файл или у-во I/O 
		L"\\\\.\\mailslot\\demoSlot",       ///имя созд-мого файла
		GENERIC_WRITE,                      /// запись
		FILE_SHARE_READ | FILE_SHARE_WRITE, /// для совместного чтения
		NULL,                               /// защита по умолчанию
		OPEN_EXISTING,                      /// только существующий файл
		NULL,
		NULL                                /// атрибутов шаблона нет
	);

	char wbuf[50] = " some text from julia ";
	std::cout << "SLOT IS WAITING \n";
	int nData;
	int n = 10, number;
	DWORD dwBytesWrite;
	double t1, t2;

	cout << "Enter text of message: ";
	cin >> wbuf;

	cout << "Enter number of messages: ";
	cin >> number;
	t1 = clock();

	for (int i = 0; i < number; i++)
	{
		char q[6];
		sprintf_s(q, "%d", i + 1);
		char buf[sizeof(wbuf) + sizeof(q)];
		strcpy_s(buf, wbuf);
		strcat_s(buf, q);

		WriteFile(hslot, buf, sizeof(wbuf), &dwBytesWrite, NULL);
		cout << "Message " << i + 1 << endl;
	}
	t2 = clock();

	//запис д-е в указ. файл
	WriteFile(hslot, " ", sizeof(" "), &dwBytesWrite, NULL);
	///		  у-во   буфер		р-р		куда запис		синхр


	cout << "\n Время передачи: " << (t2 - t1) / 1000 << " сек. \n\n";
	//CloseHandle(hslot);
	system("pause");
	return 0;
}