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

static int	check_errors(int fd, char **line, t_gnl *string)
{
	ft_memset(string, 0, sizeof(*string));
	if ((fd < 0) || (fd > RLIMIT_NOFILE) || (BUFFER_SIZE < 1) || !(line))
		return (1);
	return (0);
}

static int	add_to_line(t_gnl *string, char **line, char **excess, int new_line)
{
	if (new_line)
		*string->break_line_ptr = '\0';
	string->read[string->read_return] = '\0';
	string->temp = ft_strjoin(*line, string->read);
	if (string->temp == NULL)
		return (ERROR);
	free(*line);
	*line = string->temp;
	if (new_line)
	{
		string->temp = ft_strdup(string->break_line_ptr + 1);
		if (string->temp == NULL)
			return (ERROR);
		free(*excess);
		*excess = string->temp;
	}
	return (READ_LINE);
}

static int	add_excess(char **line, t_gnl *string, char **excess, int new_line)
{
	if (new_line)
		*string->break_line_ptr = '\0';
	string->temp = ft_strjoin(*line, *excess);
	if (string->temp == NULL)
		return (ERROR);
	free(*line);
	*line = string->temp;
	if (new_line)
	{
		string->temp = ft_strdup(string->break_line_ptr + 1);
		if (string->temp == NULL)
			return (ERROR);
	}
	free(*excess);
	if (new_line)
		*excess = string->temp;
	else
		*excess = NULL;
	return (READ_LINE);
}

int			get_next_line(int fd, char **line)
{
	static char		*excess;
	t_gnl			string;

	if ((check_errors(fd, line, &string)) || (*line = ft_strdup("")) == NULL)
		return (-1);
	if (excess != NULL)
	{
		if ((string.break_line_ptr = ft_strchr(excess, '\n')))
			return (add_excess(line, &string, &excess, NEW_LINE));
		if ((add_excess(line, &string, &excess, NO_NEW_LINE)) == ERROR)
			return (ERROR);
	}
	while (((string.read_return = read(fd, string.read, BUFFER_SIZE)) > 0)
			&& !(string.break_line_ptr = ft_strchr(string.read, '\n')))
		if (add_to_line(&string, line, &excess, NO_NEW_LINE) == ERROR)
			return (ERROR);
	if (string.read_return < 1)
	{
		free(excess);
		return (string.read_return);
	}
	return (add_to_line(&string, line, &excess, NEW_LINE));
}
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
