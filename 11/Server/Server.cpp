#include "pch.h"
#include <winsock2.h>
#include <stdio.h>
#include <string>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 512

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Russian");
	char recvbuf[DEFAULT_BUFLEN];	///буфер приема
	WSADATA wsaData;
	int retVal;


	WSAStartup(MAKEWORD(2, 2), &wsaData);


	SOCKET servSock = socket(
		PF_INET,                /// сем-тво протоколов
		SOCK_STREAM,            /// ориент на поток  
		IPPROTO_TCP             /// Протокол упр-я передачей 
	);


	SOCKADDR_IN sin;
	sin.sin_family = PF_INET;
	sin.sin_port = htons(1111);
	sin.sin_addr.s_addr = INADDR_ANY;

	retVal = bind(servSock, (LPSOCKADDR)&sin, sizeof(sin));
	retVal = listen(servSock, 10); /// Макс длина очереди ожидающих соединений.


	SOCKET clientSock;
	clientSock = accept(servSock, NULL, NULL);
	if (clientSock) cout << "Клиент подключен\n";


	for (;;)
	{
		retVal = recv(clientSock, recvbuf, strlen(recvbuf), 0);

		if (retVal > 0) {
			cout << "Клиент: ";
			for (int i = 0; i < retVal; i++)
			{
				cout << recvbuf[i];
			}

			cout << "\nСервер: ";
			char userBuff[20] = "";
			cin >> userBuff;

			
			retVal = send(clientSock, userBuff, retVal, 0);
		}
		else
		{
			cout << "Соединение прервано\n";
			break;
		}
	}
	
	closesocket(clientSock);
	closesocket(servSock);

	WSACleanup();
	return 0;

}