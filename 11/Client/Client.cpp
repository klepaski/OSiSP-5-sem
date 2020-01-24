#include "pch.h"
#include <stdio.h>
#include <winsock2.h>
#include <string>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")
#pragma warning (disable: 4996)
#define bufsize 256

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	WSADATA wsaData;
	int retVal = 0;
	char buf[bufsize];
	int r;

	WSAStartup(MAKEWORD(2, 2), (LPWSADATA)&wsaData);

	LPHOSTENT hostEnt;
	hostEnt = gethostbyname("localhost");
	SOCKADDR_IN serverInfo;
	
	SOCKET clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	serverInfo.sin_family = PF_INET;
	serverInfo.sin_addr = *((LPIN_ADDR)*hostEnt->h_addr_list);
	serverInfo.sin_port = htons(1111);

	retVal = connect(clientSock, (LPSOCKADDR)&serverInfo, sizeof(serverInfo));
	if (retVal) printf("Соединено успешно.\n");


	for (;;)
	{
		cout << "\nКлиент: ";
		string userBuff = "";
		cin >> userBuff;

		retVal = send(clientSock, userBuff.c_str(), userBuff.length(), 0);


		r = recv(clientSock, buf, bufsize, 0);

		if (r > 0)
		{
			cout << "Сервер: ";
			for (int i = 0; i < r; i++)
			{
				cout << buf[i];
			}
		}
		else if (r == 0)
		{
			cout << "Соединение разорвано\n";
			break;
		}
	}

	
	closesocket(clientSock);
	WSACleanup();

	system("pause");
	return 0;
}