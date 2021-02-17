#include "../cub3d.h"

void			draw_line(double x1, double y1, double x2, double y2, int color)
{
	double		delta_x;
	double		delta_y;
	int			steps;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	steps = (fabs(delta_x) > fabs(delta_y)) ? fabs(delta_x) : fabs(delta_y);
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game.img.data[to_coord(x1, y1)] = color;
		x1 += delta_x;
		y1 += delta_y;
	}
}

void			draw_player()
{
	int			i;
	int			j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			game.img.data[to_coord(player.x + j, player.y + i)] = 0xFF0000;
			j++;
		}
		i++;
	}
}

void			draw_lines()
{
	int			i;
	int			j;

	i = 0;
	while (i < g_idx_height)
	{
		draw_line(0, i * g_tile_size, md.width, i * g_tile_size, 0xAAAAAA);
		i++;
	}
	draw_line(0, g_idx_height * g_tile_size - 1, md.width, g_idx_height * g_tile_size - 1, 0xAAAAAA);
	j = 0;
	while (j < g_idx_width)
	{
		draw_line(j * g_tile_size, 0, j * g_tile_size, md.height, 0xAAAAAA);
		j++;
	}
	draw_line(g_idx_width * g_tile_size - 1, 0, g_idx_width * g_tile_size - 1, md.width, 0xAAAAAA);
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
			game.img.data[(row + i) * md.width + (col + j)] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void			draw_rectangles()
{
	int			i;
	int			j;

	i = 0;
	while (i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (game.map[i][j] == 1)
				draw_rectangle(j, i);
			j++;
		}
		i++;
	}
}