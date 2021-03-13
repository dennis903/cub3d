/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:22 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 17:56:12 by ihyeongjin       ###   ########.fr       */
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
	g_player.x = g_tile_size * width;
	g_player.y = g_tile_size * height;
	g_player.radius = 3;
	g_player.turn_dir = 0;
	g_player.walk_dir = 0;
	g_player.move_speed = 2.0;
	g_player.rotation_speed = 2 * (PI / 180);
}

int					defence_seg_x(double angle)
{
	t_ray			ray;

	angle = check_angle_by_dir(angle);
	ray = rot_angle_ray_cast(angle);
	check_direction(ray);
	if (g_dir.check_ea)
		return (2);
	else if (g_dir.check_we)
		return (-2);
	return (0);
}

int					defence_seg_y(double angle)
{
	t_ray			ray;

	angle = check_angle_by_dir(angle);
	ray = rot_angle_ray_cast(angle);
	check_direction(ray);
	if (g_dir.check_no)
		return (-2);
	else if (g_dir.check_so)
		return (2);
	return (0);
}

void				update(void)
{
	g_player.angle += g_player.turn_dir * g_player.rotation_speed;
	g_player.angle = normalize_angle(g_player.angle);
	move_player();
}
