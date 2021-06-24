/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleticia <cleticia@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:20:39 by cleticia          #+#    #+#             */
/*   Updated: 2021/06/20 22:17:27 by cleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# define BUFFER_SIZE	32

char	*ft_strdup(char *src);

char	*ft_strjoin(char const *s1, char const *s2);

void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlen(char const *str);

void	*ft_memccpy(void *dest, void *src, int c, size_t n);

int		get_next_line(int fd, char **line);

#endif
