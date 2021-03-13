/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:47:19 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 19:12:38 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				sprite_2d()
{
	int				i;
	double			pbs_angle;

	i = 0;
	while (i < g_sprite_num)
	{
		g_sprites[i].visible = 0;
		pbs_angle = g_player.angle - atan2(g_sprites[i].pos.y - g_player.y,
		g_sprites[i].pos.x - g_player.x);
		if (pbs_angle > PI)
			pbs_angle -= PI * 2;
		if (pbs_angle < -PI)
			pbs_angle += PI * 2;
		pbs_angle = fabs(pbs_angle);
		if (pbs_angle < (g_fov_angle / 2) + 0.2)
		{
			g_sprites[i].visible = 1;
			g_sprites[i].angle = pbs_angle;
			g_sprites[i].distance = get_distance(g_player.x, g_player.y,
			g_sprites[i].pos.x, g_sprites[i].pos.y);
		}
		i++;
	}
}

void				sprite_3d()
{
	t_sprite		visible_sprite[g_sprite_num];
	int				visible_sp_num;
	int				i;
	
	i = 0;
	visible_sp_num = 0;
	while (i < g_sprite_num)
	{
		if (g_sprites[i].visible)
		{
			visible_sprite[visible_sp_num] = g_sprites[i];
			visible_sp_num++;
		}
		i++;
	}
	calc_sprite(visible_sprite, visible_sp_num);
}

void				calc_sprite(t_sprite *visible_sprite, int visible_sp_num)
{
	t_sprite		sprite;
	int				sprite_height;
	double			correct_dist;
	int				i;

	i = 0;
	sort_sprite(visible_sprite, visible_sp_num);
	while (i < visible_sp_num)
	{
		sprite = visible_sprite[i];
		correct_dist = sprite.distance * cos(sprite.angle);
		sprite_height = (g_tile_size / correct_dist) * g_proj_dist;
		draw_3d_sprite(sprite_height, sprite);
		i++;
	}
}
