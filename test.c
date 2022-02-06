#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include"get_next_line.h"

int main()
{
	int fd1;
	int fd2;
	char *res;
	char *res1;
	int i = 0;
	fd1 = open("test1.txt",O_RDONLY);
	fd2 = open("test2.txt",O_RDONLY);
	res = malloc((BUFFER_SIZE + 1 ) * sizeof(char));
	res1 = malloc((BUFFER_SIZE + 1 ) * sizeof(char));

/*
	i = read(fd1 , res , BUFFER_SIZE);
	res[i] = 0;
	printf("i :%i \n%s\n" , i , res);


	i = read(fd1 , res1 , BUFFER_SIZE);
	res[i] = 0;
	printf("i : %i \n%s\n" , i , res1);

*/


	while ( i < 5)
	{
		res = get_next_line(fd1);
		printf(res);
		i++;
	}
/*
	while (i < 20 )
	{
		res = get_next_line(fd2);
		printf(res);
		i++;
	}

	while (i < 40)
	{
		res = get_next_line(fd1);
		printf(res);
		i++;
	}
*/
}
