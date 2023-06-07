/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:52:39 by marvin            #+#    #+#             */
/*   Updated: 2023/06/07 19:34:07 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//edit header
#include "get_next_line.h"

size_t	ft_strlen(const char *s, int mode)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (mode == 1 && s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strsubjoin(char *str, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len_s1 = ft_strlen(s1, 0);
	else
		len_s1 = 0;
	if (s2)
		len_s2 = ft_strlen(s2, 0);
	else
		len_s2 = 0;
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	ft_strsubjoin(str, s1, s2);
	if (s1 != NULL)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s, 0);
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
	return (NULL);
}
