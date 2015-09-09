/*****************************************************************************/
/*** upd-server.c                                                          ***/
/***                                                                       ***/
/*** Create a datagram server that waits for client messages (which it     ***/
/*** echoes back).                                                         ***/
/*****************************************************************************/


#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>

#define DEFAULT_PORT	9999

int main(int count, char *strings[])
{	int sd;
	int port=DEFAULT_PORT;
	struct sockaddr_in addr;
	char buffer[1024];

	if ( count != 2 )
		printf("usage: %s <port>\n...Using default port (%d).\n", strings[0], port);
	else
		port = atoi(strings[1]);
	sd = socket(PF_INET, SOCK_DGRAM, 0);
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	if ( bind(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
		perror("bind");
	while (1)
	{	int bytes, addr_len=sizeof(addr);

		bytes = recvfrom(sd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addr_len);
		printf("msg from %s:%d (%d bytes)\n", inet_ntoa(addr.sin_addr),
						ntohs(addr.sin_port), bytes);
		sendto(sd, buffer, bytes, 0, (struct sockaddr*)&addr, sizeof(addr));
	}
	close(sd);
}

