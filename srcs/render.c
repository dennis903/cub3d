/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:00 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 13:48:48 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					change_to_degree(double angle)
{
	angle = normalize_angle(angle);
	return ((int)angle / (PI / 180));
}

void				draw_2d_ray()
{
	int				col_id;
	int				i;
	double			ray_angle;

	col_id = 0;
	i = 0;
	while (i < g_num_rays)
	{
		ray_angle = g_player.rot_angle + atan((i - g_num_rays / 2) / g_dist_from_player);
		g_rays[i].ray_angle = normalize_angle(ray_angle);
		ray_cast(col_id, ray_angle);
		col_id++;
		i++;
	}
}


void				raycast_2d()
{
	draw_rectangles();
	draw_lines();
	draw_player();
	draw_2d_ray();
}

void				raycast_3d()
{
	draw_ceiling();
	draw_floor();
	draw_wall();
}

void				render()
{
	image_reset_2d();
	image_reset_3d();
	raycast_2d();
	sprite_2d();
	raycast_3d();
	sprite_3d();
}