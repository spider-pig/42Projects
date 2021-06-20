/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleticia <cleticia@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:20:39 by cleticia          #+#    #+#             */
/*   Updated: 2021/06/20 18:17:55 by cleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS       1
# define END_OF_FILE   0
# define ERROR         -1
# define CONTINUE_READ -2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

int        get_next_line(int fd, char **line);
char   *ft_strdup(const char *s);
char   *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *s);
char   *ft_strchr(const char *s, int c);
char   *ft_strjoin(char const *s1, char const *s2);

#endif
