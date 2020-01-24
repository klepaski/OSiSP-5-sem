// 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include "string.h"
#include <stdlib.h>
#include <fstream>
#include <tchar.h>
#pragma warning (disable : 4996)

CRITICAL_SECTION cs;

DWORD WINAPI myThread(void* lpPar)
{
	char info[256];

	TCHAR* b = new TCHAR();
	b = (TCHAR*)lpPar;

	///конверт b (строку шир символов) и помещ рез в строку info (первые len+1 байт)
	wcstombs(info, b, wcslen(b) + 1);

	std::cout << "WRITING : " << info << "\n";
	std::ofstream file("D:\\3\\ОСиСП\\8\\myfile.txt");

	EnterCriticalSection(&cs);

	file << info;
	file.close();

	LeaveCriticalSection(&cs);
	return 0;
}

DWORD WINAPI myThread2(void* lpPar)
{
	///участок кода, в кот. произв доступ к общ.ресурсу, кот. не дб исп одновременно 2+ потоками
	EnterCriticalSection(&cs);

	std::ifstream file("D:\\3\\ОСиСП\\8\\myfile.txt");
	char info[256];

	if (file.getline(info, 256))
		std::cout << "READING: " << info << "\n";
	else std::cout << "Error while reading\n";
	file.close();

	LeaveCriticalSection(&cs);
	return 0;

}

int _tmain(int argc, _TCHAR* argv[])
{
	DWORD myThreadID;
	DWORD myThreadID2;
	TCHAR Buff[256] = TEXT("Hello! This is the Synchronization Laboratorny work!");
	TCHAR Buff2[256] = TEXT("start");

	InitializeCriticalSection(&cs);
	///не мб унасл, нач.р-р, ф-я, парам, опции, id		
	HANDLE myHandle = CreateThread(0, 0, myThread, (void*)Buff, CREATE_SUSPENDED, &myThreadID);
	///включ способность повышать приоритет потока
	///когда поток запуск, с-ма временно повыш его приор, чтобы вывести его из сост ожидания
	BOOL b = SetThreadPriorityBoost(myHandle, false);

	if (b)
	{
		SetThreadPriority(myHandle, THREAD_PRIORITY_HIGHEST);
	}

	HANDLE myHandle2 = CreateThread(0, 0, myThread2, (void*)Buff2, CREATE_SUSPENDED, &myThreadID2);

	///возобновл выполн потока
	ResumeThread(myHandle);
	ResumeThread(myHandle2);

	///остан тек. поток до завершения потока в парам (но не дольше чем на 10 сек)
	WaitForSingleObject(myHandle, 10000);
	WaitForSingleObject(myHandle2, 10000);


	///заверш работу потока
	TerminateThread(myHandle, 0);
	TerminateThread(myHandle2, 0);

	system("pause");
	return 0;
}