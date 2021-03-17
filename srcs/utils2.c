/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:46:56 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 18:20:44 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					calc_idx(int x, int y)
{
	return (y * (g_tile_size * g_idx_width) + x);
}

int					count_sprite(void)
{
	int				i;
	int				j;
	int				count;

	i = 0;
	count = 0;
	while (i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (g_game.map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

double				fix_angle(double angle)
{
	if (g_keys.a_key)
		angle = angle + get_degree(90);
	else if (g_keys.d_key)
		angle = angle + get_degree(270);
	else if (g_keys.s_key)
		angle = angle + get_degree(180);
	return (angle);
}

double				check_angle_by_dir(double angle)
{
	if (g_keys.a_key)
		angle = angle - get_degree(90);
	else if (g_keys.d_key)
		angle = angle + get_degree(90);
	else if (g_keys.s_key)
		angle = angle + get_degree(180);
	return (angle);
}
