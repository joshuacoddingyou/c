/*****************************************************************************/
/*** demand-accept.c                                                       ***/
/***                                                                       ***/
/*** Accept connections based on signal demand.  When a connection is made,***/
/*** a SIGIO  is raised and the process stops to handle it.  The handler   ***/
/*** connects to the client.  The main program could be processing other   ***/
/*** tasks when these connections arrive.                                  ***/
/*****************************************************************************/

#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <signal.h>
#include <fcntl.h>

void PANIC(char* msg);
#define PANIC(msg) { perror(msg); abort(); }

int sd;

/*--------------------------------------------------------------------*/
/*--- Signal capture: SIGIO - connect to client.                   ---*/
/*--------------------------------------------------------------------*/
void sig_io(int sig)
{	int client;

	client = accept(sd, 0, 0);
	send(client, "hello\ngoodbye!\n\n", 16, 0);
	close(client);
}

/*--------------------------------------------------------------------*/
/*--- main - set up asynchronous connections and wait              ---*/
/*--------------------------------------------------------------------*/
int main()
{	int flag=64;
	struct sockaddr_in addr;
	struct sigaction act;

	bzero(&act, sizeof(act));
	act.sa_handler = sig_io;
	if ( sigaction(SIGIO, &act, 0) < 0 )
		PANIC("SigAction");
	sd = socket(PF_INET, SOCK_STREAM, 0);
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = INADDR_ANY;
	if ( bind(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
		PANIC("bind");
	if ( listen(sd, 20) != 0 )
		PANIC("listen");
	if ( fcntl(sd, F_SETFL, O_ASYNC | O_NONBLOCK) < 0 )
		PANIC("async & nonblocking");
	if ( fcntl(sd, F_SETOWN, getpid()) < 0 )
		PANIC("setown");
	while (1)
		sleep(5);
	return 0;
}
