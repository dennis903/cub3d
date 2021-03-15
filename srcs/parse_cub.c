/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:36 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/16 02:32:37 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				data_setting(char *line)
{
	char		**splits;

	splits = ft_split(line, ' ');
	if (!(*splits))
	{
		return (0);
	}
	else
	{
		if ((set_base_data(splits)) == ERROR)
		{
			return (-1);
		}
	}
	free_arrs(splits);
	return (1);
}

int				data_check(void)
{
	if (g_md.width != 0 && g_md.height != 0 &&
	g_md.north != 0 && g_md.south != 0 &&
	g_md.east != 0 && g_md.west != 0 &&
	g_md.sprite != 0 && g_md.f != 0 && g_md.c != 0)
		return (SUCCESS);
	return (0);
}

int				parse_data(int fd)
{
	char		*line;

	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (data_setting(line) == ERROR)
		{
			free(line);
			return (ERROR);
		}
		if ((data_check()) == SUCCESS)
		{
			free(line);
			return (0);
		}
		else
			free(line);
	}
	free(line);
	return (0);
}

int				move_to_map(int fd, t_list **map_list)
{
	int			check;
	char		*line;

	check = 0;
	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0')
		{
			check = 1;
			break ;
		}
		free(line);
	}
	if (check == 0)
	{
		free(line);
		return (ERROR);
	}
	ft_lstadd_back(map_list, ft_lstnew((void *)line));
	parse_map(fd, map_list);
	return (0);
}

int				parse_cub(int fd)
{
	int			w_tile;
	int			h_tile;
	t_list		*map_list;

	map_list = 0;
	if (!(g_game.mlx = mlx_init()))
		return (ERROR);
	if (parse_data(fd) == ERROR)
		return (ERROR);
	if (move_to_map(fd, &map_list) == ERROR)
		return (ERROR);
	if ((g_game.map = fill_map_data(map_list)) == 0)
		return (ERROR);
	w_tile = g_md.width / g_idx_width;
	h_tile = g_md.height / g_idx_height;
	if (w_tile >= h_tile)
		g_tile_size = h_tile;
	else
		g_tile_size = w_tile;
	return (0);
}
