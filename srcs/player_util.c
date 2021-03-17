/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:22 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/17 18:46:28 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				set_angle(char direction)
{
	if (direction == 'N')
		g_player.angle = (PI / 180) * 270;
	else if (direction == 'E')
		g_player.angle = PI / 180;
	else if (direction == 'W')
		g_player.angle = PI;
	else if (direction == 'S')
		g_player.angle = (PI / 180) * 90;
}

void				player_init(int height, int width)
{
	g_player.x = (g_tile_size * width) + (g_tile_size / 2);
	g_player.y = (g_tile_size * height) + (g_tile_size / 2);
	g_player.radius = 3;
	g_player.turn_dir = 0;
	g_player.walk_dir = 0;
	g_player.move_speed = 2.0;
	g_player.rotation_speed = 2 * (PI / 180);
}

void				update(void)
{
	g_player.angle += g_player.turn_dir * g_player.rotation_speed;
	g_player.angle = normalize_angle(g_player.angle);
	move_player();
}

int					check_wall_hit(double new_pos_x, double new_pos_y)
{
	if (has_wall_at(new_pos_x + 3, new_pos_y + 3))
		return (1);
	if (has_wall_at(new_pos_x - 3, new_pos_y - 3))
		return (1);
	if (has_wall_at(new_pos_x + 3, new_pos_y - 3))
		return (1);
	if (has_wall_at(new_pos_x - 3, new_pos_y + 3))
		return (1);
	return (0);
}
