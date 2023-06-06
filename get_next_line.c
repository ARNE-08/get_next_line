/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:50:12 by marvin            #+#    #+#             */
/*   Updated: 2023/06/04 13:50:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_line(int fd, char *str, char *buffer)
{
    int len;

    while (1)
    {
        len = read(fd, buffer, BUFFER_SIZE);
        if (len <= 0)
            break;
        str = ft_strjoin(str, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (str);
}

char	*cut_line(char	*str)
{
	int		len_nl;
	int		len;
	char	*temp;

    temp = ft_dupnl(str);
	len_nl = ft_strlen(temp);
	len = ft_strlen(str);
	if (len_nl < len - 1)
	{
		str = ft_strjoin(NULL, str + len_nl + 1);
		free(temp);
	}
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char *ft_dupnl(char *str) 
{
    char    *line;
    char    *before;
    size_t  i;
    size_t  len;

    i = 0;
    line = ft_strchr(str, '\n');
    if (!line)
        return (NULL);
    if (line)
    {
        len = line - str;
        before = malloc(sizeof(char) * (len + 1));
        while (str[i] != '\0' && i < len)
        {
            before[i] = str[i];
            i++;
        }
        before[i] = '\0';
        return (before);
    }
    return (NULL);
}

char    *get_next_line(int fd)
{
    static char *str;
    char        *line;
    char        *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    str = read_line(fd, str, buffer);
    if (str)
    {
        line = ft_dupnl(str);
        str = cut_line(str);
    }
    return (line);
}

// len = read(fd, buffer, BUFFER_SIZE); // return 5 or less if the left length is smaller than 5 e.g. Hey will return 3
// int main()
// {
//     int fd;
//     char *line;

//     fd = open("test/simple", O_RDONLY);
//     line = get_next_line(fd);
// }