/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:46 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 16:55:32 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					get_sp_tex_x(int current_x, int sprite_width)
{
	double			texture_x;

	texture_x = current_x * (g_dir.sp_w / (double)sprite_width);
	return ((int)texture_x);
}

int					get_sp_tex_y(int current_y, int sprite_height)
{
	double			texture_y;

	texture_y = current_y * (g_dir.sp_h / (double)sprite_height);
	return ((int)texture_y);
}

int					get_sp_texture(int x, int y)
{
	int				color;

	color = g_dir.sp_data[y * g_dir.sp_w + x];
	return (color);
}
