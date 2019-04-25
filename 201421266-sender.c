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

	printf("sender: waiting for a receiver.\n");
	fd = open(FIFO_NAME, O_WRONLY);

	printf("sender: the receiver ready.\n");
	printf("sender: : ");

	while(fgets(buf, sizeof(buf), stdin), !feof(stdin))
	{
		if((num = write(fd, buf, strlen(buf))) == -1)
			perror("send error");
		else
			printf("sender: wrote %d bytes \n", num);
	}
	return 0;
}
