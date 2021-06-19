/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleticia <cleticia@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:20:52 by cleticia          #+#    #+#             */
/*   Updated: 2021/06/18 21:17:49 by cleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER_SIZE 50


#include "get_next_line.h"


static	int	find_nl(int fd, char **buf, char **line)
{
	char		*new_line;
	char		*tmp;

	while ((new_line = ft_strchr(buf[fd], '\n')))
	{
		tmp = buf[fd];
		*new_line = '\0';
		*line = ft_strsub(buf[fd], 0, new_line - buf[fd]);
		buf[fd] = ft_strdup(new_line + 1);
		free(tmp);
		return (1);
	}
	while (*buf[fd])
	{
		*line = ft_strnew(ft_strlen(buf[fd]));
		ft_strcpy(*line, buf[fd]);
		buf[fd] = ft_memalloc(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}


static	int	ft_read(int fd, char **line)
{
	char		*buf;
	char		*tmp;
	int			i;

	buf = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!line[fd])
		{
			line[fd] = ft_strnew(ft_strlen(buf));
			ft_strcpy(line[fd], buf);
		}
		else
		{
			tmp = line[fd];
			line[fd] = ft_strjoin(line[fd], buf);
			free(tmp);
		}
		ft_memset(buf, 0, BUFF_SIZE);
	}
	free(buf);
	return (i);
}


int			get_next_line(const int fd, char **line)
{
	static	char	*buf[FDS];

	if (!line || fd < 0 || BUFF_SIZE < 0 || (ft_read(fd, &buf[fd]) < 0) ||
fd > FDS)
		return (-1);
	if (find_nl(fd, &buf[fd], line) == 1)
		return (1);
	return (0);
}




/*

/*void	ft_strcpy(char *dst, const char *src, size_t dstsize);

int		index_chr(const char *s, char c)//indice para marcar o contra barra n do lido
{
	int     index;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	if (s[index] != c)
		return (-1);
	return (index);
}

int get_next_line(int fd, char **line)
{
    int size; //retorno de read
    char *buff; //armazena o que read leu de fd
    static char *prev_lines = NULL; // vai concatenando o buffer que já foi lido
    char *aux; //para concatenar a prev com o buff o resultado é armazenado aqui
    //o resultado da aux é recebido na prev_lines
    int index;
    
    buff = (char *)malloc((BUFFER_SIZE + 1)* sizeof(char));
    size = read(fd, buff, BUFFER_SIZE);
    while (size != 0)
    {
        buff[size] = '\0';
        if (prev_lines == NULL)
            prev_lines = ft_strdup(buff);
        else
        {
            aux = ft_strjoin(prev_lines, buff);
            free(prev_lines);
            prev_lines = aux;
        }
        index = index_chr(prev_lines, '\n');
        if (index != -1)
            break;
        size = read(fd, buff, BUFFER_SIZE);   
    }
    free(buff);
    return (output(prev_lines, line, size)); 
}
*/
/*
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
*/