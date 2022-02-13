/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:39:26 by yboughan          #+#    #+#             */
/*   Updated: 2022/02/13 14:14:24 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

char *get_big_buffer(int fd , char *rest)
{
	char *tmp;
	int nb_buff;
	
	tmp = malloc((BUFFER_SIZE+1) * sizeof(char));
	if(!tmp)
		return (NULL);
	nb_buff = 1;
	while (!ft_strchr(rest, '\n') && nb_buff != 0)
	{
		nb_buff = read(fd,tmp,BUFFER_SIZE);
		if (nb_buff < 0)
		{
			free(tmp);
			return(NULL);
		}
		tmp[nb_buff] = '\0';
		rest = ft_strjoin(rest , tmp);
	}
	free(tmp);
	return (rest);
}


char *get_current_line(char *big_buffer)
{
	int len_c_l;
	int i;
	char *current_line;

	len_c_l = 0;
	i = 0;
	if (!big_buffer[i])
		return(NULL);
	while ( big_buffer[len_c_l] != '\n' && big_buffer[len_c_l] != '\0')
		len_c_l++;
	current_line = malloc((len_c_l + 2) * sizeof(char));
	if(!current_line)
		return(NULL);
	while (i < len_c_l)
	{
		current_line[i] = big_buffer[i];
		i++;
	}
	if (big_buffer[i] =='\n')
	{
		current_line[i] = '\n';
		i++;
	}
	current_line[i] = '\0';
	return (current_line);
}
char *get_rest(char *rest)
{
	int i;
	int j;
	char *new_rest;

	i = 0;
	j = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	new_rest = (char *)malloc((ft_strlen(rest) - i + 1) * sizeof(char));
	if (!new_rest)
		return(NULL);
	i++;
	while(rest[i])
		new_rest[j++] = rest[i++];
	new_rest[j] = '\0';
	free(rest);
	return(new_rest);
}


char *get_next_line(int fd)
{
	static char *rest;
	char *current_line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	
	rest = get_big_buffer(fd , rest);
	if (!rest)
		return (NULL);
	current_line = get_current_line(rest);
	rest = get_rest(rest);
	
	return(current_line);
}
