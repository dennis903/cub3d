#include "../cub3d.h"

void				img_reset_2d()
{
	int				i;
	int				j;

	i = 0;
	while (i < g_md.height)
	{
		j = 0;
		while (j < g_md.width)
		{
			g_game.img_2d.data[i * g_md.width + j] = 0x000000;
			j++;
		}
		i++;
	}
}

void				img_reset_3d()
{
	int				i;
	int				j;

	i = 0;
	while (i < g_md.height)
	{
		j = 0;
		while (j < g_md.width)
		{
			g_game.img_3d.data[i * g_md.width + j] = 0x000000;
			j++;
		}
		i++;
	}
}

int					has_wall_at(double x, double y)
{
	int				check_wall_x;
	int				check_wall_y;

	if (x >= g_idx_width * g_tile_size || x < 0 || y >= g_idx_height * g_tile_size || y < 0)
		return (1);
	check_wall_x = floor(x / g_tile_size);
	check_wall_y = floor(y / g_tile_size);
	if (g_game.map[check_wall_y][check_wall_x] == '1')
		return (1);
	else
		return (0);
}

int					calc_idx(double x, double y)
{
	return ((int)y * g_md.width + (int)x);
}