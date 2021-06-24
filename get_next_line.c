/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleticia <cleticia@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:20:52 by cleticia          #+#    #+#             */
/*   Updated: 2021/06/20 22:17:24 by cleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_read(int bread, char **buffer, char **saved, char **line)
{
	if (bread > 0)
		return (1);
	free(*buffer);
	if (*saved)
	{
		free(*saved);
		*saved = NULL;
	}
	if (bread == -1)
	{
		free(*line);
		*line = NULL;
	}
	return (bread);
}

static int	get_one_line(int bread, char **line, char **buffer, char **saved)
{
	char	*found_break;
	char	*line_temp;
	char	*linecpy;
	int		is_finished;

	line_temp = ft_calloc(bread + 1, sizeof(char));
	linecpy = *line;
	found_break = ft_memccpy(line_temp, *buffer, '\n', bread);
	is_finished = 0;
	if (found_break)
	{
		if (*saved)
			free(*saved);
		*saved = ft_strdup(found_break);
		is_finished = 1;
	}
	*line = ft_strjoin(linecpy, line_temp);
	free(*buffer);
	free(line_temp);
	free(linecpy);
	return (is_finished);
}

static int	get_saved(char **line, char **saved)
{
	int		is_finished;
	char	*saved_temp;

	if (!line)
		return (-1);
	*line = ft_calloc(1, sizeof(char));
	if (!*line)
		return (-1);
	saved_temp = NULL;
	while (*saved && **saved != '\0')
	{
		is_finished = get_one_line(ft_strlen(*saved), line, saved, &saved_temp);
		*saved = saved_temp;
		if (is_finished == 1)
			return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved;
	char		*buffer;
	int			bread;
	int			is_finished;

	is_finished = get_saved(line, &saved);
	if (is_finished == -1 || is_finished == 1)
		return (is_finished);
	while (is_finished == 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		bread = read(fd, buffer, BUFFER_SIZE);
		is_finished = get_read(bread, &buffer, &saved, line);
		if (is_finished <= 0)
			return (is_finished);
		buffer[bread] = '\0';
		is_finished = get_one_line(bread, line, &buffer, &saved);
	}
	return (1);
}
