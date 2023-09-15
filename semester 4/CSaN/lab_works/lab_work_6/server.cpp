#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include <iostream>
#include <WinSock2.h>
#include <vector>
#include <string>
#include <ctype.h>
#include <sstream>
using namespace std;

int main()
{
	WSAData wData;
	if (WSAStartup(MAKEWORD(2, 2), &wData) != 0)
	{
		printf("error");
		exit(-1);
	}
	SOCKADDR_IN addr;
	int addrl = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("192.168.43.232");//INADDR_ANY;
	addr.sin_port = htons(11);
	addr.sin_family = AF_INET;
	SOCKET this_s;
	this_s = socket(AF_INET, SOCK_STREAM, NULL);
	if (this_s == SOCKET_ERROR) {
		printf("Socket not created\n");
	}

	if (bind(this_s, (struct sockaddr*)&addr, sizeof(addr)) != SOCKET_ERROR) {
		printf("Socket succed binded\n");
	}

	if (listen(this_s, SOMAXCONN) != SOCKET_ERROR) {
		printf("Start listening at port %u\n", ntohs(addr.sin_port));
	}

	SOCKET s;
	while (true) {
		SOCKADDR_IN addr_c;
		int addrlen = sizeof(addr_c);
		if ((s = accept(this_s, (struct sockaddr*)&addr_c, &addrlen)) != 0) {
			printf("Client connected from %u.%u.%u.%u:%u\n",
				(unsigned char)addr_c.sin_addr.S_un.S_un_b.s_b1,
				(unsigned char)addr_c.sin_addr.S_un.S_un_b.s_b2,
				(unsigned char)addr_c.sin_addr.S_un.S_un_b.s_b3,
				(unsigned char)addr_c.sin_addr.S_un.S_un_b.s_b4,
				ntohs(addr_c.sin_port));

			string stroka = to_string(addr_c.sin_addr.S_un.S_un_b.s_b1);
			string stroka1 = to_string(addr_c.sin_addr.S_un.S_un_b.s_b2);
			string stroka2 = to_string(addr_c.sin_addr.S_un.S_un_b.s_b3);
			string stroka3 = to_string(addr_c.sin_addr.S_un.S_un_b.s_b4);

			stroka.push_back('.');
			stroka += stroka1;
			stroka.push_back('.');
			stroka += stroka2;
			stroka.push_back('.');
			stroka += stroka3;

			char* CH = new char[stroka.length() + 1];
			strcpy(CH, stroka.c_str());

			if (send(s, CH, strlen(CH), NULL) == -1) {
				cout << "Sending error" << endl;
			}
			closesocket(s);
		}
		else printf("connection error");
	}
	system("pause");
	return 0;
}