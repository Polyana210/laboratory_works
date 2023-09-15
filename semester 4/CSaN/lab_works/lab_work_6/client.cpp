#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#include <iostream>
#include <WinSock2.h>
#include <vector>
#include <string>
#include <ctype.h>
#include <ctime>


using namespace std;
SOCKET this_s;
int main() {
	WSAData wData;
	if (WSAStartup(MAKEWORD(2, 2), &wData) != 0)
	{
		cout << "error" << endl;
		exit(-1);
	}
	SOCKADDR_IN addr;
	int addrl = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");;
	addr.sin_port = htons(11);
	addr.sin_family = AF_INET;
	this_s = socket(AF_INET, SOCK_STREAM, NULL);
	if (this_s == SOCKET_ERROR) {
		printf("Socket not created\n");
	}
	if (connect(this_s, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		cout << "error" << endl;
		return -1;
	}
	char time[11];
	//int time;;
	/*if (recv(this_s, time, 11, NULL) != -1) {
		char mass[12];
		for (int i = 0; i < 11; i++) {
			mass[i] = time[i];
		}
		mass[11] = '\0';
		//time_t toOutput = time;
		//cout << ctime(&toOutput) << endl;
		cout << mass << endl;
	}
	*/
	system("pause");
	return 0;
}