/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:39:26 by yboughan          #+#    #+#             */
/*   Updated: 2022/02/06 17:13:19 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *get_big_buffer(int fd , char *rest)
{
	char *tmp;
	char *big_buffer;
	int flag_newl = 0;
	int nb_buff = 0;

	big_buffer = "\0";
	big_buffer = ft_strjoin(big_buffer , rest);
	while (flag_newl == 0 )
	{
		tmp = malloc((BUFFER_SIZE + 1 ) * sizeof(char));
		nb_buff = read(fd,tmp,BUFFER_SIZE);
		printf("\n nb : %d \n" , nb_buff);
		if (nb_buff == 0)
			return(big_buffer);
		tmp[nb_buff] = '\0';
		flag_newl = is_new_line(big_buffer);
		big_buffer = ft_strjoin(big_buffer , tmp);
		free(tmp);
	}
	return (big_buffer);
}

int is_new_line(char *buffer)
{
	int i;

	i = 0;
	while ( i < BUFFER_SIZE )
	{
		if ( buffer[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
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
	static char *rest[1024];
	char *big_buffer;
	char *current_line;
	int nb_buffer;
	
	nb_buffer = 0 ;
	big_buffer = get_big_buffer(fd , rest[fd]);
//	printf("big bug : %s" , big_buffer);
//	printf("\nnb_buff : %d \n" , nb_buffer);

	current_line = get_current_line(big_buffer);
	rest[fd] = get_rest(big_buffer);
	free(big_buffer);
	return(current_line);
}