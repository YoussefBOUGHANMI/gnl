/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:08:29 by yboughan          #+#    #+#             */
/*   Updated: 2022/02/06 15:24:24 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	i;

	i = 0;
	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	while (i < lensrc && src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (lensrc);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s3;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	s3 = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy((char *)s3, (char *)s1, len_s1 + 1);
	ft_strlcpy((char *)(s3 + len_s1), (char *)s2, len_s2 + 1);
	return (s3);
}


char *get_last_line(char *big_buffer)
{
	int len_c_l;
	int i;
	char *current_line;

	len_c_l = 0;
	i = 0;
	while ( big_buffer[len_c_l] != '\n')
		len_c_l++;

//	printf("len : %d \n" , len_c_l);
	current_line = malloc((len_c_l + 1) * sizeof(char));

	while (i < len_c_l)
	{
		current_line[i] = big_buffer[i];
		i++;
	}
	current_line[i] = '\0';
	return(current_line);
}

