// server.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

	HANDLE hslot = CreateMailslot(            // Созд почтовый ящик
		L"\\\\.\\mailslot\\demoSlot",  /// имя почтового ящика.
		0,                             /// сообщ мб любого размера
		MAILSLOT_WAIT_FOREVER,         /// всегда ждет сообщения.
		NULL                           /// дескриптор не мб унаследован
	);


	cout << "SLOT IS WAITING \n";
	int i = 0;
	char rbuf[50];
	DWORD rms;
	HANDLE hMS;
	double t1, t2;
	int answer;

	while (true)
	{
		i++;
		ReadFile(hslot, rbuf, sizeof(rbuf), &rms, NULL);
		///		  из   буфер	макс [б]   кол счит б
		if (i == 1) t1 = clock();
		cout << rbuf << endl;
	}

	t2 = clock();

	cout << "Время передач: " << (t2 - t1) / 1000 << " сек. \n";
	cout << "Количество всех сообщений: " << i - 1 << "\n\n";

	CloseHandle(hslot);
	return 0;
}