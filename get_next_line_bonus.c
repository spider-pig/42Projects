/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleticia <cleticia@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:20:52 by cleticia          #+#    #+#             */
/*   Updated: 2021/06/20 18:15:47 by cleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*setter(void *b, int c, size_t len)
{
	unsigned char	*test;
	size_t			t;

	t = 0;
	test = (unsigned char *)b;
	while (t < len)
	{
		test[t] = (unsigned char)c;
		t++;
	}
	return (b);
}

void *zelloc(size_t size)
{
	char *ptr;
	size_t i;

	if (!(ptr = (char*)malloc(size)))
		return (NULL);
	i = -1;
	while (++i < size)
		*(ptr + i) = 0;
	return (ptr);
}

static	int	find_nl(int fd, char **buf, char **line)
{
	char		*new_line;
	char		*tmp;

	new_line = ft_strchr(buf[fd], '\n');
	while (new_line)
	{
		tmp = buf[fd];
		*new_line = '\0';
		*line = ft_substr(buf[fd], 0, new_line - buf[fd]);
		buf[fd] = ft_strdup(new_line + 1);
		free(tmp);
		return (1);
	}
	while (*buf[fd])
	{
		*line = (char *)malloc(sizeof(char) * (ft_strlen(buf[fd] + 1)));
		*line =  ft_strdup(buf[fd]);
		buf[fd] = zelloc(BUFFER_SIZE + 1);
		return (1);
	}
	return (0);
}

static	int	ft_read(int fd, char **line)
{
	char		*buf;
	char		*tmp;
	int			i;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (!line[fd])
		{
			line[fd] = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
			line[fd] = ft_strdup(&buf[fd]);
		}
		else
		{
			tmp = line[fd];
			line[fd] = ft_strjoin(line[fd], buf);
			free(tmp);
		}
		setter(buf, 0, BUFFER_SIZE);		
	}
	free(buf);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static	char	*buf[FLDS];

	if (!line || fd < 0 || BUFFER_SIZE < 0
	||(ft_read(fd, &buf[fd]) < 0) || fd > FLDS)
		return (-1);
	if (find_nl(fd, &buf[fd], line) == 1)
		return (1);
	return (0);
}
