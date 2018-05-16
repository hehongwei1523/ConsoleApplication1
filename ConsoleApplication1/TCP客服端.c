#include "stdafx.h"
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")


#define CLIENT_ADDRESS "192.168.1.233"
#define CLIENT_PORT 8888


int client()
{
	/* init winsock */
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 1), &wsaData))
	{
		printf("winsock init failed\n");
		return 1;
	}

	SOCKADDR_IN serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(CLIENT_PORT);                      /* 服务器监听端口 */


	serverAddr.sin_addr.S_un.S_addr = inet_addr(CLIENT_ADDRESS);//inet_pton(SERVER_ADDRESS);//InetPton(SERVER_ADDRESS);//     /* 服务器地址 */  //

																/* connect to server */
	printf("connecting...\n");

	/* create a tcp socket  */
	SOCKET sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd <= 0)
	{
		printf("socket create failed\n");
		return -1;
	}

	int len = sizeof(serverAddr);
	if (connect(sock_fd, (SOCKADDR *)&serverAddr, len) != 0)
	{
		printf("connection failed\n");
		return -1;
	}
	printf("connected\n");


	char buffer[1024];
	while (1)
	{
		printf("press: ");
		fgets(buffer, sizeof(buffer), stdin);

		/* send to server */
		if (send(sock_fd, buffer, sizeof(buffer), 0) <= 0)
		{
			printf("send error\n");
			break;
		}

		if (recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddr, &len) != SOCKET_ERROR)
		{
			printf("got: %s", buffer);
		}
	}

	WSACleanup();

	return 0;
}
