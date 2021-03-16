/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:51 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 02:34:48 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				test_number(char *s1, char *s2)
{
	int			i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] < '0' || s1[i] > '9')
			return (ERROR);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (s2[i] < '0' || s2[i] > '9')
			return (ERROR);
		i++;
	}
	return (0);
}

int				save_r(char **splits)
{
	int			split_length;
	int			width;
	int			height;

	split_length = count_splits(splits);
	if (split_length != 3)
		return (ERROR);
	if (test_number(splits[1], splits[2]) == ERROR)
		return (ERROR);
	if (check_g_md() == ERROR)
		return (ERROR);
	width = ft_atoi(splits[1]);
	height = ft_atoi(splits[2]);
	if (width == 0 || height == 0)
		return (ERROR);
	width = width > 1920 ? 1920 : width;
	height = height > 1080 ? 1080 : height;
	width = width < 250 ? 250 : width;
	height = height < 250 ? 250 : height;
	g_md.width = width;
	g_md.height = height;
	return (0);
}

int				save_texture(char **splits)
{
	int			split_length;

	split_length = count_splits(splits);
	if (split_length != 2)
		return (ERROR);
	if (check_texture(splits[0]) == ERROR)
		return (ERROR);
	if (check_sprite(splits[0]) == ERROR)
		return (ERROR);
	if (ft_strcmp(splits[0], "NO") == 0)
		g_md.north = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "SO") == 0)
		g_md.south = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "EA") == 0)
		g_md.east = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "WE") == 0)
		g_md.west = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "S") == 0)
		g_md.sprite = ft_strdup(splits[1]);
	return (0);
}

int				save_color(char **splits)
{
	int			split_length;

	split_length = count_splits(splits);
	if (split_length != 2)
		return (ERROR);
	if (ft_strcmp(splits[0], "F") == 0)
		return (make_color(splits[1], &g_md.f));
	else if (ft_strcmp(splits[0], "C") == 0)
		return (make_color(splits[1], &g_md.c));
	return (0);
}
