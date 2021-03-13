/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:17 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/12 21:48:18 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void					draw_ceiling()
{
	int					i;
	int					j;

	i = 0;
	while (i < md.height / 2)
	{
		j = 0;
		while (j < md.width)
		{
			game.img_3d.data[i * md.width + j] = fill_color(md.f);
			j++;
		}
		i++;
	}
}

void					draw_floor()
{
	int					i;
	int					j;

	i = md.height / 2;
	while (i < md.height)
	{
		j = 0;
		while (j < md.width)
		{
			game.img_3d.data[i * md.width + j] = fill_color(md.c);
			j++;
		}
		i++;
	}
}

void					draw_3d_wall(double x, int wall_strip_height, t_ray ray)
{
	int					i;
	int					start_point;
	int					end_point;
	int					screen_y;
	t_point				get_texture;

	start_point = (md.height / 2) - (wall_strip_height / 2);
	if (start_point < 0)
		start_point = 0;
	end_point = (md.height / 2) + (wall_strip_height / 2);
	if (end_point >= md.height)
		end_point = md.height - 1;
	i = start_point;
	check_direction(ray);
	get_texture.x = get_texture_x(ray);
	while (i < end_point)
	{
		screen_y = i + (wall_strip_height / 2) - (md.height / 2);
		get_texture.y = get_texture_y(screen_y,  wall_strip_height);
		game.img_3d.data[i * md.width + (int)x] = get_texture_color(get_texture.x, get_texture.y);
		i++;
	}
}

void					draw_wall()
{
	int					i;
	double				correct_ray_dist;
	int					wall_height;

	i = 0;
	while (i < g_num_rays)
	{
		correct_ray_dist = cos(player.rot_angle - g_rays[i].ray_angle) * (g_rays[i].distance);
		wall_height = (g_tile_size / correct_ray_dist) * g_dist_from_player;
		draw_3d_wall(i, wall_height, g_rays[i]);
		i++;
	}
}