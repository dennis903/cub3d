/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:09 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 17:11:27 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				is_dir_up(int left, t_ray ray)
{
	if (left)
	{
		if (ray.side == 0)
			g_dir.check_no = 1;
		else
			g_dir.check_we = 1;
	}
	else
	{
		if (ray.side == 1)
			g_dir.check_ea = 1;
		else
			g_dir.check_no = 1;
	}
}

void				is_dir_down(int left, t_ray ray)
{
	if (left)
	{
		if (ray.side == 0)
			g_dir.check_so = 1;
		else
			g_dir.check_we = 1;
	}
	else
	{
		if (ray.side == 1)
			g_dir.check_ea = 1;
		else
			g_dir.check_so = 1;
	}
}

double				get_texture_x(t_ray ray)
{
	double			texture_x;
	double			temp_x;

	if (g_dir.check_no || g_dir.check_so)
	{
		if (g_dir.check_no)
			temp_x = fmod(ray.hit_point.x, g_tile_size) *
			((double)g_dir.no_w / g_tile_size);
		else
			temp_x = fmod(ray.hit_point.x, g_tile_size) *
			((double)g_dir.so_w / g_tile_size);
	}
	else
	{
		if (g_dir.check_we)
			temp_x = fmod(ray.hit_point.y, g_tile_size) *
			((double)g_dir.we_w / g_tile_size);
		else
			temp_x = fmod(ray.hit_point.y, g_tile_size) *
			((double)g_dir.ea_w / g_tile_size);
	}
	texture_x = temp_x;
	return (texture_x);
}

double				get_texture_y(int screen_y, int wall_height)
{
	int				texture_y;

	texture_y = 0;
	if (g_dir.check_no == 1 || g_dir.check_so == 1)
	{
		if (g_dir.check_no)
			texture_y = screen_y * ((double)g_dir.no_h / wall_height);
		else if (g_dir.check_so)
			texture_y = screen_y * ((double)g_dir.so_h / wall_height);
	}
	else if (g_dir.check_ea == 1 || g_dir.check_we == 1)
	{
		if (g_dir.check_ea)
			texture_y = screen_y * ((double)g_dir.ea_h / wall_height);
		else if (g_dir.check_we)
			texture_y = screen_y * ((double)g_dir.we_h / wall_height);
	}
	return (texture_y);
}

int					get_texture_color(double x, double y)
{
	int				color;

	if (g_dir.check_no)
		color = g_dir.no_data[(int)y * g_dir.no_w + (int)x];
	else if (g_dir.check_so)
		color = g_dir.so_data[(int)y * g_dir.so_w + (int)x];
	else if (g_dir.check_we)
		color = g_dir.we_data[(int)y * g_dir.we_w + (int)x];
	else
		color = g_dir.ea_data[(int)y * g_dir.ea_w + (int)x];
	return (color);
}
