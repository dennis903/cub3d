#include "../cub3d.h"

void					draw_2d_sprite(int y, int x, int color)
{
	int					i;
	int					j;

	i = 0;

	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			game.img_2d.data[(y + i) * (g_tile_size * g_idx_width) + x + j] = color;
			j++;
		}
		i++;
	}
}

void					sprite_pos_set()
{
	int					i;
	int					j;
	int					count;

	count = 0;
	i = 0;
	while(i < g_idx_height)
	{
		j = 0;
		while (j < g_idx_width)
		{
			if (game.map[i][j] == '2')
			{
				g_sprites[count].pos.x = j * g_tile_size;
				g_sprites[count].pos.y = i * g_tile_size;
				count++;
			}
			j++;
		}
		i++;
	}
}