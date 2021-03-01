/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 22:00:15 by hyeolee           #+#    #+#             */
/*   Updated: 2020/10/23 19:03:17 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_line(char **line, char **str, char *temp)
{
	char		*tmp_ptr;

	if (temp)
	{
		*temp = '\0';
		*line = ft_strdup(*str);
		tmp_ptr = ft_strdup(temp + 1);
		free(*str);
		*str = tmp_ptr;
		return (1);
	}
	if (*str)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	else
		*str = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *str[OPEN_MAX];
	char		*buffer;
	char		*temp;
	int			rd_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (ERROR);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	while (!(temp = ft_strchr(str[fd], '\n')) &&
	(rd_size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rd_size] = '\0';
		temp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = temp;
	}
	free(buffer);
	if (rd_size < 0)
		return (ERROR);
	return (get_line(line, &str[fd], temp));
}
