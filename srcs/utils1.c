/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:04 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/12 21:47:05 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double				get_degree(int degree)
{
	return (degree * (PI / 180));
}

int					has_wall_at(double x, double y)
{
	int				check_wall_x;
	int				check_wall_y;	

	if (x >= md.width || x < 0 ||y >= md.height || y < 0)
		return (1);
	check_wall_x = (int)(x / g_tile_size);
	check_wall_y = (int)(y / g_tile_size);
	if (game.map[check_wall_y][check_wall_x] == '1')
		return (1);
	else
		return (0);
}

int					to_coord(double x, double y)
{
	return ((int)floor(y) * g_tile_size * g_idx_width + (int)floor(x));
}

double				get_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void				move_player()
{
	if (g_keys.a_key)
		check_a(player.rot_angle);
	if (g_keys.w_key)
		check_w(player.rot_angle);
	if (g_keys.d_key)
		check_d(player.rot_angle);
	if (g_keys.s_key)
		check_s(player.rot_angle);
}
