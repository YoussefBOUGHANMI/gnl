/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:14:45 by yboughan          #+#    #+#             */
/*   Updated: 2022/02/12 17:16:41 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	int				length;
	int 			fd;
	struct s_list	*next;
}		t_list;

size_t	ft_strlen(char const *str);
size_t    ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char *add_buffer(int fd , char *line , int *flag_newl);
int is_new_line(char *buffer);
char *get_next_line(int fd);
void	goto_next_line(int fd , char *rest , int *nb_buff);
#endif
