/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:09 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 19:27:28 by ihyeongjin       ###   ########.fr       */
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

int					get_texture_x(t_ray ray)
{
	int				texture_x;
	double			temp_x;

	if (g_dir.check_no || g_dir.check_so)
	{
		if (g_dir.check_no)
			temp_x = fmod(ray.hit_point.x, g_tile_size) *
			(g_dir.no_w / g_tile_size);
		else
			temp_x = fmod(ray.hit_point.x, g_tile_size) *
			(g_dir.so_w / g_tile_size);
	}
	else
	{
		if (g_dir.check_we)
			temp_x = fmod(ray.hit_point.y, g_tile_size) *
			(g_dir.we_w / g_tile_size);
		else
			temp_x = fmod(ray.hit_point.y, g_tile_size) *
			(g_dir.ea_w / g_tile_size);
	}
	texture_x = temp_x;
	return (texture_x);
}

int					get_texture_y(int screen_y, int wall_height)
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

int					get_texture_color(int x, int y)
{
	int				color;

	if (g_dir.check_no)
		color = g_dir.no_data[y * g_dir.no_w + x];
	else if (g_dir.check_so)
		color = g_dir.so_data[y * g_dir.so_w + x];
	else if (g_dir.check_we)
		color = g_dir.we_data[y * g_dir.we_w + x];
	else
		color = g_dir.ea_data[y * g_dir.ea_w + x];
	return (color);
}
