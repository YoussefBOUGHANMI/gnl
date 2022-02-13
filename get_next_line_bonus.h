/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:14:45 by yboughan          #+#    #+#             */
/*   Updated: 2022/02/13 14:51:26 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*get_big_buffer(int fd, char *rest);
char	*get_current_line(char *big_buffer);
char	*get_rest(char *rest);
char	*get_next_line(int fd);
#endif
