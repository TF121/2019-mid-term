#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int i, j;

int main(void)
{
	pid_t pid; 

	pid = fork(); 
	if(pid == -1)
	{
		printf("can't fork, error\n");
		exit(0);
	}

	if(pid == 0)
	{
		for(j = 0; j < 201; j++)
		{
			printf("child2: %d\n", j);
		}
		exit(0);
	}
	else
	{
		for(i = 0; i < 101; i++)
		{
			printf("child1 : %d\n", i);
		}
		exit(0);

		printf("sum: %d + %d = %d \n", i, j, i+j);
		return 0;
	}
}
