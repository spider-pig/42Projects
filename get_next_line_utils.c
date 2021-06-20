/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleticia <cleticia@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:19:22 by cleticia          #+#    #+#             */
/*   Updated: 2021/06/20 18:16:00 by cleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (*(str + idx) != '\0')
		idx++;
	return (idx);
}

char	*ft_substr (char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*new;
	size_t	l;
	size_t	i;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (s == NULL || l < start)
		return (ft_strdup(""));
	if (start + len < l)
		sub = (char *)malloc((len + 1) * sizeof(char));
	else
		sub = (char *)malloc((l - start + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = start;
	new = sub;
	while (i < (start + len) && *(s + i))
		*new++ = *(s + i++);
	*new = '\0';
	return (sub);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen (s1);
	p = (char *)malloc(sizeof (char) * (l + 1));
	if (p == NULL)
		return (0);
	while (i < l)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin (char const *s1, char const *s2)
{
    size_t	i;
    size_t	j;
    size_t	sum_sizes;
    char	*new_s;

    if (!s1 || !s2)
        return (NULL);
    sum_sizes = ft_strlen(s1) + ft_strlen(s2) + 1;
    new_s = malloc(sum_sizes);
    i = 0;
    j = 0;
	if (new_s == NULL)
        return (NULL);
	while (s1[i] != '\0')
	{
        new_s[i] = s1[i];
        i++;
		}
		while (s2[j] != '\0')
		{
        new_s[i + j] = s2[j];
        j++;
		}
		new_s[i + j] = '\0';
	return (new_s);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if ((unsigned char)c == *(s + i))
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((unsigned char)c == *(s + i))
	{
		return ((char *)s + i);
	}
	return (0);
}
