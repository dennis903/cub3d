/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:35 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/12 21:47:35 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void					draw_2d_sprite(int y, int x, int color)
{
	int					i;
	int					j;

	i = 0;

	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			game.img_2d.data[(y + i) * (g_tile_size * g_idx_width) + x + j] = color;
			j++;
		}
		i++;
	}
}

void					sprite_pos_set()
{
	int					i;
	int					j;
	int					count;

	count = 0;
	i = 0;
	while(i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (game.map[i][j] == '2')
			{
				g_sprites[count].pos.x = (j * g_tile_size + (g_tile_size / 2));
				g_sprites[count].pos.y = (i * g_tile_size + (g_tile_size / 2));
				count++;
			}
			j++;
		}
		i++;
	}
}

void					draw_sprite_height(int sprite_height, int sprite_width, int x, t_sprite_utils sp_utils)
{
	int					start_y;
	int					end_y;
	int					texture_x;
	int					texture_y;

	start_y = (md.height / 2) - (sprite_height / 2);
	end_y = (md.height / 2) + (sprite_height / 2);
	sp_utils.start_y = start_y;
	sp_utils.end_y = end_y;
	if (start_y < 0)
		start_y = 0;
	if (end_y > md.height)
		end_y = md.height;
	texture_x = get_sp_tex_x(x - sp_utils.start_x, sprite_width);
	while (start_y < end_y)
	{
		texture_y = get_sp_tex_y(start_y - sp_utils.start_y, sprite_height);
		if (get_sp_texture(texture_x, texture_y) != 0)
			game.img_3d.data[start_y * md.width + x] = get_sp_texture(texture_x, texture_y);
		start_y++;
	}
}

void					draw_3d_sprite(int sprite_height, t_sprite sprite)
{
	int					start_x;
	int					end_x;
	t_sprite_utils		sp_utils;
	int					sprite_width;
	double				sprite_angle;

	sprite_angle = atan2(sprite.pos.y - player.y, sprite.pos.x - player.x) - player.rot_angle;
	sprite_width = sprite_height;
	start_x = (md.width / 2) + (tan(sprite_angle) * g_dist_from_player) - (sprite_width / 2) + 30;
	sp_utils.start_x = start_x;
	end_x = start_x + sprite_width;
	sp_utils.end_x = end_x;
	if (start_x < 0)
		start_x = 0;
	if (end_x > md.width)
		end_x = md.width;
	while (start_x < end_x)
	{
		if (sprite.distance < g_rays[start_x].distance)
			draw_sprite_height(sprite_height, sprite_width, start_x, sp_utils);
		start_x++;
	}
}

void					sort_sprite(t_sprite *visible_sprite, int visible_sp_num)
{
	t_sprite			temp_sprite;
	int					i;
	int					j;

	i = 0;
	while (i < visible_sp_num - 1)
	{
		j = 0;
		while (j < visible_sp_num - 1 - i)
		{
			if (visible_sprite[j].distance < visible_sprite[j + 1].distance)
			{
				temp_sprite = visible_sprite[j];
				visible_sprite[j] = visible_sprite[j + 1];
				visible_sprite[j + 1] = temp_sprite;
			}
			j++;
		}
		i++;
	}
}