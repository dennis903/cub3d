/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:49:23 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/13 17:56:00 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			check_w(double angle)
{
	t_point		new_pos;

	new_pos.x = (g_player.x + cos(angle) * g_player.move_speed);
	new_pos.y = (g_player.y + sin(angle) * g_player.move_speed);
	if (!has_wall_at(new_pos.x + defence_seg_x(g_player.angle),
new_pos.y + defence_seg_y(g_player.angle)))
	{
		g_player.x = new_pos.x;
		g_player.y = new_pos.y;
	}
}

void			check_s(double angle)
{
	t_point		new_pos;

	angle += get_degree(180);
	new_pos.x = (g_player.x + cos(angle) * g_player.move_speed);
	new_pos.y = (g_player.y + sin(angle) * g_player.move_speed);
	if (!has_wall_at(new_pos.x + defence_seg_x(g_player.angle),
new_pos.y + defence_seg_y(g_player.angle)))
	{
		g_player.x = new_pos.x;
		g_player.y = new_pos.y;
	}
}

void			check_d(double angle)
{
	t_point		new_pos;

	angle += get_degree(90);
	new_pos.x = (g_player.x + cos(angle) * g_player.move_speed);
	new_pos.y = (g_player.y + sin(angle) * g_player.move_speed);
	if (!has_wall_at(new_pos.x + defence_seg_x(g_player.angle),
new_pos.y + defence_seg_y(g_player.angle)))
	{
		g_player.x = new_pos.x;
		g_player.y = new_pos.y;
	}
}

void			check_a(double angle)
{
	t_point		new_pos;

	angle += get_degree(270);
	new_pos.x = (g_player.x + cos(angle) * g_player.move_speed);
	new_pos.y = (g_player.y + sin(angle) * g_player.move_speed);
	if (!has_wall_at(new_pos.x + defence_seg_x(g_player.angle),
new_pos.y + defence_seg_y(g_player.angle)))
	{
		g_player.x = new_pos.x;
		g_player.y = new_pos.y;
	}
}
