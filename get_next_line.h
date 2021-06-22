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

# include <stdlib.h>
# include <unistd.h>

# define R_LINE 1
# define R_EOF 0
# define R_ERROR -1

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
void	ft_strcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		findchr(const char *s, char c);
char	*strjoin_free(char *s1, char *s2);
int		strcpy_line_bl(char **line, char *str, int i, char *buff);
int		get_read(int fd, char **line, char *buff, char **str);

#endif
