/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:44 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/12 21:48:45 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				up_test(char **map, int i, int j)
{
	while (i >= 0)
	{
		if (map[i][j] == '1')
			return (0);
		if (check_not_valid_map(map[i][j]) == ERROR)
			return (ERROR);
		i--;
	}
	return (ERROR);
}

int				left_test(char **map, int i, int j)
{
	while (j >= 0)
	{
		if (map[i][j] == '1')
			return (0);
		if (check_not_valid_map(map[i][j]) == ERROR)
			return (ERROR);
		j--;
	}
	return (ERROR);
}

int				right_test(char **map, int i, int j)
{
	while (j <= g_idx_width)
	{
		if (map[i][j] == '1')
			return (0);
		if (check_not_valid_map(map[i][j]) == ERROR)
			return (ERROR);
		j++;
	}
	return (ERROR);
}

int				down_test(char **map, int i, int j)
{
	while(i <= g_idx_height)
	{
		if (map[i][j] == '1')
			return (0);
		if (check_not_valid_map(map[i][j]) == ERROR)
			return (ERROR);
		i++;
	}
	return (ERROR);
}

int				map_valid_test(char **map, int i, int j)
{
	int			player_count;

	player_count = 0;
	if ((up_test(map, i, j)) == ERROR)
		return (ERROR);
	if ((down_test(map, i, j)) == ERROR)
		return (ERROR);
	if ((left_test(map, i, j)) == ERROR)
		return (ERROR);
	if ((right_test(map, i, j)) == ERROR)
		return (ERROR);
	return (0);
}