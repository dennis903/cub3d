/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeolee <hyeolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:49:03 by ihyeongjin        #+#    #+#             */
/*   Updated: 2021/03/15 18:56:56 by hyeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			draw_line(double x1, double y1, double x2, double y2)
{
	double		delta_x;
	double		delta_y;
	int			steps;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	steps = (fabs(delta_x) > fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);
	delta_x /= steps;
	delta_y /= steps;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		g_game.img_2d.data[to_coord(x1, y1)] = 0xFFFFFF;
		x1 += delta_x;
		y1 += delta_y;
	}
}

void			draw_player(void)
{
	int			i;
	int			j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			g_game.img_2d.data[to_coord(g_player.x + j,
			g_player.y + i)] = 0xFF0000;
			j++;
		}
		i++;
	}
}

void			draw_rectangle(int row, int col)
{
	int			i;
	int			j;

	row *= g_tile_size;
	col *= g_tile_size;
	i = 0;
	while (i < g_tile_size)
	{
		j = 0;
		while (j < g_tile_size)
		{
			g_game.img_2d.data[(row + i) * g_tile_size * g_idx_width
			+ (col + j)] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void			draw_rectangles(void)
{
	int			i;
	int			j;

	i = 0;
	while (i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (g_game.map[i][j] == '1')
				draw_rectangle(i, j);
			j++;
		}
		i++;
	}
}
