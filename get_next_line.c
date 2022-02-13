/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:39:26 by yboughan          #+#    #+#             */
/*   Updated: 2022/02/13 11:35:31 by youssef          ###   ########.fr       */
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

char *get_big_buffer(int fd , char *rest)
{
	char tmp[BUFFER_SIZE+1];
	int nb_buff;

	nb_buff = 1;
	while (!strchr(rest, '\n') && nb_buff != 0)
	{
		nb_buff = read(fd,tmp,BUFFER_SIZE);

		if (nb_buff == -1)
			return(NULL);

		tmp[nb_buff] = '\0';
		rest = ft_strjoin(rest , tmp);
	}
	return (rest);
}

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
	static char *rest;
	char *current_line;
	
	if (BUFFER_SIZE <= 0)
		return (NULL);	
	rest = get_big_buffer(fd , rest);
	current_line = get_current_line(big_buffer);
	printf(current
//	rest[fd] = get_rest(big_buffer);
//	free(big_buffer);
//	return(current_line);
	return(" test ");
}
