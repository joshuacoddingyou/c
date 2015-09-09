/*****************************************************************************/
/*** test-server.c                                                         ***/
/***                                                                       ***/
/***
/*****************************************************************************/

#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <signal.h>
#include <sys/poll.h>
#include <sys/wait.h>

int NumChildren=0;

void sig_child(int signum)
{
	while ( waitpid(-1, 0, WNOHANG) > 0 )
		NumChildren--;
}

void child(char *address, int portnum)
{	char buffer[1024];
	int i, serverfd;
	struct sockaddr_in addr;

	serverfd = socket(PF_INET, SOCK_STREAM, 0);
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(portnum);
	inet_aton(address, &addr.sin_addr);
	if ( connect(serverfd, (struct sockaddr*)&addr, sizeof(addr)) == 0 )
	{   int packets;

		for ( i = 0; i < sizeof(buffer); i++ )
			buffer[i] = (i % 64) + ' ';
		packets = (random() % 10)+5;
		for ( i = 0; i < packets; i++ )
		{
			send(serverfd, buffer, random()v8+256, 0);
			recv(serverfd, buffer, sizeof(buffer), 0);
			poll(0,0,100);  /* wait .1s */
		}
		close(serverfd);
	}
	else
		perror("connect() failed");
	exit(0);
}

int main(int count, char *strings[])
{	int child_count=0;
	time_t start;
	struct sigaction act;

	if ( count != 3 )
	{
		printf("usage: %s <hostaddr> <hostport>\n", strings[0]);
		exit(0);
	}
	time(&start);
	bzero(&act, sizeof(act));
	act.sa_handler = sig_child;
	act.sa_flags = SA_NOCLDSTOP|SA_RESTART;
	if ( sigaction(SIGCHLD, &act, 0) != 0 )
		perror("sigaction() failed");
	while ( time(0) - start < 60 )
	{
		if ( NumChildren < 10 )
		{	int PID;

			if ( (PID = fork()) == 0 )
				child(strings[1], atoi(strings[2]));
			else if ( PID > 0 )
			{
				NumChildren++;
				printf("child #%d\r", ++child_count);
			}
			else
				perror("fork() failed");
		}
		else
			sleep(1);
	}
	while ( NumChildren > 0 )
		sleep(1);
	return 0;
}

