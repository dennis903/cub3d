/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:48 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 14:39:32 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				copy_map_data(char **map, t_list *map_list)
{
	int				length;
	t_list			*temp;
	int				i;
	int				j;

	i = 0;
	while (map_list)
	{
		length = ft_strlen((char *)map_list->content);
		temp = map_list->next;
		j = -1;
		while (++j < length)
			map[i][j] = ((char *)map_list->content)[j];
		while (j < g_idx_width)
		{
			map[i][j] = '\0';
			j++;
		}
		i++;
		map_list = temp;
	}
}

int					map_valid_check(char **map)
{
	int				i;
	int				j;
	int				player_count;

	player_count = 0;
	i = 0;
	while (i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (map[i][j] == '0' || map[i][j] == '2' || map[i][j] == 'N' ||
			map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S')
			{
				if ((map_valid_test(map, i, j)) == -1)
					return (ERROR);
			}
			player_test(map[i][j], &player_count);
			j++;
		}
		i++;
	}
	if (player_count == 0 || player_count > 1)
		return (ERROR);
	return (0);
}

int					check_not_valid_map(char index)
{
	if (index != '1' && index != 'N' && index != 'E' && index != 'W' &&
	index != 'S' && index != '0' && index != '2')
		return (ERROR);
	return (0);
}

void				player_test(char index, int *player_count)
{
	if (index == 'N' || index == 'W' || index == 'E' || index == 'S')
		(*player_count)++;
}
