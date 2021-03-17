/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:51 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 17:13:08 by hyeolee          ###   ########.fr       */
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
	int			max_width;
	int			max_height;

	split_length = count_splits(splits);
	mlx_get_screen_size(g_game.mlx, &max_width, &max_height);
	if (split_length != 3)
		return (ERROR);
	if (test_number(splits[1], splits[2]) == ERROR)
		return (ERROR);
	if (check_g_md() == ERROR)
		return (ERROR);
	g_md.width = ft_atoi(splits[1]);
	g_md.height = ft_atoi(splits[2]);
	if (g_md.width == 0 || g_md.height == 0)
		return (ERROR);
	g_md.width = g_md.width > max_width ? max_width : g_md.width;
	g_md.height = g_md.height > max_height ? max_height : g_md.height;
	g_md.width = g_md.width < 400 ? 400 : g_md.width;
	g_md.height = g_md.height < 400 ? 400 : g_md.height;
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
	if (check_color(splits[0], splits[1]) == ERROR)
		return (ERROR);
	if (ft_strcmp(splits[0], "F") == 0)
		return (make_color(splits[1], &g_md.f));
	else if (ft_strcmp(splits[0], "C") == 0)
		return (make_color(splits[1], &g_md.c));
	return (0);
}
