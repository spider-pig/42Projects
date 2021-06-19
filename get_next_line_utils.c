/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleticia <cleticia@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:19:22 by cleticia          #+#    #+#             */
/*   Updated: 2021/06/17 19:40:00 by cleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


ssize_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (*(str + idx) != '\0')
		idx++;
	return (idx);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen (s1);
	p = (char *) malloc(sizeof (char) * (l + 1));
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
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

