/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:05:25 by ppoti             #+#    #+#             */
/*   Updated: 2023/06/07 19:13:35 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//edit header
#include "get_next_line.h"

char	*read_line(int fd, char *str, char *buffer)
{
	int	len;

	while (1)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buffer[len] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (buffer != NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	return (str);
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
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	return (str);
}

char	*ft_dupnl(char *str)
{
	char	*line;
	char	*before;
	size_t	i;
	size_t	len;

	i = 0;
	line = ft_strchr(str, '\n');
	if (!line)
		return (str);
	len = line - str +1;
	before = malloc(sizeof(char) * (len + 1));
	while (str[i] != '\0' && i < len)
	{
		before[i] = str[i];
		i++;
	}
	before[i] = '\0';
	return (before);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str = read_line(fd, str, buffer);
	if (str)
	{
		line = ft_dupnl(str);
		if (!ft_strchr(str, '\n'))
			line = ft_strjoin(NULL, str);
		str = cut_line(str);
	}
	return (line);
}

// int main(void)
// {
//     int fd;
// 	char	*line;

//     //fd = open("file.txt", O_RDONLY);
//     fd = open("gnlTester/files/43_no_nl", O_RDONLY);

// 	line = get_next_line(fd);
// 	while(line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);

// //    printf("line 1:%s|", get_next_line(fd));
// //    printf("line 2:%s|", get_next_line(fd));
// //    printf("line 3:%s|", get_next_line(fd));
// //    printf("line 4:%s|", get_next_line(fd));
// //    printf("line 5:%s|", get_next_line(fd));
// //    printf("line 6:%s|", get_next_line(fd));
//     close(fd);

//     return 0;
// }
