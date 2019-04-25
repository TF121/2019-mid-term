#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "FIFO_FD"

int main()
{
	char buf[100];
	int num, fd;

	if(mknod(FIFO_NAME, S_IFIFO | 0666, 0) == -1)
	{
		perror("mknod error");
	}
	
	printf("receiver: waiting for a sender.\n");
	fd = open(FIFO_NAME, O_RDONLY);

	printf("receiver: the sender is ready.\n");

	do
	{
		if((num = read(fd, buf, 100)) == -1)
			perror("receive error");
		else
		{
			buf[num] ='\0';
			printf("receiver: %d bytes read: %s", num, buf);
		}
	}
	while(num > 0);
	return 0;
}
