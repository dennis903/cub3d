/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:17 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 17:00:34 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void					draw_ceiling(void)
{
	int					i;
	int					j;

	i = 0;
	while (i < g_md.height / 2)
	{
		j = 0;
		while (j < g_md.width)
		{
			g_game.img_3d.data[i * g_md.width + j] = fill_color(g_md.f);
			j++;
		}
		i++;
	}
}

void					draw_floor(void)
{
	int					i;
	int					j;

	i = g_md.height / 2;
	while (i < g_md.height)
	{
		j = 0;
		while (j < g_md.width)
		{
			g_game.img_3d.data[i * g_md.width + j] = fill_color(g_md.c);
			j++;
		}
		i++;
	}
}

void					draw_3d_wall(double x, int wall_strip_height, t_ray ray)
{
	int					color;
	int					start_point;
	int					end_point;
	int					screen_y;
	t_point				get_texture;

	start_point = (g_md.height / 2) - (wall_strip_height / 2);
	if (start_point < 0)
		start_point = 0;
	end_point = (g_md.height / 2) + (wall_strip_height / 2);
	if (end_point >= g_md.height)
		end_point = g_md.height;
	check_direction(ray);
	get_texture.x = get_texture_x(ray);
	while (start_point < end_point)
	{
		screen_y = start_point + (wall_strip_height / 2) - (g_md.height / 2);
		get_texture.y = get_texture_y(screen_y, wall_strip_height);
		color = get_texture_color(get_texture.x, get_texture.y);
		g_game.img_3d.data[start_point * g_md.width + (int)x] = color;
		start_point++;
	}
}

void					draw_wall(void)
{
	int					i;
	double				correct_ray_dist;
	int					wall_height;

	i = 0;
	while (i < g_num_rays)
	{
		correct_ray_dist = cos(g_player.angle -
		g_rays[i].ray_angle) * (g_rays[i].distance);
		wall_height = (g_tile_size / correct_ray_dist) * g_proj_dist;
		draw_3d_wall(i, wall_height, g_rays[i]);
		i++;
	}
}
