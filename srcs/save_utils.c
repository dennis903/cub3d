/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:51 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/12 21:47:52 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				save_r(char **splits)
{
	int			split_length;
	// int			max_width;
	// int			max_height;
	int			width;
	int			height;

	split_length = count_splits(splits);
	// mlx_get_screen_size(game.mlx, &max_width, &max_height);
	if (split_length != 3)
		return (ERROR);
	width = ft_atoi(splits[1]);
	height = ft_atoi(splits[2]);
	if (width == 0 || height == 0)
		return (ERROR);
	if (width < 250)
		width = 250;
	if (height < 250)
		height = 250;
	// if (width > max_width)
	// 	width = max_width;
	// if (height > max_height)
	// 	height = max_height;
	md.width = width;
	md.height = height;
	return (0);
}

int				save_texture(char **splits)
{
	int			split_length;

	split_length = count_splits(splits);
	if (split_length != 2)
		return (ERROR);
	if (ft_strcmp(splits[0], "NO") == 0)
		md.north = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "SO") == 0)
		md.south = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "EA") == 0)
		md.east = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "WE") == 0)
		md.west = ft_strdup(splits[1]);
	else if (ft_strcmp(splits[0], "S") == 0)
		md.sprite = ft_strdup(splits[1]);
	return (0);
}

int				save_color(char **splits)
{
	int			split_length;

	split_length = count_splits(splits);
	if (split_length != 2)
		return (ERROR);
	if (ft_strcmp(splits[0], "F") == 0)
		return (make_color(splits[1], &md.f));
	else if (ft_strcmp(splits[0], "C") == 0)
		return (make_color(splits[1], &md.c));
	return (0);
}