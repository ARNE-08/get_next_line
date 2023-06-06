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
        if (len <= 0)
            break;

        buffer[len] = '\0'; // Ensure buffer is null-terminated

        str = ft_strjoin(str, buffer);

        if (ft_strchr(buffer, '\n'))
            break;
    }

    // printf("\nfree buffer! : buffer = %s", buffer);
    if (buffer != NULL)
    {
        free(buffer);
        buffer = NULL;
        // printf("\nalready free buffer! : buffer = %s", buffer);
    }

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
        // printf("\nfree temp! : temp = %s", temp);
        if (temp != NULL)
        {
            free(temp);
            temp = NULL;
            // printf("\nalready free temp! : temp = %s", temp);
        }
	}
	else
	{
        // printf("\nfree str! : str = %s", str);
        if (str != NULL)
        {
            free(str);
            str = NULL;
            // printf("\nalready free str! : str = %s", str);
        }
		return (NULL);
	}
    // printf("\nnot else str : %s", str);
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

    len = line - str +1;
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

    return line;
}

int main(void)
{
    int fd;
    char *str;

    fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
    // fd = open("gnlTester/files/multiple_line_with_nl", O_RDONLY);

    printf("line 1:%s|", get_next_line(fd));
    printf("line 2:%s|", get_next_line(fd));
    printf("line 3:%s|", get_next_line(fd));
    printf("line 4:%s|", get_next_line(fd));
    printf("line 5:%s|", get_next_line(fd));
    printf("line 6:%s|", get_next_line(fd));
    close(fd);

    return 0;
}
