/*****************************************************************************/
/*** smart-select.c                                                        ***/
/***                                                                       ***/
/*** The smart select combines preforking with the select() call to keep   ***/
/*** the select descriptor arrays small.                                   ***/
/*****************************************************************************/

#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define MAXPROCESSES	5
#define MAXCONNECTIONS	5

int NumChildren=0;

/*---------------------------------------------------------------------*/
/*--- sig_child - SIGCHLD                                           ---*/
/*---------------------------------------------------------------------*/
void sig_child(int signum)
{
	wait(0);
	NumChildren--;
}

/*---------------------------------------------------------------------*/
/*--- servlet - each servlet accepts a connection and keeps track   ---*/
/*--- of it using a select() statement.                             ---*/
/*---------------------------------------------------------------------*/
void servlet(int server)
{	fd_set set;
	int maxfd = server;
	int ceiling=0;

	FD_ZERO(&set);
	FD_SET(server, &set);
	for (;;)
	{   struct timeval timeout={2,0}; /* 2 seconds */

    	/*---Wait for some action---*/
	    if ( select(maxfd+1, &set, 0, 0, &timeout) > 0 )
    	{
        	/*---If new connection, connect and add to list---*/
			if ( FD_ISSET(server, &set) )
			{
			    if ( ceiling < MAXCONNECTIONS )
		    	{   int client = accept(server, 0, 0);
		        	if ( maxfd < client )
        		    	maxfd = client;
			        FD_SET(client, &set);
    	    		ceiling++;
					printf("select process #%d: %d connected\n",
							getpid(), ceiling);
			    }
	        }

    	    /*---If command/request from client, process---*/
        	else
			{	int i;

				for ( i = 0; i < maxfd+1; i++ )
				{
					if ( FD_ISSET(i, &set) )
					{	char buffer[1024];
						int bytes;

						bytes = recv(i, buffer, sizeof(buffer), 0);
						if ( bytes < 0 )		/* check if channel closed */
						{
							close(i);
							FD_CLR(i, &set);
							ceiling--;
							printf("select process #%d: %d connected\n",
									getpid(), ceiling);
						}
						else					/* process the request */
							send(i, buffer, bytes, 0);
					}
				}
			}
    	}
	}
	exit(0);
}

/*---------------------------------------------------------------------*/
/*--- main - set up server and maintain the number of living servlets--*/
/*---------------------------------------------------------------------*/
int main(int count, char *strings[])
{	int sd;
	struct sockaddr_in addr;
	struct sigaction act;

	if ( count != 2 )
	{
		printf("usage: %s <port>\n", strings[0]);
		exit(0);
	}
	bzero(&act, sizeof(act));
	act.sa_handler = sig_child;
	act.sa_flags = SA_NOCLDSTOP | SA_RESTART;
	if ( sigaction(SIGCHLD, &act, 0) != 0 )
		perror("sigaction()");

	sd = socket(PF_INET, SOCK_STREAM, 0);
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(strings[1]));
	addr.sin_addr.s_addr = INADDR_ANY;
	if ( bind(sd, (struct sockaddr*)&addr, sizeof(addr)) == 0 )
	{
		listen(sd, 15);
		for (;;)
		{
			if ( NumChildren < MAXPROCESSES )
			{	int pid;

				if ( (pid = fork()) == 0 )
					servlet(sd);
				else if ( pid > 0 )
					NumChildren++;
				else
					perror("fork()");
			}
			else
				sleep(1);
		}
	}
	else
		perror("bind()");
	return 0;
}

