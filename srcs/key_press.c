/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihyeongjin <ihyeongjin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:48:59 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/12 21:49:00 by ihyeongjin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				init_keys()
{
	g_keys.w_key = 0;
	g_keys.a_key = 0;
	g_keys.d_key = 0;
	g_keys.s_key = 0;
	g_keys.left_key = 0;
	g_keys.right_key = 0;
	g_keys.tab_key = 0;
}

int					key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		g_keys.w_key = 1;
	if (keycode == KEY_S)
		g_keys.s_key = 1;
	if (keycode == KEY_A)
		g_keys.a_key = 1;
	if (keycode == KEY_D)
		g_keys.d_key = 1;
	if (keycode == KEY_LEFT)
	{
		g_keys.left_key = 1;
		player.turn_dir = -1;
	}
	if (keycode == KEY_RIGHT)
	{
		g_keys.right_key = 1;
		player.turn_dir = 1;
	}
	if (keycode == KEY_TAB)
		g_keys.tab_key = 1;
	return (0);
}

int					key_release(int keycode)
{
	if (keycode == KEY_W)
	{
		player.walk_dir = 0;
		g_keys.w_key = 0;
	}
	if (keycode == KEY_A)
	{
		player.walk_dir = 0;
		g_keys.a_key = 0;
	}
	if (keycode == KEY_S)
	{
		player.walk_dir = 0;
		g_keys.s_key = 0;
	}
	if (keycode == KEY_D)
	{
		player.walk_dir = 0;
		g_keys.d_key = 0;
	}
	if (keycode == KEY_LEFT)
	{
		player.turn_dir = 0;
		g_keys.left_key = 0;
	}
	if (keycode == KEY_RIGHT)
	{
		player.turn_dir = 0;
		g_keys.right_key = 0;
	}
	if (keycode == KEY_TAB)
		g_keys.tab_key = 0;
	return (0);
}

int					key_exit()
{
	exit(0);
}