// 12DLL.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


extern "C++" __declspec(dllexport) void Write(char* s)
{
	FILE * file = fopen("D:\\file.txt", "w");
	fputs(s, file);
	fclose(file);
}

extern "C++" __declspec(dllexport) void ProcessRun()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("notepad.exe");
	CreateProcess(NULL, buf, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi);
}

extern "C++" __declspec(dllexport) bool CheckFile(string path, string file_name)
{
	ifstream file;
	string full = path + file_name;
	file.open(full);
	if (!file) return false;
	else return true;
}


///СОБРАТЬ РЕШЕНИЕ