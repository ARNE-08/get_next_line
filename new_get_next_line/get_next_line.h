/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:50:19 by marvin            #+#    #+#             */
/*   Updated: 2023/06/04 13:50:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *read_line(int fd, char *str, char *buffer);
char    *ft_strchr(char *s, int c);
char    *ft_dupnl(char *str);
char	*cut_line(char	*str);

#endif