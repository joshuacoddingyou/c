/*****************************************************************************/
/*** trivial-server.c                                                      ***/
/***                                                                       ***/
/*****************************************************************************/

#include <stdio.h>
#include <perror.h>

int main()
{   int cnt;

	while (1)
	{
		int pchild;
		printf("Enter count:");
		scanf("%d", &cnt);
		if ( (pchild = fork()) == 0 )
		{   int i;
			for ( i = 0; i < cnt; i++ )
			{
				printf("Child: %d\n", i);
				sleep(1);
			}
			exit(0);
		}
		else if ( pchild < 0 )
			perror("Fork error");
	}
	return 0;
}

