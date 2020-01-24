// client2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include "time.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");
	system("cls");
	HANDLE hslot;

	hslot = CreateFile(L"\\\\.\\mailslot\\demoSlot", GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);


	char wbuf[50] = "another text from julia ";
	std::cout << "SLOT IS WAITING" << std::endl;
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
	WriteFile(hslot, " ", sizeof(" "), &dwBytesWrite, NULL);

	cout << endl << "Время передачи: " << (t2 - t1) / 1000 << " сек.\n\n";

	//CloseHandle(hslot);
	system("pause");
	return 0;

}