/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:51:06 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 20:51:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd, char *str, char *buffer)
{
    int len;

    while (1)
    {
        len = read(fd, buffer, BUFFER_SIZE);
        // printf("len = %d\n", len);
        // printf("buffer : %s\n", buffer);
        if (len <= 0)
            break;

        buffer[len] = '\0'; // Ensure buffer is null-terminated

        // printf("str before join : %s\n", str);
        str = ft_strjoin(str, buffer);
        // printf("str after join : %s\n", str);
        if (ft_strchr(buffer, '\n'))
            break;
    }

    free(buffer);
    // printf("str when return : %s\n", str);
    return str;
}

char	*cut_line(char	*str)
{
	int		len_nl;
	int		len;
	char	*temp;

	len_nl = ft_strlen(str, 1);
	len = ft_strlen(str, 0);
	if (len_nl < len - 1)
	{
		temp = str;
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
    char *line;
    char *before;
    size_t i;
    size_t len;

    i = 0;
    line = ft_strchr(str, '\n');
    if (!line)
        return str;

    len = line - str;
    before = malloc(sizeof(char) * (len + 1));

    while (str[i] != '\0' && i < len)
    {
        before[i] = str[i];
        i++;
    }

    before[i] = '\0';
    return before;
}

char *get_next_line(int fd)
{
    static char *str = NULL; // Initialize str to NULL
    char *line;
    char *buffer;

    line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return NULL;

    // Check if str is NULL
    str = read_line(fd, str, buffer);

    if (str)
    {
        line = ft_dupnl(str);
        // printf("line : %s\n", line);
        str = cut_line(str);
        // printf("str : %s\n", str);
    }

    // free(buffer);
    return line;
}

/* int main(void)
{
    int fd;
    char *str;

    fd = open("newwy", O_RDONLY);
    // printf("%d", fd);

    for (int i = 0; i < 10; i++)
    {
        str = get_next_line(fd);
        printf("answer : %s\n", str);
        free(str);
    }
    close(fd);

    return 0;
} */
