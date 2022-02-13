/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:39:26 by yboughan          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/02/13 10:03:02 by youssef          ###   ########.fr       */
=======
/*   Updated: 2022/02/12 18:27:09 by yboughan         ###   ########.fr       */
>>>>>>> fb447cd52952fd2e5ef37247948982d63dde90ac
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
char *get_big_buffer(int fd , char *rest)
{
	char tmp[BUFFER_SIZE+1];
	int nb_buff;

/*	if(!rest)
	{
		printf("nu");
		rest = malloc(1);
		rest[0] = 0;
	}*/
	nb_buff = 1;
	while (!strchr(rest, '\n') && nb_buff != 0)
	{
		nb_buff = read(fd,tmp,BUFFER_SIZE);
=======
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	if (dstsize < len_dst || dstsize == 0)
		return (len_src + dstsize);
	while (i + len_dst < dstsize - 1 && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_dst + len_src);
}

void	goto_next_line(int fd , char *rest , int *nb_buff)
{
	char *tmp[BUFFER_SIZE+1];
	int flag_newl = 0;

	flag_newl = is_new_line(rest);
	while (flag_newl == 0 && *nb_buff > 0)
	{
		*nb_buff = read(fd,tmp,BUFFER_SIZE);
		if (*nb_buff == 0)
			return;
		tmp[*nb_buff] = 0;
//		printf("tmp : %s\n" , tmp);
//		printf("rest : %s\n" , rest);
		ft_strlcat(rest , tmp , ft_strlen(rest) + *nb_buff + 1);
		flag_newl = is_new_line(rest);
	}
	return;
}
>>>>>>> fb447cd52952fd2e5ef37247948982d63dde90ac

		if (nb_buff == -1)
			return(NULL);

<<<<<<< HEAD
		tmp[nb_buff] = '\0';
		rest = ft_strjoin(rest , tmp);
=======
	i = 0;
	if ( buffer == NULL)
		return(0);
	while (buffer[i] != '\0')
	{
		if ( buffer[i] == '\n')
			return (1);
		i++;
>>>>>>> fb447cd52952fd2e5ef37247948982d63dde90ac
	}
	return (rest);
}

<<<<<<< HEAD
=======



>>>>>>> fb447cd52952fd2e5ef37247948982d63dde90ac
char *get_current_line(char *big_buffer)
{
	int len_c_l;
	int i;
	char *current_line;

	len_c_l = 0;
	i = 0;
	while ( big_buffer[len_c_l] != '\n')
		len_c_l++;

	current_line = malloc((len_c_l + 2) * sizeof(char));

	while (i < len_c_l)
	{
		current_line[i] = big_buffer[i];
		i++;
	}
	current_line[i] = '\n';
	current_line[i + 1] = '\0';
	return (current_line);
}

char *get_rest(char *big_buffer)
{
	int i;
	int len_rest;
	char *rest;

	i  = 0;
	len_rest = 0;
	while (*big_buffer != '\n')
		big_buffer++;
	big_buffer++;

	while (big_buffer[len_rest] != '\0')
		len_rest++;
	rest = malloc((len_rest + 1) * sizeof(char));
		
	while(i < len_rest)
	{
		rest[i] = big_buffer[i];
		i++;
	}
	rest[i] = '\0';
	return(rest);
}


char *get_next_line(int fd)
{
<<<<<<< HEAD
	static char *rest;
=======
	static char rest[1024][1];
>>>>>>> fb447cd52952fd2e5ef37247948982d63dde90ac
	char *current_line;
	
	if (BUFFER_SIZE <= 0)
<<<<<<< HEAD
		return (NULL);	
	rest = get_big_buffer(fd , rest);
	printf("big : %s", rest);
//	current_line = get_current_line(big_buffer);
//	rest[fd] = get_rest(big_buffer);
//	free(big_buffer);
//	return(current_line);
	return(" test ");
=======
		return (NULL);

	goto_next_line(fd , rest[fd] , &nb_buffer);
	printf("f : %s \n" , rest[fd]);
/*
	if ((nb_buffer == 0 && rest[fd][0]=='\0') || (nb_buffer < 0))
	{
		return(NULL);
	}
	
	if (is_new_line(rest[fd]) == 0 && nb_buffer == 0 )
		printf("last : ");
*/
	current_line = get_current_line(rest[fd]);
	printf(current_line);
	//get_rest(rest[fd]);
//	return(current_line);

	return("");
>>>>>>> fb447cd52952fd2e5ef37247948982d63dde90ac
}
