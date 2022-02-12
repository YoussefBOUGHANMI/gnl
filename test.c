#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include"get_next_line.h"


void ft(char *c , char *s)
{

strlcat(c , s , 20);
return;

}

int main()
{
	int fd1;
	int fd2;
	char *res2;
	char *res;
	char res1[4];
	fd1 = open("test1.txt",O_RDONLY);
	fd2 = open("test2.txt",O_RDONLY);
	int i = 0;
	//res = malloc((BUFFER_SIZE + 1 ) * sizeof(char));
	get_next_line(fd1);
/*	read(fd1 , res , 3);
	res[3] = 0;
	read(fd1 , res1 , 3);
	res1[3] = 0;
	printf("res : %s \n" , res);
	printf("res1 : %s \n", res1);
	ft(res1 , res2);

	printf("res2 : %s\n" , res2);
	printf("res1 : %s \n", res1);
	res = malloc((BUFFER_SIZE + 1 ) * sizeof(char));
//	res1 = malloc((BUFFER_SIZE + 1 ) * sizeof(char));
	

	i = read(fd1 , res , BUFFER_SIZE);
	res[i] = 0;
	printf("i :%i \n%s\n" , i , res);


	i = read(fd1 , res1 , BUFFER_SIZE);
	res[i] = 0;
	printf("i : %i \n%s\n" , i , res1);



	while ( i < 2)
	{
		res = get_next_line(fd1);
		printf("res : %s " , res);
		i++;
	}

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
