/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:25:38 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/23 19:02:51 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define ERROR -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  32
# endif

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int			get_next_line(int fd, char **line);
char		*ft_strndup(const char *s1, int n);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
#endif
