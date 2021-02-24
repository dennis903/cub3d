#include "../cub3d.h"

void					draw_ceiling()
{
	int					i;
	int					j;

	i = 0;
	while (i < g_map_height / 2)
	{
		j = 0;
		while (j < g_map_width)
		{
			game.img.data[i * g_map_width + j] = fill_color(md.f);
			j++;
		}
		i++;
	}
}

void					draw_floor()
{
	int					i;
	int					j;

	i = g_map_height / 2;
	while (i < g_map_height)
	{
		j = 0;
		while (j < g_map_width)
		{
			game.img.data[i * g_map_width + j] = fill_color(md.c);
			j++;
		}
		i++;
	}
}