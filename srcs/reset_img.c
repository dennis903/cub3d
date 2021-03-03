#include "../cub3d.h"

void				image_reset_2d()
{
	int				i;
	int				j;

	i = 0;
	while (i < g_tile_size * g_idx_height)
	{
		j = 0;
		while (j < g_tile_size * g_idx_width)
		{
			game.img_2d.data[i * g_tile_size * g_idx_width + j] = 0x000000;
			j++;
		}
		i++;
	}
}

void				image_reset_3d()
{
	int				i;
	int				j;

	i = 0;
	while (i < md.height)
	{
		j = 0;
		while (j < md.width)
		{
			game.img_3d.data[i * md.width + j] = 0x000000;
			j++;
		}
		i++;
	}
}