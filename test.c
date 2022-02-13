#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include"get_next_line.h"


int main()
{
//	char test[10000000];
	int fd1;
	int fd2;
	fd1 = open("test1.txt",O_RDONLY);

	int i = 0;
	
	while ( i < 15)
	{
	printf("%s" , get_next_line(fd1));
	i++;
	}
}
