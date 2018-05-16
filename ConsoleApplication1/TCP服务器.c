#include "stdafx.h"  //需要放在winsock前才能使inet_addr 编译通过
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")


#define SERVER_PORT 8888
#define SERVER_ADDR "192.168.1.233"

void toUpper(char * in, char * out, int len)
{
	int i;
	char diff = 'a' - 'A';

	for (i = 0; i<len; ++i)
	{
		if ((in[i] >= 'a') && (in[i] <= 'z'))
		{
			out[i] = in[i] - diff;
		}
		else
		{
			out[i] = in[i];
		}
	}
}


int server()
{
	/* init winsock */
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 1), &wsaData))
	{
		printf("winsock init failed\n");
		return 1;
	}

	/* create a tcp socket */
	SOCKET serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSock <= 0)
	{
		printf("socket create failed\n");
		return -1;
	}

	SOCKADDR_IN serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SERVER_PORT);            /* 监听端口 */
	serverAddr.sin_addr.S_un.S_addr = inet_addr(SERVER_ADDR);//htonl(SERVER_ADDR);  /* 本机 */

	if (bind(serverSock, (SOCKADDR *)&serverAddr, sizeof(serverAddr)) != 0)
	{
		printf("bind failed\n");
		return -1;
	}

	/* start listen */
	printf("start listening...\n");
	if (listen(serverSock, 1) != 0)
	{
		printf("listen failed\n");
		return -1;
	}

	int len = sizeof(SOCKADDR_IN);

	/* waiting for connection */
	SOCKADDR_IN clientAddr;
	SOCKET clientSock = accept(serverSock, (SOCKADDR *)&clientAddr, &len);
	if (clientSock <= 0)
	{
		printf("accept failed\n");
		return -1;
	}
	printf("connected\n");

	char bufferIn[1024];
	char bufferOut[1024];
	while (1)
	{
		bufferIn[0] = '\0';

		printf("waiting...\n");

		if (recv(clientSock, bufferIn, sizeof(bufferIn), 0) <= 0)
		{
			/* error occurs */
			printf("close connection\n");
			break;
		}
		printf("got: %s", bufferIn);

		toUpper(bufferIn, bufferOut, len);

		if (send(clientSock, bufferOut, sizeof(bufferOut), 0) <= 0)
		{
			printf("send error\n");
			break;
		}
	}

	closesocket(clientSock);

	WSACleanup();

	return 0;
}
