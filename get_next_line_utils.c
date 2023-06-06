/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:50:16 by marvin            #+#    #+#             */
/*   Updated: 2023/06/04 13:50:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    size_t  len;

    if (!s1 || !s2)
        return (0);
    len = ft_strlen(s1) + ft_strlen(s2);
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (0);
    while (*s1)
        *str++ = *s1++;
    while (*s2)
        *str++ = *s2++;
    *str = '\0';
    if (s1)
        free(s1);
    return (str - len);
}

char    *ft_strchr(char *s, int c)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(s);
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
        {
            s = s + i;
            return ((char *)s);
        }
        i++;
    }
    if (c == 0)
    {
        s = s + len;
        return ((char *)s);
    }
    return (0);
}

// int main()
// {
//     char *s3 = "Hello\nWorld";

//     printf(ft_dupnl(s3, '\n'));
// }